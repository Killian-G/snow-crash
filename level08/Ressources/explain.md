Dans ce challenge le programme attend en entrée un fichier à lire.

Si on essaie de lire le fichier `token` present dans le dossier cela ne fonctionne pas.

Pour trouver la raison, on va désassembler le programme avec gdb

    
```bash
> disassemble main
...
0x080485a6 <+82>:	mov    eax,DWORD PTR [esp+0x1c]      // Acces à argv
0x080485aa <+86>:	add    eax,0x4                       // Acces à argv[1]
0x080485ad <+89>:	mov    eax,DWORD PTR [eax]
0x080485af <+91>:	mov    DWORD PTR [esp+0x4],0x8048793 // "token"
0x080485b7 <+99>:	mov    DWORD PTR [esp],eax
0x080485ba <+102>:	call   0x8048400 <strstr@plt>
0x080485bf <+107>:	test   eax,eax                       
0x080485c1 <+109>:	je     0x80485e9 <main+149>          // Si eax == 0x0
0x080485c3 <+111>:	mov    eax,DWORD PTR [esp+0x1c]
0x080485c7 <+115>:	add    eax,0x4
0x080485ca <+118>:	mov    edx,DWORD PTR [eax]
0x080485cc <+120>:	mov    eax,0x8048799
0x080485d1 <+125>:	mov    DWORD PTR [esp+0x4],edx
0x080485d5 <+129>:	mov    DWORD PTR [esp],eax
0x080485d8 <+132>:	call   0x8048420 <printf@plt>
0x080485dd <+137>:	mov    DWORD PTR [esp],0x1
0x080485e4 <+144>:	call   0x8048460 <exit@plt>
...

> x/s 0x8048793
0x8048793:	 "token"
```

La fonction `strstr` est utilisée pour chercher si dans le premier argument du programme il y a le mot `token`,
si c'est le cas la fonction `exit`

Pour contourner cette restriction il suffit de créer un lien symbolique `/tmp/level08/file` vers le fichier `token`

```bash
> mkdir -p /tmp/level08
> ln -s /home/user/level08/token /tmp/level08/file
> ./level08 /tmp/level08/file
quif5eloekouj29ke0vouxean
```


