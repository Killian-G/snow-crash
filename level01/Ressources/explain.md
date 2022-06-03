Pour ce niveau on peut voir dans le fichier /etc/passwd:

```bash
> cat /etc/passwd
...
flag01:42hDRfypTqqnw:3001:3001::/home/flag/flag01:/bin/bash
...
```

`42hDRfypTqqnw` est le hash du mot de passe de l'utilisateur flag01

Apres ca, on peut utiliser le logiciel `John` qui permet de trouver
le mot de passe a partir du hash

```bash
> john hash_file
...
Loaded 1 password hash (descrypt, traditional crypt(3) [DES 128/128 SSE2-16])
john  | abcdefg          (?)
...
```
