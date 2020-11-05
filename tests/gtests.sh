#!/bin/bash

cd tests
sudo apt install build-essential
sudo apt install libgtest-dev
sudo apt install cmake

sudo apt install software-properties-common
sudo apt install gcc-7 g++-7 gcc-8 g++-8 gcc-9 g++-9
sudo update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-9 90 --slave /usr/bin/g++ g++ /usr/bin/g++-9 --slave /usr/bin/gcov gcov /usr/bin/gcov-9

cd /usr/src/gtest
sudo cmake .
sudo make

cd -
./runTests
