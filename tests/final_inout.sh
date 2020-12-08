#!/bin/bash

if test -f scenario1_native_final.txt
then
	rm scenario1_native_final.txt
fi

cat units/directions.txt | ./a.out scenarios/scenario1.json >> native_output1_final.txt

diff native_output1_final.txt scenarios/output1_final.txt
