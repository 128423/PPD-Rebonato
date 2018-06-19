#include <complex>
#include <iostream>
#include <cstdlib>

using namespace std;


int main(){
	int max_row, max_column, max_n;
	cin >> max_row;
	cin >> max_column;
	cin >> max_n;

	char **mat = (char**)malloc(sizeof(char*)*max_row);

	for (int i=0; i<max_row;i++)
		mat[i]=(char*)malloc(sizeof(char)*max_column);

	for(int r = 0; r < max_row; ++r){
		for(int c = 0; c < max_column; ++c){
			float x,y ;
			float auxR,auxIM;
			auxR = (float) c * 2 / max_column - 1.5;
			auxIM = (float) r * 2 / max_row - 1 ;
			int n = 0;
			float temp = 0;
			x=0;
			y=0;
			while((x*x + y*y)< 4 && ++n < max_n) {
				temp = x*x - y*y + auxR;
				y = 2*x*y + auxIM;
				x = temp ;
			}
			mat[r][c]=(n == max_n ? '#' : '.');
		}
	}

	for(int r = 0; r < max_row; ++r){
		for(int c = 0; c < max_column; ++c)
			std::cout << mat[r][c];
		cout << '\n';
	}	
}


