BlueBeasts-Coin [TBB] integration/staging tree
=====================================

http://www.bluebeasts-coincoin.com

What is the BlueBeasts-Coin [TBB] Blockchain?
---------------------------

The BlueBeasts-Coin [TBB] Blockchain is an experimental smart contract platform protocol that enables 
instant payments to anyone, anywhere in the world in a private, secure manner. 
BlueBeasts-Coin [TBB] uses peer-to-peer blockchain technology developed by BlueBeastsCoin to operate
with no central authority: managing transactions, execution of contracts, and 
issuing money are carried out collectively by the network. BlueBeasts-Coin [TBB] is the name of 
open source software which enables the use of this protocol.

Specifications and General info
------------------
BlueBeasts-Coin uses libsecp256k1,
			  libgmp,
			  Boost1.63,
			  OR Boost1.57,  
			  Openssl1.02k,
			  Berkeley DB 6.2.23,
			  QT5.8 to compile


Block Spacing: 5 Minutes
Stake Minimum Age: 15 Confirmations (PoS-v3) | 30 Minutes (PoS-v2)

Port: 51441
RPC Port: 10257


BUILD LINUX
-----------
1) git clone https://github.com/CryptoCoderz/TBB

2) cd TBB/src

3) sudo make -f makefile.unix            # Headless

(optional)

4) strip BlueBeasts-Coind

5) sudo cp BlueBeasts-Coind /usr/local/bin

License
-------

BlueBeasts-Coin [TBB] is released under the terms of the MIT license. See [COPYING](COPYING) for more
information or see https://opensource.org/licenses/MIT.

Development Process
-------------------

The `master` branch is regularly built and tested, but is not guaranteed to be
completely stable. [Tags](https://github.com/CryptoCoderz/TBB/tags) are created
regularly to indicate new official, stable release versions of BlueBeasts-Coin [TBB].

The contribution workflow is described in [CONTRIBUTING.md](CONTRIBUTING.md).

The developer [mailing list](https://lists.linuxfoundation.org/mailman/listinfo/bitcoin-dev)
should be used to discuss complicated or controversial changes before working
on a patch set.

Developer Slack can be found at http://bluebeasts-coincointeam.slack.com.

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
