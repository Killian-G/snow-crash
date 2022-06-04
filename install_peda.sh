echo "Installing peda..."
git -C ./peda/ pull || git clone https://github.com/longld/peda.git ./peda/
echo "Creating /tmp/peda directory..."
./sshpass -p "level00" ssh -p $SNOWCRASH_SSH_PORT level00@$SNOWCRASH_IP "mkdir -p /tmp/peda/ && chmod 777 /tmp/peda/"
echo "Copying peda to /tmp/peda..."
./sshpass -p "level00" scp -P $SNOWCRASH_SSH_PORT -r ./peda level00@$SNOWCRASH_IP:/tmp/peda/peda/
echo "Installing peda..."
./sshpass -p "level00" ssh -p $SNOWCRASH_SSH_PORT level00@$SNOWCRASH_IP "echo 'source ./peda/peda.py' >> /tmp/peda/.gdbinit"
echo "Done!"
