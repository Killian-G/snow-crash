Pour ce niveau, il n'y a pas de fichier à analyser, du coup il nous reste plus que l'exécutable `getflag`

```bash
> which getflag
/bin/getflag
```

Au debut de la fonction `main` on voit que la fonction `ptrace` est utilisé pour contrer une tentative de debug

```bash
> disassemble main
...
0x08048962 <+28>:	mov    DWORD PTR [esp+0x10],0x0
0x0804896a <+36>:	mov    DWORD PTR [esp+0xc],0x0
0x08048972 <+44>:	mov    DWORD PTR [esp+0x8],0x1
0x0804897a <+52>:	mov    DWORD PTR [esp+0x4],0x0
0x08048982 <+60>:	mov    DWORD PTR [esp],0x0
0x08048989 <+67>:	call   0x8048540 <ptrace@plt>
0x0804898e <+72>:	test   eax,eax
0x08048990 <+74>:	jns    0x80489a8 <main+98>
...
```

Mais cette protection est facile à contourner, il suffit de modifier la valeur de retour de `ptrace` par `1`

La fonction `getuid` est utilisé pour obtenir le UID du processus en cours

```bash
> disassemble main
...
0x08048afd <+439>:	call   0x80484b0 <getuid@plt>
0x08048b02 <+444>:	mov    DWORD PTR [esp+0x18],eax
0x08048b06 <+448>:	mov    eax,DWORD PTR [esp+0x18]
0x08048b0a <+452>:	cmp    eax,0xbbe
0x08048b0f <+457>:	je     0x8048ccb <main+901>
0x08048b15 <+463>:	cmp    eax,0xbbe
0x08048b1a <+468>:	ja     0x8048b68 <main+546>
0x08048b1c <+470>:	cmp    eax,0xbba
0x08048b21 <+475>:	je     0x8048c3b <main+757>
0x08048b27 <+481>:	cmp    eax,0xbba
0x08048b2c <+486>:	ja     0x8048b4d <main+519>
0x08048b2e <+488>:	cmp    eax,0xbb8
0x08048b33 <+493>:	je     0x8048bf3 <main+685>
0x08048b39 <+499>:	cmp    eax,0xbb8
0x08048b3e <+504>:	ja     0x8048c17 <main+721>
0x08048b44 <+510>:	test   eax,eax
0x08048b46 <+512>:	je     0x8048bc6 <main+640>
0x08048b48 <+514>:	jmp    0x8048e06 <main+1216>
0x08048b4d <+519>:	cmp    eax,0xbbc
0x08048b52 <+524>:	je     0x8048c83 <main+829>
0x08048b58 <+530>:	cmp    eax,0xbbc
0x08048b5d <+535>:	ja     0x8048ca7 <main+865>
0x08048b63 <+541>:	jmp    0x8048c5f <main+793>
0x08048b68 <+546>:	cmp    eax,0xbc2
0x08048b6d <+551>:	je     0x8048d5b <main+1045>
0x08048b73 <+557>:	cmp    eax,0xbc2
0x08048b78 <+562>:	ja     0x8048b95 <main+591>
0x08048b7a <+564>:	cmp    eax,0xbc0
0x08048b7f <+569>:	je     0x8048d13 <main+973>
0x08048b85 <+575>:	cmp    eax,0xbc0
0x08048b8a <+580>:	ja     0x8048d37 <main+1009>
0x08048b90 <+586>:	jmp    0x8048cef <main+937>
0x08048b95 <+591>:	cmp    eax,0xbc4
0x08048b9a <+596>:	je     0x8048da3 <main+1117>
0x08048ba0 <+602>:	cmp    eax,0xbc4
0x08048ba5 <+607>:	jb     0x8048d7f <main+1081>
0x08048bab <+613>:	cmp    eax,0xbc5
0x08048bb0 <+618>:	je     0x8048dc4 <main+1150>
0x08048bb6 <+624>:	cmp    eax,0xbc6
0x08048bbb <+629>:	je     0x8048de5 <main+1183>
0x08048bc1 <+635>:	jmp    0x8048e06 <main+1216>
...
```

On voit qu'il y a un saut vers une instruction en fonction du retour de la fonction `getuid`.

```bash
> id flag14
uid=3014(flag14) gid=3014(flag14) groups=3014(flag14),1001(flag)
```

On a plus qu'à changer la valeur du registre `eax` pour `0xbc6` a l'adresse `0x08048b0a`
