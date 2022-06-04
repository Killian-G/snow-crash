
```bash
> disassemble main

...
0x08048975 <+423>:	mov    eax,DWORD PTR [esp+0x1c]
0x08048979 <+427>:	add    eax,0x4
0x0804897c <+430>:	mov    edx,DWORD PTR [eax]
0x0804897e <+432>:	mov    eax,DWORD PTR [esp+0x20]
0x08048982 <+436>:	add    eax,edx
0x08048984 <+438>:	movzx  eax,BYTE PTR [eax]
0x08048987 <+441>:	movsx  eax,al
0x0804898a <+444>:	add    eax,DWORD PTR [esp+0x20]
0x0804898e <+448>:	mov    DWORD PTR [esp],eax
0x08048991 <+451>:	call   0x80484c0 <putchar@plt>
0x08048996 <+456>:	add    DWORD PTR [esp+0x20],0x1
0x0804899b <+461>:	mov    ebx,DWORD PTR [esp+0x20]
0x0804899f <+465>:	mov    eax,DWORD PTR [esp+0x1c]
0x080489a3 <+469>:	add    eax,0x4
0x080489a6 <+472>:	mov    eax,DWORD PTR [eax]
0x080489a8 <+474>:	mov    DWORD PTR [esp+0x18],0xffffffff
0x080489b0 <+482>:	mov    edx,eax
0x080489b2 <+484>:	mov    eax,0x0
0x080489b7 <+489>:	mov    ecx,DWORD PTR [esp+0x18]
0x080489bb <+493>:	mov    edi,edx
0x080489bd <+495>:	repnz scas al,BYTE PTR es:[edi]
0x080489bf <+497>:	mov    eax,ecx
0x080489c1 <+499>:	not    eax
0x080489c3 <+501>:	sub    eax,0x1
0x080489c6 <+504>:	cmp    ebx,eax
0x080489c8 <+506>:	jb     0x8048975 <main+423>

...
```

L'algoritme de chiffrement ici est le valeur du caractères ASCII + sa position dans la chaine de caracteres

Pour retrouver le token original il nous sufit de faire la meme operation en retournant la valeur ASCII - sa position dans la chaine de caracteres

f3iji1ju5yuevaus41q1afiuq
