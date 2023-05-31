#! /usr/bin/bash
gcc -fopenmp parallel.c -o parallel.exe
gcc -fopenmp serial.c -o serial.exe
