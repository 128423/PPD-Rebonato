#include <complex>
#include <iostream>
#include <cstdlib>
#include <omp.h>

using namespace std;

struct aij
{
	int L;
	int C;
	
};

int main(){
	int max_row, max_column, max_n;
	cin >> max_row;
	cin >> max_column;
	cin >> max_n;

	int max_vet = max_row * max_column ;

	//cout << max_vet ;
	
	char *mat = (char*)malloc(sizeof(char) * max_vet);

	aij *vetaij = (aij*) malloc(sizeof(aij)* max_vet);
	
	int l = 0 ;
	int c = 0 ;
	for (int i = 0; i < max_vet; ++i)
	{
		if (c == max_column)
		{
			c = 0;
			l++;	
		}
		vetaij[i].L = l;
		vetaij[i].C = c;
		c++;

	}

/*
	for (int i = 0; i < max_vet; ++i)
	{
		cout << mat [i] << '\t' << i << '\n' ;

	}
*/	

	int chunk = 10000;
	omp_set_num_threads(4);


	// x = c*r 

	int n  ;
	#pragma omp parallel for private(n) schedule(dynamic,chunk) 
	for(int i = 0; i < max_vet; ++i){
		 complex<float> z;
		 n = 0;
		 while(abs(z) < 2 && ++n < max_n)
			z = pow(z, 2) + decltype(z) ( 
				(float) vetaij[i].C * 2 / max_column - 1.5,
				(float) vetaij[i].L * 2 / max_row - 1 );

		mat[i]=(n == max_n ? '#' : '.');
	}
	
	
	c = 0;
		for (int i = 0; i < max_vet; ++i)
	{
		cout << mat [i];
		c++;
		if(c == max_column){
			cout << '\n' ;
			c = 0 ;
		}
	}
	return 0 ;
}


