mkdir -p /tmp/sshpass
cd /tmp/sshpass/
wget http://archive.ubuntu.com/ubuntu/pool/universe/s/sshpass/sshpass_1.06-1_amd64.deb
dpkg -x ./sshpass_1.06-1_amd64.deb ./
cd -
mv /tmp/sshpass/usr/bin/sshpass ./