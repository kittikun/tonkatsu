# tonkatsu

A game using [dominion rules](dominionrules.org) for I don't know yet :)

Server using ASIO C++14
Client using Unity 4.6.2

**Requires [dominionrules](https://github.com/kittikun/dominionrules)**

Tested on the following platforms:

Win8.1, VS2013
Ubuntu 14.04, GCC 4.9.2

##Build

Files required to build are located under the *build/* folder

You will need:
- C++14
- Boost
- SQLite

###Windows

When building for windows, please define the following environment variables:

BOOST_ROOT
DOMINION_ROOT 

eg: 
```
    BOOST_ROOT=C:\boost_1_57_0 
    DOMINION_ROOT=C:\dominionrules
```

###Linux and BSD

Builds requires CMake to be installed

Define $DOMINIONLIB poiting to your [dominionrules](https://github.com/kittikun/dominionrules) folder

eg: 
```
DOMINIONLIB=/home/user/dominionrules
```
