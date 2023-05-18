CMC 1.0.0

Setup
---------------------

To download CMC Core, visit [GitHub Releases](https://github.com/cpuminerscoin/CMC/releases/latest).

Running
---------------------
The following are some helpful notes on how to run CMC on your native platform.

### Unix

Unpack the files into a directory and run:

- `bin/cpuminerscoin-qt` (GUI) or
- `bin/cpuminerscoind` (headless)

Data Directory Location:
- Unix: ~/.cpuminerscoin

### Windows

Unpack the files into a directory, and then run cpuminerscoin-qt.exe.

Data Directory Locations

- Windows < Vista: C:\Documents and Settings\Username\Application Data\CMC
- Windows >= Vista: C:\Users\Username\AppData\Roaming\CMC

### OS X

Drag CMC-Core to your applications folder, and then run CMC-Core.

Data Directory Location:
- Mac: ~/Library/Application Support/CMC

### Need Help?

* See the documentation at the [Bitcoin Wiki](https://en.bitcoin.it/wiki/Main_Page)
for help and more information. CMC is very similar to bitcoin, so you can use their wiki.
* Ask for help on [#general](https://discord.gg/ycV7abbF7M) in the Official CMC Coin Discord Channel.

Building
---------------------
The following are developer notes on how to build CMC on your native platform. They are not complete guides, but include notes on the necessary libraries, compile flags, etc.

- [Dependencies](dependencies.md)
- [OS X Build Notes](build-osx.md)
- [Unix Build Notes](build-unix.md)
- [Windows Build Notes](build-windows.md)
- [OpenBSD Build Notes](build-openbsd.md)
- [Gitian Building Guide](gitian-building.md)

Development
---------------------
The CMC repo's [root README](/README.md) contains relevant information on the development process and automated testing.

- [Developer Notes](developer-notes.md)
- [Release Notes](release-notes.md)
- [Release Process](release-process.md)
- [Source Code Documentation (External Link)](none-yet)
- [Translation Process](translation_process.md)
- [Translation Strings Policy](translation_strings_policy.md)
- [Travis CI](travis-ci.md)
- [Unauthenticated REST Interface](REST-interface.md)
- [Shared Libraries](shared-libraries.md)
- [BIPS](bips.md)
- [Dnsseed Policy](dnsseed-policy.md)
- [Benchmarking](benchmarking.md)


### Miscellaneous
- [Assets Attribution](assets-attribution.md)
- [Files](files.md)
- [Fuzz-testing](fuzzing.md)
- [Reduce Traffic](reduce-traffic.md)
- [Tor Support](tor.md)
- [Init Scripts (systemd/upstart/openrc)](init.md)
- [ZMQ](zmq.md)

License
---------------------
Distributed under the [MIT software license](/COPYING).
This product includes software developed by the OpenSSL Project for use in the [OpenSSL Toolkit](https://www.openssl.org/). This product includes
cryptographic software written by Eric Young ([eay@cryptsoft.com](mailto:eay@cryptsoft.com)), and UPnP software written by Thomas Bernard.
