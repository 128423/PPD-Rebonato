#!/bin/bash

mpic++ -std=c++11 mandelmpi2.cpp -lm -o mandelmpi 
echo "compilou mpi "


>tempo.out


echo "2" >> tempo.out
for (( i = 1; i <= 2; i++ )); do
	echo "Executando ${i}ª vez"
	echo "Execucao $i:" >> tempo.out
	(/usr/bin/time -f %e mpirun -np 2 --hostfile host mandelmpi $1 $2 $3  > mpi.out) 2>> tempo.out
	echo "" >> tempo.out
done


echo "4" >> tempo.out
for (( i = 1; i <= 5; i++ )); do
	echo "Executando ${i}ª vez"
	echo "Execucao $i:" >> tempo.out
	(/usr/bin/time -f %e mpirun -np 4 --hostfile host mandelmpi $1 $2 $3 > mpi.out) 2>> tempo.out
	echo "" >> tempo.out
done

echo "8" >> tempo.out
for (( i = 1; i <= 5; i++ )); do
	echo "Executando ${i}ª vez"
	echo "Execucao $i:" >> tempo.out
	(/usr/bin/time -f %e mpirun -np 8 --hostfile host mandelmpi $1 $2 $3  > mpi.out) 2>> tempo.out
	echo "" >> tempo.out
done

echo "16" >> tempo.out
for (( i = 1; i <= 5; i++ )); do
	echo "Executando ${i}ª vez"
	echo "Execucao $i:" >> tempo.out
	(/usr/bin/time -f %e mpirun -np 16 --hostfile host mandelmpi $1 $2 $3 > mpi.out) 2>> tempo.out
	echo "" >> tempo.out
done


echo "32" >> tempo.out	
for (( i = 1; i <= 5; i++ )); do
	echo "Executando ${i}ª vez"
	echo "Execucao $i:" >> tempo.out
	(/usr/bin/time -f %e mpirun -np 32 --hostfile host mandelmpi $1 $2 $3  > mpi.out) 2>> tempo.out
	echo "" >> tempo.out
done


echo "64" >> tempo.out	
for (( i = 1; i <= 5; i++ )); do
	echo "Executando ${i}ª vez"
	echo "Execucao $i:" >> tempo.out
	(/usr/bin/time -f %e mpirun -np 64 --hostfile host mandelmpi $1 $2 $3  > mpi.out) 2>> tempo.out
	echo "" >> tempo.out
done
