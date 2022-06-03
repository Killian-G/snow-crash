Pour ce challenge il faut utiliser GDB

```bash
> disassemble main
...
0x804856f <main+91>     movl   $0x8048680,(%esp)
0x8048576 <main+98>     call   0x8048400 <getenv@plt>
...
```

On voit que la fonction `getenv` est utilisé a l'adresse 0x8048576 et que l'argument est stocké dans l'espace mémoire à l'adresse 0x8048680.

```bash
> x/s 0x8048680
0x8048680:       "LOGNAME"
```

```bash
...
0x804857f <main+107>    movl   $0x8048688,0x4(%esp)
0x8048587 <main+115>    lea    0x14(%esp),%eax
0x804858b <main+119>    mov    %eax,(%esp)
0x804858e <main+122>    call   0x8048440 <asprintf@plt>
...
```

On voit que la fonction `asprintf` est utilisé a l'adresse `0x804858e` et que l'argument est stocké dans l'espace mémoire à l'adresse `0x8048688`.

```
> x/s 0x8048688
0x8048688:       "/bin/echo %s "
```

```bash
...
0x804859a <main+134>    call   0x8048410 <system@plt>
...
```

On voit que la fonction `system` est utilisé, elle prend en argument la chaine de caracteres `/bin/echo %s`.

```bash
> env | grep LOGNAME
LOGNAME=levle07
```

En exécutant le programme, on voit que le programme affiche `levle07`.

Si on change la variable LOGNAME à `Test`, le programme affiche `Test`.

Ce qui confirme que le programme lance bien la commande `echo` avec le bon argument.

Ce qui est une vulnérabilité, car si l'on change la variable LOGNAME pour `a && getflag`, le programme lance la commande `getflag`
