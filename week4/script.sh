#!/bin/bash

gcc ex1.c -o ex1.out
for n in {1..10}
do
	./ex1.out
done
