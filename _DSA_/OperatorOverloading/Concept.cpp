#include<iostream>
using namespace std;
  
class Complex {
private:
    int real, imag;
public:
    Complex(int r = 0, int i =0)  {real = r;   imag = i;}
      
    // This is automatically called when '+' is used 
    // between two Complex objects
    Complex operator + (Complex const &obj) {
         Complex res;
         res.real = real + obj.real;
         res.imag = imag + obj.imag;
         return res;
    }
    void print() { cout << real << " + i" << imag << endl; }
};

class Hi{
	private:
	int a,b;
	public: 
	Hi(){
		a = 0;
		b = 0;
	}
	Hi(int a ,int b){
		this -> a = a;
		this -> b = b;
	}
	 void print() { cout << a << " + " << b<< endl; }


	//  in other way we can say that we have CAN have a method name as alphabets only
	//but if want a operator instead of alphabetical name for function we can use operator keyword
	//remember the operator to be used as function name should be a valid opeartor
	//the left object is collar object which in case is h1
	 Hi add(Hi const &h){
		Hi c;
		c.a = a+ h.a;
		c.b = b+ h.b;
		return c;
	 }
	 //or
	 //the left object is collar object for binary operator
	 Hi operator +(Hi const &h){
		Hi c;
		c.a = a+ h.a;
		c.b = b+ h.b;
		return c;
	 }
	 //unary operator is collar opeartor
	 Hi operator -(){

		 //preIncrement
		 Hi h;
		 h.a= -a;
		 h.b= -b;
		 return h;
	 }

	 //pre and post increment operator
	 //compiler calls post increment operator when it has one argument inside
	 //or we are passing int as parameter so that compiler can Differenciaste between this two methods
	 Hi operator ++(int){

		//Post Increment
		 Hi h;
		 h.a= a++;
		 h.b= b++;
		 return h;

	 }
	 Hi operator ++(){
		 Hi h;
		 h.a= ++a;
		 h.b= ++b;
		 return h;

	 }

};
  
int main()
{
    Complex c1(10, 5), c2(2, 4);
    Hi h1(112, 5), h2(221, 4);
    Complex c3 = c1 + c2; // An example call to "operator+"
    c3.print();
    //the left object is collar object which in case is h1
    Hi h3 = h1 + h2;
    //we can also write in this way 
    //     h4 = h1.operator+(h2);
    Hi h4 = h1.add(h2);
    //Hi h5 = -h5;
	// or 
    Hi h5 = h1.operator-();
    h3.print();
    h4.print();
    h5.print();
}