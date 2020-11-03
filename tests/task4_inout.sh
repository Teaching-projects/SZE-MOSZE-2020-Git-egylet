#!/bin/bash

if test -f scenario1_native.txt
then
	rm scenario1_native.txt
fi

if test -f scenario2_native.txt
then
	rm scenario2_native.txt
fi

for i in scenarios/*.json
do
	./a.out $i >> ${i%.json}_native.txt
done

#~ ./a.out scenarios/scenario1.json >> native_output1.txt
#~ ./a.out scenarios/scenario2.json >> native_output2.txt
