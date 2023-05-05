#include <iostream>
#include "../../vector/vector.h"
#include "../../complex/Complex.h"
using namespace std;
int main(){
	Complex A[10];
	cout << "随机生成有序复数向量" <<endl; 
	for (int j = 0; j < 10; j++){
	   A[j].read_Real(rand() % 200 / 10.0);
	   A[j].read_Imaginary(rand() % 200 / 10.0);
	   A[j].read_modulus();
//       A[j].display();//在屏幕上显示 
    }//生成复数 
    Vector<Complex>a(A,10);
    a.bubbleSort(0,10);
    for(int i=0;i<10;i++)
    	a[i].display();
    int c;
    c=a.intervalSearch(0,10,10,20);
    Complex* B =new Complex[c]; 
    B=a.check2(0,10,10,20);
    cout<<endl;
    cout<<"在[10,20)之间的复数有："<<endl;
     for(int i=0;i<c;i++)
     	B[i].display();
    cout<<endl;
    cout<<"原始数组为"<<endl;
    for(int i=0;i<10;i++)
    	a[i].display();
    	
}
