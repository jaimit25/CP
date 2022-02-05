#include <iostream>
#include <stdlib.h>
using namespace std;

struct Matrix
{
	//we take pointer because we dont know size of MATRICE
	int *A;
	int n;
};


void Rowset(struct Matrix *m ,int i ,int j , int x){
	//for lower matrice i >= j
	if(i>=j){
		m->A[(i*(i-1)/2) + (j-1) ]=x;
	}
	else{
		m->A[(i*(i-1)/2) + (j-1) ]=0;
	}
}	 
void Columnset(struct Matrix *m ,int i ,int j , int x){
	//for lower matrice i >= j
	if(i>=j){
		m->A[m->n*(j-1)-(j-1)*(j-2)/2+i-j]=x;
	}
	else{
		m->A[m->n*(j-1)-(j-1)*(j-2)/2+i-j]=0;
	}
}	 

int Rowget(struct Matrix m, int i , int  j){
	
	if(i>= j){
		return m.A[(i*(i-1)/2) + (j-1) ];
	}
	else return 0;
}
int Columnget(struct Matrix m, int i , int  j){
	
	if(i>= j){
		return m.A[m.n*(j-1)-(j-1)*(j-2)/2+i-j];
	}
	else return 0;
}

void RowDisplay ( struct Matrix m ){
	int i , j ;
	for( i = 1 ; i <= m.n ; i++){
		for( j = 1 ; j <= m.n ; j++){
			if( i >= j ) { 
				cout<<" "<<m.A[(i*(i-1)/2) + (j-1)];
			}
			else{
				cout<<" 0";
			}
		}
		cout<<endl;
	}
}
void ColumnDisplay ( struct Matrix m ){
	int i , j ;
	for( i = 1 ; i <= m.n ; i++){
		for( j = 1 ; j <= m.n ; j++){
			if( i >= j ) { 
				cout<<" "<<m.A[m.n*(j-1)-(j-1)*(j-2)/2+i-j];
			}
			else{
				cout<<" 0";
			}
		}
		cout<<endl;
	}
}


int main()
{

	struct Matrix m;
	int i , j;
	int store;
	cout<<"Enter Dimension "<<endl;
	cin>>m.n;
	m.A = (int*)malloc((m.n*(m.n+1))/2*(sizeof(int)));
	for( i = 1 ; i <= m.n ; i++){
		for( j = 1 ; j <= m.n ; j++){
				cin>>store;
				// Rowset(&m,i,j,store);
				 Columnset(&m,i,j,store);
		}
		cout<<endl;
	}

	RowDisplay(m);

	return 0;
}