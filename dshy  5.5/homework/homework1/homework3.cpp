#include <iostream>
#include "../../vector/vector.h"
#include "../../complex/Complex.h"
using namespace std;
int main(){
	Complex A[10];
	cout << "�����������������" <<endl; 
	for (int j = 0; j < 10; j++){
	   A[j].read_Real(rand() % 200 / 10.0);
	   A[j].read_Imaginary(rand() % 200 / 10.0);
	   A[j].read_modulus();
//       A[j].display();//����Ļ����ʾ 
    }//���ɸ��� 
    Vector<Complex>a(A,10);
    a.bubbleSort(0,10);
    for(int i=0;i<10;i++)
    	a[i].display();
    int c;
    c=a.intervalSearch(0,10,10,20);
    Complex* B =new Complex[c]; 
    B=a.check2(0,10,10,20);
    cout<<endl;
    cout<<"��[10,20)֮��ĸ����У�"<<endl;
     for(int i=0;i<c;i++)
     	B[i].display();
    cout<<endl;
    cout<<"ԭʼ����Ϊ"<<endl;
    for(int i=0;i<10;i++)
    	a[i].display();
    	
}
