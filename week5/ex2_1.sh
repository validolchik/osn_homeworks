#!/bin/bash
while true
do
let var=`tail -n 1 text.txt`+1
echo "$var">> text.txt
done

