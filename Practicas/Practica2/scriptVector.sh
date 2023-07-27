#!/bin/bash

rm VECTOR.txt

touch VECTOR.txt

g++ genera-duplicados.cpp -o genera

./genera $1 >> VECTOR.txt