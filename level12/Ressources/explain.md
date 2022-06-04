Dans ce challenge, on a un fichier `perl`, qui est un serveur :

```bash
#!/usr/bin/env perl
# localhost:4646
use CGI qw{param};
print "Content-type: text/html\n\n";
```

Dans ce niveau la vulnérabilité est dans la fonction `t`:

```bash
sub t {
  $nn = $_[1];
  $xx = $_[0];
  $xx =~ tr/a-z/A-Z/; 
  $xx =~ s/\s.*//;
  @output = `egrep "^$xx" /tmp/xd 2>&1`;
  foreach $line (@output) {
      ($f, $s) = split(/:/, $line);
      if($s =~ $nn) {
          return 1;
      }
  }
  return 0;
}
```

On peut voir que des backquotes sont utilisées pour exécuter la commande `egrep` et que la variable `$xx` est utilisée comme argument de la commande `egrep`,
si la variable `$xx` contient aussi des backquotes, sont contenu sera exécuté

Donc si on envoie :

```bash
`/*/exploit`
```

Plu

S'il y a un exécutable dans `/tmp/` qui se nomme `EXPLOIT`, il sera exécuté.

Il reste plus qu'à écrire un script bash `/tmp/EXPLOIT` qui appel `getflag >> /tmp/level12/flag`
