#!/bin/bash

g++ -Wall -std=c++11 -fopenmp $1

echo "$2 $3 $4 $5" > entrada.in
> tempo.out

for (( i = 1; i <= $6; i++ )); do
	echo "Executando ${i}ª vez"
	echo "Execucao $i:" >> tempo.out
	(time ./a.out < entrada.in > saida.out) 2>> tempo.out
	echo "" >> tempo.out
done
