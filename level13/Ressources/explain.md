Pour ce challenge, on voit qu'il y a un appel à la fonction `getuid` et que le retour est comparé a la valeur `0x1092 (4242)`

```bash
> disassemble main
...
0x08048595 <+9>:	call   0x8048380 <getuid@plt>
0x0804859a <+14>:	cmp    eax,0x1092
0x0804859f <+19>:	je     0x80485cb <main+63>
0x080485cb <+63>:	mov    DWORD PTR [esp],0x80486ef
0x080485d2 <+70>:	call   0x8048474 <ft_des>
0x080485d7 <+75>:	mov    edx,0x8048709
0x080485dc <+80>:	mov    DWORD PTR [esp+0x4],eax
0x080485e0 <+84>:	mov    DWORD PTR [esp],edx
0x080485e3 <+87>:	call   0x8048360 <printf@plt>
...

> x/s 0x80486ef
0x80486ef:	 "boe]!ai0FB@.:|L6l@A?>qJ}I"

> x/s 0x8048709
0x8048709:	 "your token is %s\n"
```

Pour afficher le token il nous suffit de modifier le retour de la fonction `getuid` pour qu'elle retourne `0x1092`

```bash
> b *0x0804859a
> run
> set $eax = 0x1092
> c
...
your token is 2A31L79asukciNyi8uppkEuSx
```
