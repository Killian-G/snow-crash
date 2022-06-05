Dans un premier temps, on doit copier le fichier, pour l'analyser hors de la VM

```bash
> scp -P 3042 level02@localhost:./level02.pcap ./
```

Ensuite on peut afficher le contenu des packets pour voir si on peut deja
trouver des infos
```bash
> tcpflow -C -r level02.pcap
...
..wwwbugs login: 
l
.l
e
.e
v
.v
e
.e
l
.l
X
.X

.
.
Password: 
f
t
_
w
a
n
d
r
.
.
.
N
D
R
e
l
.
L
0
L

.

.
.
Login incorrect
...
```

`-C` print packet content

`-r` read from file

On voit que ce sont des packets de connexion,
il se connecte avec `levelX` et le mot de passe `ft_wandr   NDRel L0L`

Mais l'authentification échoue donc il y a des fautes dans le mot de passe,
on peut deja essayer d'enlever les espaces ce qui donne `ft_wandrNDRelL0L`
ce qui ne fonctionne pas pour se connecter à l'utilisateur `flag02`, on sait
que le créateur de ce sujet est `wandre`, ce qui resemble au mot de passe
qu'on a, on voit qu'il y a `ndrNDR` c'est surement qu'il a corrigé ce qui a écrit
donc on peut essayer `ft_waNDReL0L` 

Et ça fonctionne on peut se connecter à l'utilisateur `flag02`
