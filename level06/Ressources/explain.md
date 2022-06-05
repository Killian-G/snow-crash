Ce challenge contient un fichier PHP.

```bash
> cat level06.php
#!/usr/bin/php
<?php
function y($m) { $m = preg_replace("/\./", " x ", $m); $m = preg_replace("/@/", " y", $m); return $m; }
function x($y, $z) { $a = file_get_contents($y); $a = preg_replace("/(\[x (.*)\])/e", "y(\"\\2\")", $a); $a = preg_replace("/\[/", "(", $a); $a = preg_replace("/\]/", ")", $a); return $a; }
$r = x($argv[1], $argv[2]); print $r;
?>
```

La fonction `preg_replace` utilise une expression régulière pour remplacer une partie de la chaîne de caractères,
sauf que le modifier `e` est utilisé, ce qui a pour cause d'exécuter le code php present en entrée de cette fonction.

L'entrée de la fonction est le contenu present dans le fichier passé en paramètre de la fonction `x`

La fonction `x` est appelée avec comme premier paramètre `$argv[1]` donc le contenu du fichier donné en entée du programme
est évalué par la fonction `x` 

Il suffit d'écrire `[x ${``getflag``}]` dans un fichier et de le passer en argument du programme pour obtenir le flag
