#!/bin/bash

if test -f native_output.txt
then
	rm native_output.txt
fi

for i in ../units/*.json 
do
	for j in ../units/*.json
	do
		if [ $i != $j ]
		then
			./../a.out $i $j >> ../native_output.txt
		fi
	done
done
