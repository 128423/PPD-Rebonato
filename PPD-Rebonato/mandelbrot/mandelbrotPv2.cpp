#include <complex>
#include <iostream>
#include <cstdlib>
#include <omp.h>

using namespace std;

int main(){

	int max_row, max_column, max_n, numteads;
	
	cin >> numteads;

	if(numteads == 4 || numteads == 8 || numteads == 16 || numteads == 2 ){

		omp_set_num_threads(numteads);
	}else{
		exit(2);
	}

	cin >> max_row;
	cin >> max_column;
	cin >> max_n;

	int max_vet = max_row *	max_column ;

	//cout << max_vet ;
	
	char *mat = (char*)malloc(sizeof(char) * max_vet);

	int chunk = 1000;

	// x = c*r  	

	int n  ;
	#pragma omp parallel for private(n) schedule(dynamic,chunk) 
	for(int i = 0; i < max_vet; ++i){
		 complex<float> z;
		 n = 0;
		 while(abs(z) < 2 && ++n < max_n)
			z = pow(z, 2) + decltype(z) ( 
				(float) ( i % max_column) * 2 / max_column - 1.5,
				(float) (i / max_column)  * 2 / max_row - 1 );

		mat[i]=(n == max_n ? '#' : '.');
	}
	
	
	for(int r = 0; r < max_row; ++r){
		for(int c = 0; c < max_column; ++c)
			std::cout << mat[r*max_column + c];
		cout << '\n';
	}		return 0 ;
}


