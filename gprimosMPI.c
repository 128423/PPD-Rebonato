#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <omp.h>

#define TAM 1200
#define MAX 100

int ehprimo(int num);

int main(int argc, char **argv){
	int i, j, k;
    int *vet;
    int  meurank, procs, parte, ind=0,delta,Nfolhas;
    


    srand(313);
    vet = (int *)malloc(sizeof(int) * TAM);
    if (vet == NULL){
        printf("Nao foi\n");
        exit(1);
    }

    for(i=0; i < TAM; i++)
        vet[i] = rand() % MAX;


    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &procs);
    MPI_Comm_rank(MPI_COMM_WORLD, &meurank);
    
    Nfolhas = ((int) procs/2) + 1 ;
    delta = TAM / Nfolhas;
    if ()
    {
        /* code */
    }

    if (meurank != 0)
        MPI_Send(&envia, 1, MPI_INT, meurank+1, tag, MPI_COMM_WORLD);
    

    j=0;  
    for(i=0; i < TAM; i++){
        if (ehprimo(vet[i])){
            j++;
            //printf("%d\n", vet[i]);
        }

    }


    printf("Primos %d\n", j);


}


int ehprimo(int num){
    int i,c=0;    

    for(i=3; i < num/2+1; i++)
        if ((num % i ) == 0){
            c++;
            break;
        }
    return (c == 0 ? 1 : 0);
}
