To run

#Make sure tor is started
sudo systemctl start tor.service

#start cpuminerscoin daemon with tor as proxy
ONIONHOSTNAME=$(sudo cat /var/lib/tor/cmc-service/hostname)
./cpuminerscoind -daemon -proxy=127.0.0.1:9050 -bind=127.0.0.1 -externalip=${ONIONHOSTNAME}
