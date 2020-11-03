#!/bin/bash

if test -f native_output1.txt
then
	rm native_output1.txt
fi

if test -f native_output2.txt
then
	rm native_output2.txt
fi

./a.out scenarios/scenario1.json >> native_output1.txt
./a.out scenarios/scenario2.json >> native_output2.txt
