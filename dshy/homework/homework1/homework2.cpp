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
	cout << "ÀÊª˙…˙≥…¬“–Ú∏¥ ˝œÚ¡ø" <<endl; 
	for (int j = 0; j < 10; j++){
	   A[j].read_Real(rand() % 200 / 10.0);
	   A[j].read_Imaginary(rand() % 200 / 10.0);
	   A[j].read_modulus();
       A[j].display();//‘⁄∆¡ƒª…œœ‘ æ 
    }//…˙≥…∏¥ ˝ 
    for(int i=0; i<10; i++)
    B[i] = A[i];
    cout << endl;
    Vector<Complex>a(A, 10);
    Vector<Complex>b(B, 10);
    //¬“–Ú√∞≈›≈≈–Ú 
    cout<<"¬“–Ú√∞≈›≈≈–Ú:"<<endl;
    a.bubbleSort(0,10);  
    for(int i=0; i<10; i++)
    {
    	a[i].display();
	}
	cout << endl;
	//¬“–ÚπÈ≤¢≈≈–Ú 
	cout<<"¬“–ÚπÈ≤¢≈≈–Ú:"<<endl;
	b.mergeSort(0,10);
	for(int i=0;i<10;i++)
	{
		b[i].display();
	}
	cout << endl << endl;
	//≥ œ÷À≥–ÚœÚ¡ø 
	cout<<"À≥–ÚœÚ¡ø"<<endl;
	a.mergeSort(0,10);
	for(int i=0;i<10;i++)
	{
		b[i].display();
	}
	cout << endl;
    //À≥–Ú√∞≈›≈≈–Ú 
    cout<<"À≥–Ú√∞≈›≈≈–Ú:"<<endl;
    a.bubbleSort(0,10);  
    for(int i=0; i<10; i++)
    {
    	a[i].display();
	}
	cout << endl;
	//À≥–ÚπÈ≤¢≈≈–Ú 
	cout<<"À≥–ÚπÈ≤¢≈≈–Ú:"<<endl;
	b.mergeSort(0,10);
	for(int i=0;i<10;i++)
	{
		b[i].display();
	}
	cout << endl << endl;
	//ƒÊ–Ú
	cout<<"ƒÊ–ÚœÚ¡ø"<<endl;
	a.bubbleSort(-1,0,10);
	for(int i=0;i<10;i++)
	{
		a[i].display();
	}
	cout << endl;
	//ƒÊ–Ú√∞≈›≈≈–Ú
	cout<<"ƒÊ–Ú√∞≈›≈≈–Ú:"<<endl;
    a.bubbleSort(0,10);  
    for(int i=0; i<10; i++)
    {
    	a[i].display();
	}
	cout << endl;
	//ƒÊ–ÚπÈ≤¢≈≈–Ú
	cout<<"ƒÊ–ÚπÈ≤¢≈≈–Ú:"<<endl;
	b.mergeSort(0,10);
	for(int i=0;i<10;i++)
	{
		b[i].display();
	}
	cout << endl << endl;	 
	
	
	
//_______________________________________________________________________________________________________________
    cout << "º∆À„20∏ˆ∏¥ ˝œÚ¡ø≈≈–Ú ±º‰:" <<endl<<endl;
	Complex C[20];
	Complex D[20];
	cout << "ÀÊª˙…˙≥…20∏ˆ¬“–Ú∏¥ ˝œÚ¡ø(≤ªœ‘ æ)" <<endl; 
	for (int j = 0; j < 20; j++){
	   C[j].read_Real(rand() % 200 / 10.0);
	   C[j].read_Imaginary(rand() % 200 / 10.0);
	   C[j].read_modulus();

//       C[j].display();//
    }//…˙≥…∏¥ ˝ 
    for(int i=0; i<20; i++)
    	D[i] = C[i];
    Vector<Complex>c(C, 20);
    Vector<Complex>d(D, 20);  
	//¬“–Ú√∞≈›≈≈–Ú 
    cout<<"¬“–Ú√∞≈›≈≈–Ú:"<<endl;
    start = clock();
    c.bubbleSort(0,20);
    end = clock();
    duration=(double)(end-start)/ CLOCKS_PER_SEC;
	cout << "need " << duration*1000.0000 << " ms" << endl;   
    for(int i=0; i<20; i++)
    {
//    	c[i].display();
	}
	//¬“–ÚπÈ≤¢≈≈–Ú 
    cout<<"¬“–ÚπÈ≤¢≈≈–Ú:"<<endl;  
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
	//≥ œ÷À≥–ÚœÚ¡ø  
    cout<<"20∏ˆÀ≥–ÚœÚ¡ø(≤ªœ‘ æ)"<<endl;
    c.bubbleSort(0,20); 
    for(int i=0; i<20; i++)
    {
//    c[i].display();
	}
	//À≥–Ú√∞≈›≈≈–Ú 
    cout<<"À≥–Ú√∞≈›≈≈–Ú:"<<endl;
    start = clock();
    c.bubbleSort(0,20);
    end = clock();
    duration=(double)(end-start)/ CLOCKS_PER_SEC;
	cout << "need " << duration*1000.0000 << " ms" << endl;   
    for(int i=0; i<20; i++)
    {
//    	c[i].display();
	}
	//À≥–ÚπÈ≤¢≈≈–Ú 
    cout<<"À≥–ÚπÈ≤¢≈≈–Ú:"<<endl;  
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
	//≥ œ÷ƒÊ–ÚœÚ¡ø 
	cout<<"20∏ˆƒÊ–ÚœÚ¡ø(≤ªœ‘ æ)"<<endl;
	c.bubbleSort(-1,0,20);
	for(int i=0;i<20;i++)
	{
//		c[i].display();
	}
	//ƒÊ–Ú√∞≈›≈≈–Ú 
    cout<<"ƒÊ–Ú√∞≈›≈≈–Ú:"<<endl;
    start = clock();
    c.bubbleSort(0,20);
    end = clock();
    duration=(double)(end-start)/ CLOCKS_PER_SEC;
	cout << "need " << duration*1000.0000 << " ms" << endl;   
    for(int i=0; i<20; i++)
    {
//    	c[i].display();
	}
	//ƒÊ–ÚπÈ≤¢≈≈–Ú 
    cout<<"ƒÊ–ÚπÈ≤¢≈≈–Ú:"<<endl;  
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
    cout<<"¿œ ¶£¨clock∫Ø ˝ŒÛ≤ÓÃ´¥Û¡À£¨Œ“”– ±ƒ‹ ‰≥ˆ”– ˝æ›µƒ ±º‰£¨”– ±»´ «0 T^T"<<endl; 
}
