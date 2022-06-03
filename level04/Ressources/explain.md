Dans ce niveau, c'est un fichier en perl qui doit être exploité,
ce fichier est un setuid et setgid, c'est-à-dire que le code est exécuté en tant que
flag04 car c'est le propriétaire du fichier.
Ce code est exécuté quand la vm reçoit une requête sur le port 4747,
le query parameter `x` est envoyé à la fonction `x` :
```bash
...
x(param("x"));
...
```

La fonction x affiche une chaine de caractères utilisant des backquotes, en perl cela permet
d'exécuter des commandes shell, et cette chaine de caractères fait un echo du paramètre passé
à la fonction `x`, et ceci est une faille de sécurité, car si on fait cette requête :

```bash
curl http://localhost:4747?x=%26%26getflag
```

`%26` correspond au caractère `&`

Ce qui donne dans la chaine de caractère du code perl :

```bash
echo &&getflag 2>&1
```

le `print` en perl revoit des données au client dans ce cas le résultat de la command
et donc le flag.