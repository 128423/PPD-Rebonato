#!/bin/bash

mpic++ -std=c++11 mandelmpi.cpp -lm -o mandelmpi 
echo "compilou mpi "
g++ -std=c++11 mandelbrot.cpp  -o sequecial
echo "compilou seq "

>tempo.out

for (( i = 1; i <= 5; i++ )); do
	echo "Executando ${i}ª vez"
	echo "Execucao $i:" >> tempo.out
	 (/usr/bin/time -f %e mpirun -np 4 mandelmpi $1 $2 $3 > mpi.out) 2>> tempo.out
	echo "" >> tempo.out
done

>entrada.in
echo "$1 $2 $3" >> entrada.in
for (( i = 1; i <= 5; i++ )); do
	echo "Executando ${i}ª vez"
	echo "Execucao $i:" >> tempo.out
	 (/usr/bin/time -f %e ./sequecial  < entrada.in > seq.out ) 2>> tempo.out
	echo "" >> tempo.out
done

echo "diff das saidas"
diff seq.out mpi.out
