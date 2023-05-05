#include <iostream>
#include "../../vector/vector.h"
#include "../../complex/Complex.h"
using namespace std;
int main()
{
	Complex A[10];
	cout << "随机生成无序复数向量" <<endl; 
	for (int j = 0; j < 10; j++){
	   A[j].read_Real(rand() % 200 / 10.0);
	   A[j].read_Imaginary(rand() % 200 / 10.0);
	   A[j].read_modulus();
       A[j].display();//在屏幕上显示 
    }//生成复数 
    cout << endl;
    //置乱
    Vector<Complex>a(A, 10);
	cout<<"置乱后"<<endl;
    a.unsort(0,10);
    for (int i=0;i<10;i++)
    {
    	a._elem[i].display();
	}
	cout<<endl;
	//查找
	cout<<"查找"<<endl;
	int x;
	x = a.find(A[7]);
	cout<<"A[7]此时的位置为"<<x<<endl;
	cout<<endl;
	//插入
	cout<<"插入后"<<endl;  
	a.insert(7,A[7]) ;
	for(int i=0;i<a.size();i++)
		a._elem[i].display(); 
	cout<<endl;
	//删除
	cout<<"删除后"<<endl;
	a.remove(3);
	for(int i=0;i<a.size();i++)   
		a._elem[i].display(); 
	cout<<endl;
	//唯一化
	cout<<"唯一化"<<endl; 
	x = a.deduplicate();
	for(int i=0;i<a.size();i++)
		a._elem[i].display(); 
	cout << "重复复数的个数为" << x << endl <<"唯一化后："<< endl;
	
	
}
