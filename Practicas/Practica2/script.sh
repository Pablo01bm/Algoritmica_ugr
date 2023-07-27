#!/bin/bash

touch Tiempos.txt

g++ listaderegistros.cpp -o lista 

./lista VECTOR.txt >> Tiempos.txt