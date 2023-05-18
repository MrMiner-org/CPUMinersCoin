#!/bin/bash -ev

mkdir -p ~/.cpuminerscoin
echo "rpcuser=username" >>~/.cpuminerscoin/cpuminerscoin.conf
echo "rpcpassword=`head -c 32 /dev/urandom | base64`" >>~/.cpuminerscoin/cpuminerscoin.conf

