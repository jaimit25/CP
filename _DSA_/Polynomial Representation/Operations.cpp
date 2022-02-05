#include <iostream>
#include <stdlib.h>

using namespace std;

struct Term
{
	int coeff;
	int exp;
};
struct Poly
{
	int n;
	struct Term *t;
};

void create(struct Poly *p)
{
	int i, j, k;
	i = j = k = 0;
	printf("Enter Number of Non Zero Elements : \n");
	scanf("%d", &(p->n));
	p->t = (struct Term *)malloc(p->n * sizeof(struct Term));
	for (i = 0; i < p->n; i++)
	{
		printf("Enter Coeff and Exponent for Term %d : ", i + 1);
		scanf("%d %d", &p->t[i].coeff,
		      &p->t[i].exp);
	}
}

void display(struct Poly p)
{
	for (int i = 0; i < p.n; i++)
	{
		cout << p.t[i].coeff << "x^" << p.t[i].exp << " +";
	}
	cout << endl;
}

struct Poly *add(struct Poly *p1, struct Poly *p2)
{

	struct Poly *sum;
	sum = (struct Poly *)malloc(sizeof(struct Poly));
	sum -> t = (struct Term *)malloc((p1 -> n + p2 -> n)*sizeof(struct Poly));
	int i , j , k ;
	i = j = k = 0 ;
	sum->n = p1->n + p2->n;
	while(i < p1 -> n && j < p2 -> n){
		if(p1->t[i].exp > p2->t[i].exp)
		 sum-> t[k++] = p1->t[i++];
		 else if(p1->t[i].exp < p2->t[i].exp)
		 sum-> t[k++] = p2->t[j++];
		 else{
		    sum -> t[k].exp  = p1->t[i].exp;
		    sum -> t[k++].coeff  = p1->t[i++].coeff + p2->t[j++].coeff;
		 }
	}
	for(;i< p1->n;i++){
		sum-> t[k++] = p1 -> t[i];
	}
	for(;j< p2->n;j++){
		sum-> t[k++] = p2->t[j];
	}

	return sum;
}

int main()
{	
	struct Poly p1, p2, *sumpoly;
	cout << "Creating Polynomial 1 :" << endl;
	create(&p1);
	cout << "Creating Polynomial 2 :" << endl;
	create(&p2);
	cout<<"Display Polynomial 1 and Polynomial 2 : "<<endl;
	display(p1);
	display(p2);
	cout<<"Adding Polynomial 1 and Polynomial 2 : "<<endl;
	sumpoly = add(&p1, &p2);
	display(*sumpoly);
	return 0;
}