Bluebeasts [TBB] integration/staging tree
=====================================

https://thebluebeast.com/

What is the BlueBeasts [TBB] Blockchain?
----------------------------------------
*TODO: Update documentation regarding implemented tech as this section is out of date and much progress and upgrades have been made to mentioned sections...*

### Overview
The goal of this project is to be a record for all scientific discovery. A Library of "theoretical" knowledge if you will. So that students and future generations can simply look for a pdf or old textbook on the blockchain to assist them in their studies.

### Blockchain Technology
The BlueBeasts [TBB] Blockchain is an experimental smart contract platform protocol that enables 
instant payments to anyone, anywhere in the world in a private, secure manner. 
BlueBeasts [TBB] uses peer-to-peer blockchain technology developed by Satoshi Nakamoto to operate
with no central authority: managing transactions, execution of contracts, and 
issuing money are carried out collectively by the network. BlueBeasts [TBB] is the name of 
open source software which enables the use of this protocol.

### Custom Difficulty Retarget Algorithm “VRX”
VRX is designed from the ground up to integrate properly with the Velocity parameter enforcement system to ensure users no longer receive orphan blocks.

### Velocity Block Constraint System
Ensuring Insane stays as secure and robust as possible the CryptoCoderz team have implemented what's known as the Velocity block constraint system. This system acts as third and final check for both mined and peer-accepted blocks ensuring that all parameters are strictly enforced.

### Wish (bmw512) Proof-of-Work Algorithm
Wish or bmw512 (BlueMidnightWish 512) hashing algorithm is utilized for the Proof-of-Work function and also replaces much of the underlying codebase hashing functions as well that normally are SHA256. By doing so this codebase is able to be both exponentially lighter and more secure in comparison to reference implementations.

Specifications and General info
------------------
BlueBeasts uses 

	libsecp256k1,
	libgmp,
	Boost1.68, OR Boost1.58,  
	Openssl1.02r,
	Berkeley DB 6.2.32,
	QT5.13.0,
	to compile

General Specs

	Block Spacing: 4 Minutes
	Stake Minimum Age: 25 Confirmations (PoS-v3) | 30 Minutes (PoS-v2)
	Port: 47224
	RPC Port: 47444


BUILD LINUX
-----------
### Compiling BlueBeasts "SatoshiCore" daemon on Ubunutu 18.04 LTS Bionic
### Note: guide should be compatible with other Ubuntu versions from 14.04+

### Become poweruser
```
sudo -i
```
### CREATE SWAP FILE FOR DAEMON BUILD (if system has less than 2GB of RAM)
```
cd ~; sudo fallocate -l 3G /swapfile; ls -lh /swapfile; sudo chmod 600 /swapfile; ls -lh /swapfile; sudo mkswap /swapfile; sudo swapon /swapfile; sudo swapon --show; sudo cp /etc/fstab /etc/fstab.bak; echo '/swapfile none swap sw 0 0' | sudo tee -a /etc/fstab
```

### Dependencies install
```
cd ~; sudo apt-get install -y ntp git build-essential libssl-dev libdb-dev libdb++-dev libboost-all-dev libqrencode-dev libcurl4-openssl-dev curl libzip-dev; apt-get update -y; apt-get install -y git make automake build-essential libboost-all-dev; apt-get install -y yasm binutils libcurl4-openssl-dev openssl libssl-dev; sudo apt-get install -y libgmp-dev; sudo apt-get install -y libtool; cd ~;
```

### Dependencies build and link
```
cd ~; wget http://download.oracle.com/berkeley-db/db-6.2.32.NC.tar.gz; tar zxf db-6.2.32.NC.tar.gz; cd db-6.2.32.NC/build_unix; ../dist/configure --enable-cxx; make; sudo make install; sudo ln -s /usr/local/BerkeleyDB.6.2/lib/libdb-6.2.so /usr/lib/libdb-6.2.so; sudo ln -s /usr/local/BerkeleyDB.6.2/lib/libdb_cxx-6.2.so /usr/lib/libdb_cxx-6.2.so; export BDB_INCLUDE_PATH="/usr/local/BerkeleyDB.6.2/include"; export BDB_LIB_PATH="/usr/local/BerkeleyDB.6.2/lib" cd ~;
```

