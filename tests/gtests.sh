#!/bin/bash

cd tests
sudo apt install build-essential
sudo apt install libgtest-dev
sudo apt install cmake
cd /usr/src/gtest
sudo cmake CMakeLists.txt
sudo make
sudo ln -st /usr/lib/ /usr/src/gtest/libgtest.a
sudo ln -st /usr/lib/ /usr/src/gtest/libgtest_main.a
cd -
cmake CMakeLists.txt
make
./runTests