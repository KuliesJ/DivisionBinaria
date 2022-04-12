#include <iostream>
#include <bitset>
using namespace std;

int main(){
	/*A es el residuo
	  M es el divisor (palabra binaria de n bits)
	  Q es el dividendo (palabra binaria de n bits)
	  R es el resultado de la división
	  n es la cantidad de bits de los factores a multiplicar*/
	int auxiliar, divisor, dividendo, n=4;
	cout<<"Divisor: "; cin>>divisor;
	cout<<"Dividendo: "; cin>>dividendo;
	bitset<4> A(0);
	bitset<4> M(dividendo);
	bitset<4> Q(divisor);
	cout<<"Valor de A: "<<A<<endl;
	cout<<"Valor de Q: "<<Q<<endl;
	while(n>0){
		cout<<endl;
		//Corrimiento a la izquierda
		A <<=1;
		A[0]=Q[3];
		Q <<=1;
		A=A.to_ulong()+ ~M.to_ulong()+1;
		
		//A<0
		if(A[3]==0){
			cout<<"Valor de A: "<<A<<endl;
			Q[0]=1;
		}
		else{
			cout<<"Valor de A: "<<A<<endl;
			Q[0]=0;
			A=A.to_ulong()+M.to_ulong();
		}

		cout<<"Valor de Q: "<<Q<<endl;
		n--;
	}
	/*Residuo= 0001 - Cociente 0010*/
	cout<<"Cociente: "<<Q.to_ulong()<<endl<<"Residuo: "<<A.to_ulong()<<endl;
	return 0;
}
