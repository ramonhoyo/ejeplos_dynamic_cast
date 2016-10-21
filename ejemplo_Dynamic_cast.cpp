#include <iostream>
using namespace std;

	class A{
		public:
		int a;
		virtual void imprimir() {cout<<"yo soy A\n";};
	};
	
	class B:virtual public A{
		public:
		int b;
		void imprimir(){cout<<"yo soy B\n";};
	};

	class C:virtual public A{
		public:
			int c;
		void imprimir(){cout<<"yo soy C\n";}
	};

	class D:public C, public B{
		public:
			int d;
		void imprimir(){cout<<"yo soy D\n";}
	};


	int main(){
	A *abc[4];
		abc[0]= new A;
		abc[1]= new B;
		abc[2]= new C;
		abc[3]=new D;
		
		//necesitamos apuntadores auxiliares al el tipo que deseamos castear.
	B*	B_aux;
	C* 	C_aux;
	D* D_aux;

		//hacemos los casteos.
	B_aux=dynamic_cast<B*>(abc[1]);//B_aux tiene acceso a todos los metodos publicos de B. 	
	C_aux=dynamic_cast<C*>(abc[2]);//C_aux tiene acceso a todos los metodos publicos de C. 	
	D_aux=dynamic_cast<D*>(abc[3]);//D_aux tiene acceso a todos los metodos publicos de D.	
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

		abc[0]->imprimir();
		abc[1]->imprimir();
		abc[2]->imprimir();
		abc[3]->imprimir();

		return 0;
	}

	
