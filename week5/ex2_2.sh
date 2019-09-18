#!/bin/bash
while true
do
	tempfile=$(mktemp ./lock.XXXX)
	lockfile=./lockfile
	if ln $tempfile $lockfile ; then
		let var=`tail -n 1 text.txt`+1
		echo "$var">> text.txt
		rm $lockfile
	else 
	    echo did not succeed
	fi
	rm $tempfile
done

