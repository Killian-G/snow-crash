Pour ce niveau si on lance l'exectuable, on obtient le message suivant:

```bash
Exploit me
```

On peut lancer la commande `strings` sur l'exécutable pour voir toutes les chaines de caractères contenues dans l'exécutable :

```bash
strings ./level03 | grep "Exploit me"
/usr/bin/env echo Exploit me
```

Pour compprendre quelle fonction est utilisé dans l'executable, on peut lancer la commande `nm` sur l'exécutable :
    
```bash
nm ./level03
...
system@@GLIBC_2.0
...
```

Ce qui correspond a la fonction `system()` qui permet d'exécuter des commandes dans un shell.

On peut déduire que la fonction `system()` est utilisé dans l'executable pour afficher le message `Exploit me`.

```bash
ls -l ./level03
-rwsr-sr-x 1 flag03 level03 8627 Mar  5  2016 level03
```

le `s` dans les droits signifie que quand l'executable est exécuté il sera exécuter en tant `flag03` qui est le propriétaire de `level03`.

On peut donc essayer d'exploiter la commande `echo` exécutée dans `./level03` pour exécuter une autre commande en tant que `flag03`.

Pour faire cela on modifie la variable d'environnement `PATH` pour qu'elle pointe vers un dossier avec un exécutable `echo` qui sera exécuter en tant que `flag03` et qui exécutera