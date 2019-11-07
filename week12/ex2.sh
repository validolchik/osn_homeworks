#!/bin/bash

gcc ex2.c -o ex2.out

cat /proc/cpuinfo | ./ex2.out ex2.txt