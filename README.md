This is the reference code for [Worktips](https://worktips.info) cryptocurrency.

* Official homepage: [Worktips](http://worktips.info)
* Official repository: [Worktips GitHub](https://github.com/Vordas/worktips)
* Official Announcement thread: [Worktips BitcoinTalk](https://bitcointalk.org/index.php?topic=3086019.0)
* Official Discord: [Worktips Discord](https://discord.gg/UmZExyz)
* Official Facebook: [Worktips Facebook](https://www.facebook.com/worktipscoin)
* Official Twitter: [Worktips Twitter](https://twitter.com/wtipscoin)
* Official Telegram: [Worktips Telegram](https://t.me/worktips)
* Official Whitepaper: [Worktips Whitepaper](http://worktips.info/whitepaper_worktips.zip)


## Worktips Cryptocurrency

Worktips [WTIP] is a CryptoNight Lite Variant 1 POW algorithm based coin with a total supply of 184,467,440,735 coins. Fast transactions & privacy make this coin a perfect cryptocurrency for rewarding your workers, co-workers, colleagues and family for a job well done.

- Algorithm: CryptoNight Lite Variant 1
- Max. supply: 184,467,440,735.0
- CryptoNote name: worktips
- Decimal points: 8
- Block time: 120
- Ticker: WTIP
- Emission speed factor: 18
- P2P port: 17239
- RPC port: 18238

## How to compile

### Compile on Linux Ubuntu 16

**1. Install dependencies**

- run an update

``
sudo apt-get update
``

- get all dependencies

``
sudo apt-get install build-essential python-dev gcc g++ git cmake libboost-all-dev librocksdb-dev
``

**2. Get the coin**

``
git clone https://github.com/Vordas/worktips.git worktips
``

**3. CHMOD**

- navigate to:

``
cd worktips/external/rocksdb/build_tools
``

- execute the following commands:

``
chmod +x build_detect_platform
``

``
chmod +x version.sh
``

**4. Build executables**

- Navigate back to repo folder 

``
cd
``

``
cd worktips
``

- prepare the build

``
mkdir build && cd $_
``

``
cmake ..
``

- Export flags

``
export CXXFLAGS="-std=gnu++11"
``

- Make/Build

``
make
``

_Your executables will be located in `build/src` folder._


### Compile on Linux Ubuntu 14

**1. Install dependencies**

- run an update

``
sudo apt-get update
``

- get all dependencies

``
sudo apt-get install -y build-essential python-dev git cmake libboost1.55-all-dev libgflags-dev libsnappy-dev zlib1g-dev libbz2-dev libgflags-dev libgflags2 gcc-4.8 g++-4.8
``

**2. Install RocksDB database (long compilation)**

``
git clone https://github.com/facebook/rocksdb.git
``

``
cd rocksdb
``

``
make all
``

**3. Get the coin**

``
cd
``

``
git clone https://github.com/Vordas/worktips.git worktips
``

**4. CHMOD**

- navigate to:

``
cd worktips/external/rocksdb/build_tools
``

- execute the following commands:

``
chmod +x build_detect_platform
``

``
chmod +x version.sh
``

**5. Build executables (long compilation)**

- Navigate back to repo folder 

``
cd
``

``
cd worktips
``

- prepare the build

``
mkdir build && cd $_
``

``
cmake ..
``

- Export flags

``
export CXXFLAGS="-std=gnu++11"
``

- Make/Build

``
make
``

_Your executables will be located in `build/src` folder._
