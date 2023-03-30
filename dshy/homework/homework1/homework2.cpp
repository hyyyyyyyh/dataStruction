#include <iostream>
#include "../../vector/vector.h"
#include "../../complex/Complex.h"

#include<iostream>
#include<time.h>

using namespace std;
int main(){
	int m = 0;
	clock_t start, end;

	double duration; 
	Complex A[10];
	Complex B[10];
	cout << "�����������������" <<endl; 
	for (int j = 0; j < 10; j++){
	   A[j].read_Real(rand() % 200 / 10.0);
	   A[j].read_Imaginary(rand() % 200 / 10.0);
	   A[j].read_modulus();
       A[j].display();//����Ļ����ʾ 
    }//���ɸ��� 
    for(int i=0; i<10; i++)
    B[i] = A[i];
    cout << endl;
    Vector<Complex>a(A, 10);
    Vector<Complex>b(B, 10);
    //����ð������ 
    cout<<"����ð������:"<<endl;
    a.bubbleSort(0,10);  
    for(int i=0; i<10; i++)
    {
    	a[i].display();
	}
	cout << endl;
	//����鲢���� 
	cout<<"����鲢����:"<<endl;
	b.mergeSort(0,10);
	for(int i=0;i<10;i++)
	{
		b[i].display();
	}
	cout << endl << endl;
	//����˳������ 
	cout<<"˳������"<<endl;
	a.mergeSort(0,10);
	for(int i=0;i<10;i++)
	{
		b[i].display();
	}
	cout << endl;
    //˳��ð������ 
    cout<<"˳��ð������:"<<endl;
    a.bubbleSort(0,10);  
    for(int i=0; i<10; i++)
    {
    	a[i].display();
	}
	cout << endl;
	//˳��鲢���� 
	cout<<"˳��鲢����:"<<endl;
	b.mergeSort(0,10);
	for(int i=0;i<10;i++)
	{
		b[i].display();
	}
	cout << endl << endl;
	//����
	cout<<"��������"<<endl;
	a.bubbleSort(-1,0,10);
	for(int i=0;i<10;i++)
	{
		a[i].display();
	}
	cout << endl;
	//����ð������
	cout<<"����ð������:"<<endl;
    a.bubbleSort(0,10);  
    for(int i=0; i<10; i++)
    {
    	a[i].display();
	}
	cout << endl;
	//����鲢����
	cout<<"����鲢����:"<<endl;
	b.mergeSort(0,10);
	for(int i=0;i<10;i++)
	{
		b[i].display();
	}
	cout << endl << endl;	 
	
	
	
//_______________________________________________________________________________________________________________
    cout << "����20��������������ʱ��:" <<endl<<endl;
	Complex C[20];
	Complex D[20];
	cout << "�������20������������(����ʾ)" <<endl; 
	for (int j = 0; j < 20; j++){
	   C[j].read_Real(rand() % 200 / 10.0);
	   C[j].read_Imaginary(rand() % 200 / 10.0);
	   C[j].read_modulus();

//       C[j].display();//
    }//���ɸ��� 
    for(int i=0; i<20; i++)
    	D[i] = C[i];
    Vector<Complex>c(C, 20);
    Vector<Complex>d(D, 20);  
	//����ð������ 
    cout<<"����ð������:"<<endl;
    start = clock();
    c.bubbleSort(0,20);
    end = clock();
    duration=(double)(end-start)/ CLOCKS_PER_SEC;
	cout << "need " << duration*1000.0000 << " ms" << endl;   
    for(int i=0; i<20; i++)
    {
//    	c[i].display();
	}
	//����鲢���� 
    cout<<"����鲢����:"<<endl;  
    start = clock();
    d.mergeSort(0,20);
    end = clock();
    duration=(double)(end-start)/ CLOCKS_PER_SEC;
	cout << "need " << duration*1000.0000 << " ms" << endl;   
    for(int i=0; i<20; i++)
    {
//    	d[i].display();
	}
	cout<<endl; 
	//����˳������  
    cout<<"20��˳������(����ʾ)"<<endl;
    c.bubbleSort(0,20); 
    for(int i=0; i<20; i++)
    {
//    c[i].display();
	}
	//˳��ð������ 
    cout<<"˳��ð������:"<<endl;
    start = clock();
    c.bubbleSort(0,20);
    end = clock();
    duration=(double)(end-start)/ CLOCKS_PER_SEC;
	cout << "need " << duration*1000.0000 << " ms" << endl;   
    for(int i=0; i<20; i++)
    {
//    	c[i].display();
	}
	//˳��鲢���� 
    cout<<"˳��鲢����:"<<endl;  
    start = clock();
    d.mergeSort(0,20);
    end = clock();
    duration=(double)(end-start)/ CLOCKS_PER_SEC;
	cout << "need " << duration*1000.0000 << " ms" << endl;   
    for(int i=0; i<20; i++)
    {
//    	d[i].display();
	}
	cout<<endl; 
	//������������ 
	cout<<"20����������(����ʾ)"<<endl;
	c.bubbleSort(-1,0,20);
	for(int i=0;i<20;i++)
	{
//		c[i].display();
	}
	//����ð������ 
    cout<<"����ð������:"<<endl;
    start = clock();
    c.bubbleSort(0,20);
    end = clock();
    duration=(double)(end-start)/ CLOCKS_PER_SEC;
	cout << "need " << duration*1000.0000 << " ms" << endl;   
    for(int i=0; i<20; i++)
    {
//    	c[i].display();
	}
	//����鲢���� 
    cout<<"����鲢����:"<<endl;  
    start = clock();
    d.mergeSort(0,20);
    end = clock();
    duration=(double)(end-start)/ CLOCKS_PER_SEC;
	cout << "need " << duration*1000.0000 << " ms" << endl;   
    for(int i=0; i<20; i++)
    {
//    	d[i].display();
	}
	cout<<endl; 
	cout<<"!!!!!!!!!"<<endl;	
    cout<<"��ʦ��clock�������̫���ˣ�����ʱ����������ݵ�ʱ�䣬��ʱȫ��0 T^T"<<endl; 
}
