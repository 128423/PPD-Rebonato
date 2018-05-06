#include <iostream>
#include <cstdlib>
#include <mpi.h>
#include <complex>


int main(int argc, char * argv[] ){

	int max_row, max_column, max_n,numprocs,ind;
	int n, parte ;
	char *vetall; 
	int max_vet;
	int procs, meurank;
    int tag=10;
	char * vet;
    MPI_Status status;
	
	//cout << max_vet ;
	MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &procs);
    MPI_Comm_rank(MPI_COMM_WORLD, &meurank);

	max_row =atoi (argv[1]);
	max_column =atoi( argv[2]);
	max_n = atoi ( argv[3]) ;

	max_vet = max_row *	max_column ;
	
	parte = max_vet/(procs);

	ind = parte * meurank ;
	
	if (meurank == 0)
	{
		vet = (char*)malloc(sizeof(char) * max_vet);
	}else {
		vet = (char*)malloc(sizeof(char) * parte);
	}
	

	for(int i = 0; i <parte; ++i)
	{
		std::complex<float> z;
		n = 0;
		while (abs(z) < 2 && ++n < max_n)
			z = pow(z, 2) + decltype(z)(
								(float)(ind % max_column) * 2 / max_column - 1.5,
								(float)(ind / max_column) * 2 / max_row - 1);

		vet[i] = (n == max_n ? '#' : '.');
		ind ++;	
	}

	// std::cout << "chegou aqui  " << meurank << '\n';

	MPI_Barrier(MPI_COMM_WORLD);
	// std::cout << "sinq " << meurank << '\n';
	MPI_Gather(vet, parte, MPI_BYTE,
			   vet, parte, MPI_BYTE,
			   0, MPI_COMM_WORLD);

	if (meurank == 0 ){
		ind = 0;
		for (int r = 0; r < max_row; ++r)
		{
			for (int c = 0; c < max_column; ++c)
				std::cout << vet[r * max_column + c];
			std::cout << '\n';
		}
	
	}


	MPI_Finalize(); 
	
		return 0 ;
	}
