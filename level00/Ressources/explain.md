Dans la vidéo de Snow-Crash il nous montre un readme pour le level00 qui dit qu'il faut trouver
un fichier qui a les droits de l'utilisateur ou du groupe flag00, du coup pour trouver ce fichier
j'ai utilisé la commande:


```bash
> find / -user flag00 -group flag00 2> /dev/null | grep -v 'proc'
/usr/sbin/john
/rofs/usr/sbin/john
```

`find`: Une commande permetant de chercher des fichiers dans un répèrtoire de manière récursive

`/`: Le dossier où l'on commence la recherche, ici le dossier racine

`-user flag00`: Option permetant de recherche uniquement les fichiers appartenant a l'utilisateur 'flag00'

`-group flag00`: Option permetant de recherche uniquement les fichiers appartenant au groupe 'flag00'

`2> /dev/null`: Redirige la sortie d'erreur vers /dev/null pour ne pas les affichers

`| grep -v 'proc'`: Enlève les ligne avec le mot proc, car ces fichiers correspondes a des processus et ce n'est pas ce qu'il nous intéresse

```bash
> cat /usr/sbin/john
cdiiddwpgswtgt
```

J'ai essayé de me connecter avec ce mot de passe a l'utilisateur flag00 avec: 

```bash
> su flag00
```

Ce qui n'a pas fonctionné, j'en ai donc déduis que ce mot de passe etait chiffré, j'au utilisé le site dcode.fr pour déchiffrer le mot de passe
qui etait chiffré avec un chiffrement César, ce qui me donne une fois déchifré:

```bash
nottoohardhere
```

Avec ce mot de passe on peut se connecter a l'utilisateur flag00
