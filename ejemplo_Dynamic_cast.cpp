#include <iostream>
using namespace std;

class A{
	public:
		int a;
		virtual void print() { cout<<"I'm A\n"; };
};
	
class B: virtual public A{
	public:
		int b;
		void print(){cout<<"I'm B\n";};
};

class C: virtual public A {
	public:
		int c;
		void print(){cout<<"yo soy C\n";}
};

class D: public C, public B{
	public:
		int d;
		void print(){cout<<"yo soy D\n";}
};


int main(){
	A *abc[4];
	abc[0]= new A;
	abc[1]= new B;
	abc[2]= new C;
	abc[3]=new D;
	
	C* 	C_aux;
	D* D_aux;

	B* B_aux = dynamic_cast<B*>(abc[1]);//B_aux has access to full members of B class. 	
	C* C_aux = dynamic_cast<C*>(abc[2]);//C_aux has access to full members of C class. 	
	D* D_aux = dynamic_cast<D*>(abc[3]);//D_aux has access to full members of B class.	
	
	abc[0]->a=5;
	B_aux->b=10;
	C_aux->c=15;
	D_aux->d=20;
		
	cout<<abc[0]->a<<"\n";
	cout<<B_aux->b<<"\n";
	cout<<C_aux->c<<"\n";
	cout<<D_aux->d<<"\n";
		

	D_aux->a=50;
	cout<<D_aux->a<<"\n";

	abc[0]->print();
	abc[1]->print();
	abc[2]->print();
	abc[3]->print();

	return 0;
}

	
