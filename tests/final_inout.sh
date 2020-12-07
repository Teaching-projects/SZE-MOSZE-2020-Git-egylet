#!/bin/bash

if test -f scenario1_native.txt
then
	rm scenario1_native.txt
fi

if test -f scenario2_native.txt
then
	rm scenario2_native.txt
fi

cat units/directions.txt | ./a.out scenarios/scenario1.json >> native_output1.txt
cat units/directions.txt | ./a.out scenarios/scenario2.json >> native_output2.txt

diff native_output1.txt scenarios/output1.txt
diff native_output2.txt scenarios/output2.txt
