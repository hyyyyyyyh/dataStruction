#include <iostream>
#include "../../vector/vector.h"
#include "../../complex/Complex.h"
using namespace std;
int main()
{
	Complex A[10];
	cout << "�����������������" <<endl; 
	for (int j = 0; j < 10; j++){
	   A[j].read_Real(rand() % 200 / 10.0);
	   A[j].read_Imaginary(rand() % 200 / 10.0);
	   A[j].read_modulus();
       A[j].display();//����Ļ����ʾ 
    }//���ɸ��� 
    cout << endl;
    //����
    Vector<Complex>a(A, 10);
	cout<<"���Һ�"<<endl;
    a.unsort(0,10);
    for (int i=0;i<10;i++)
    {
    	a._elem[i].display();
	}
	cout<<endl;
	//����
	cout<<"����"<<endl;
	int x;
	x = a.find(A[7]);
	cout<<"A[7]��ʱ��λ��Ϊ"<<x<<endl;
	cout<<endl;
	//����
	cout<<"�����"<<endl;  
	a.insert(7,A[7]) ;
	for(int i=0;i<a.size();i++)
		a._elem[i].display(); 
	cout<<endl;
	//ɾ��
	cout<<"ɾ����"<<endl;
	a.remove(3);
	for(int i=0;i<a.size();i++)   
		a._elem[i].display(); 
	cout<<endl;
	//Ψһ��
	cout<<"Ψһ��"<<endl; 
	x = a.deduplicate();
	for(int i=0;i<a.size();i++)
		a._elem[i].display(); 
	cout << "�ظ������ĸ���Ϊ" << x << endl <<"Ψһ����"<< endl;
	
	
}
