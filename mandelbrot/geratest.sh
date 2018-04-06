#!/bin/bash

g++ -Wall -std=c++11 -fopenmp $1


> tempo.out

echo "2 $2 $3 $4" > entrada.in

echo "2 treads" >> tempo.out
echo "2 treads"
for (( i = 1; i <= 5; i++ )); do
	echo "Executando ${i}ª vez"
	echo "Execucao $i:" >> tempo.out
	 (/usr/bin/time -f %e ./a.out < entrada.in > saida.out) 2>> tempo.out
	echo "" >> tempo.out
done

echo "4 treads"
echo "4 $2 $3 $4" > entrada.in
echo "4 treads" >> tempo.out
for (( i = 1; i <= 5; i++ )); do
	echo "Executando ${i}ª vez"
	echo "Execucao $i:" >> tempo.out
	 (/usr/bin/time -f %e ./a.out < entrada.in > saida.out) 2>> tempo.out
	echo "" >> tempo.out
done


echo "8 treads"
echo "8 $2 $3 $4" > entrada.in
echo "8 treads" >> tempo.out
for (( i = 1; i <= 5; i++ )); do
	echo "Executando ${i}ª vez"
	echo "Execucao $i:" >> tempo.out
	 (/usr/bin/time -f %e ./a.out < entrada.in > saida.out) 2>> tempo.out
	echo "" >> tempo.out
done

echo "16 treads"
echo "16 $2 $3 $4" > entrada.in
echo "16 treads" >> tempo.out
for (( i = 1; i <= 5; i++ )); do
	echo "Executando ${i}ª vez"
	echo "Execucao $i:" >> tempo.out
	 (/usr/bin/time -f %e ./a.out < entrada.in > saida.out) 2>> tempo.out
	echo "" >> tempo.out
done

