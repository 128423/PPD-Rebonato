#include <iostream>
#include <cstdlib>
#include <mpi.h>
#include <complex>

int main(int argc, char *argv[])
{

    int max_row, max_column, max_n, numprocs, ind;
    int n;
    int max_vet;
    int procs, meurank;
    int chunk, auxchunk;
    int tag = 10;
    int die_tag = 0 ; 
    char *vet;
    MPI_Status status;

    //cout << max_vet ;
    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &procs);
    MPI_Comm_rank(MPI_COMM_WORLD, &meurank);

    max_row = atoi(argv[1]);
    max_column = atoi(argv[2]);
    max_n = atoi(argv[3]);

    max_vet = max_row * max_column;
    chunk = 100;
    auxchunk = max_vet % chunk;

    if(auxchunk == 0 ){
        auxchunk = chunk;
    }


    if (meurank == 0)
    {
        int vetind[procs];
        char *reciver;
        int source;
        int indproc;
        vet = (char *)malloc(sizeof(char) * (max_vet+(chunk - auxchunk)));
        reciver = (char *)malloc(sizeof(char) * chunk);
        ind = 0;
        vetind[0]=0;
        for (int i = 1; i < procs; i++)
        {
            MPI_Send(&ind, 1, MPI_INT, i, tag, MPI_COMM_WORLD);
            vetind[i] = ind;
            ind += chunk;
        }       
        
        while(ind < max_vet)
        {
            MPI_Recv(reciver, chunk, MPI_CHAR, MPI_ANY_SOURCE, MPI_ANY_TAG,MPI_COMM_WORLD, &status);
            source = status.MPI_SOURCE;

            indproc = vetind[source];

            for(int i =0;i  <  chunk;i++){
                vet[(i + indproc)]= reciver[i];
             }    
            //vet[vetind[source]] = reciver;

            MPI_Send(&ind,1,MPI_INT,source,tag,MPI_COMM_WORLD);
            vetind[source] = ind;
            ind += chunk;

         }

         for(int i = 1 ; i < procs;i++){
            MPI_Recv(reciver, chunk, MPI_CHAR, MPI_ANY_SOURCE, MPI_ANY_TAG,MPI_COMM_WORLD, &status);
             //colocar na vet;
            source = status.MPI_SOURCE;
                 

            for(int i =0 ;i  <  chunk;i++){
                vet[(i + indproc)]= reciver[i];
            }
              
            MPI_Send(&die_tag,1,MPI_INT,source,die_tag,MPI_COMM_WORLD);
        }

        
            
            for (int r = 0; r < max_row; ++r)
             {
                for (int c = 0; c < max_column; ++c)
                     std::cout << vet[r * max_column + c];
                std::cout << '\n';
             }
    }
    else

    {
        //std::cout << "chegou aqui" << meurank << "\n";
        vet = (char *)malloc(sizeof(char) * chunk);
        
        MPI_Recv(&ind,1, MPI_INT,0, MPI_ANY_TAG,MPI_COMM_WORLD, &  status);
        while(status.MPI_TAG > 0){


            for (int i = 0; i < chunk; ++i)
            {
                std::complex<float> z;
                n = 0;
                while (abs(z) < 2 && ++n < max_n)
                    z = pow(z, 2) + decltype(z)(
                                        (float)(ind % max_column) * 2 / max_column - 1.5,
                                        (float)(ind / max_column) * 2 / max_row - 1);

                vet[i] = (n == max_n ? '#' : '.');
                ind++;
              //  std::cout << vet[i];
            }
        
        
            MPI_Send(vet,chunk,MPI_CHAR,0,tag,MPI_COMM_WORLD);

            MPI_Recv(&ind,1,MPI_INT,0,MPI_ANY_TAG,MPI_COMM_WORLD,&status);

        }
        

    }

    MPI_Finalize();

    return 0;
}