### GitHub pull (Source Download)
```
cd ~; git clone https://github.com/SaltineChips/Bluebeasts
```

### Build BlueBeasts daemon
```
cd ~; cd ~/BlueBeasts/src; chmod a+x obj; chmod a+x leveldb/build_detect_platform; chmod a+x secp256k1; chmod a+x leveldb; chmod a+x ~/BlueBeasts/src; chmod a+x ~/BlueBeasts; make -f ~/BlueBeasts/src/makefile/makefile.unix USE_UPNP=-; cd ~; cp -r ~/BlueBeasts/src/BlueBeasts-Coind /usr/local/bin/BlueBeasts-Coind;
```

### Create config file for daemon
```
cd ~; sudo ufw allow 47444/tcp; sudo ufw allow 51221/tcp; sudo ufw allow 22/tcp; sudo mkdir ~/.TBB; cat << "CONFIG" >> ~/.TBB/BlueBeasts.conf
listen=1
server=1
daemon=1
testnet=0
rpcuser=TBBrpcuser
rpcpassword=SomeCrazyVeryVerySecurePasswordHere
rpcport=47444
port=47224
rpcconnect=127.0.0.1
rpcallowip=127.0.0.1
addnode=207.148.27.92
addnode=45.76.62.163
addnode=188.166.109.87
addnode=68.183.146.51
addnode=80.211.2.103
addnode=84.113.44.78
addnode=93.100.163.137
addnode=95.66.140.59
addnode=66.176.232.29
addnode=45.32.10.58
addnode=37.53.34.2
addnode=37.232.178.182
addnode=24.11.24.196
addnode=202.229.49.182
addnode=201.75.101.163
addnode=176.114.7.216
addnode=139.228.206.17
addnode=13.67.38.233
addnode=13.67.106.233
addnode=122.196.137.109
addnode=114.219.150.58
addnode=104.238.62.81
addnode=103.84.143.25
CONFIG
chmod 700 ~/.TBB/BlueBeasts-Coin.conf; chmod 700 ~/.TBB; ls -la ~/.TBB
```

### Run BlueBeasts daemon
```
cd ~; BlueBeasts-Coind; BlueBeasts-Coind getinfo
```

### Troubleshooting
### for basic troubleshooting run the following commands when compiling:
### this is for minupnpc errors compiling

```
make clean -f makefile.unix USE_UPNP=-
make -f makefile.unix USE_UPNP=-
```
### Updating daemon in bin directory
```
cd ~; cp -r ~/BlueBeasts/src/BlueBeasts-Coind /usr/local/bin
```

License
-------

BlueBeasts [TBB] is released under the terms of the MIT license. See [COPYING](COPYING) for more
information or see https://opensource.org/licenses/MIT.

Development Process
-------------------

The `master` branch is regularly built and tested, but is not guaranteed to be
completely stable. [Tags](https://github.com/SaltineChips/BlueBeasts/tags) are created
regularly to indicate new official, stable release versions of BlueBeasts [TBB].

The contribution workflow is described in [CONTRIBUTING.md](CONTRIBUTING.md).

The developer [mailing list](https://lists.linuxfoundation.org/mailman/listinfo/bitcoin-dev)
should be used to discuss complicated or controversial changes before working
on a patch set.

Developer Discord can be found at: https://discord.gg/zAsyJzn

Testing
-------

Testing and code review is the bottleneck for development; we get more pull
requests than we can review and test on short notice. Please be patient and help out by testing
other people's pull requests, and remember this is a security-critical project where any mistake might cost people
lots of money.

### Automated Testing

Developers are strongly encouraged to write [unit tests](/doc/unit-tests.md) for new code, and to
submit new unit tests for old code. Unit tests can be compiled and run
(assuming they weren't disabled in configure) with: `make check`

There are also [regression and integration tests](/qa) of the RPC interface, written
in Python, that are run automatically on the build server.

### Manual Quality Assurance (QA) Testing

Changes should be tested by somebody other than the developer who wrote the
code. This is especially important for large or high-risk changes. It is useful
to add a test plan to the pull request description if testing the changes is
not straightforward.
