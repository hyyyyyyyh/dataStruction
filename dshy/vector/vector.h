#include<stdlib.h>
#include <iostream>
typedef int Rank; //��
#define DEFAULT_CAPACITY  3 //Ĭ�ϵĳ�ʼ������ʵ��Ӧ���п�����Ϊ����
using namespace std;

template <typename T> class Vector { //����ģ����
public:
	
   Rank _size; int _capacity, clock;  T* _elem; //��ģ��������������
   void copyFrom ( T const* A, Rank lo, Rank hi ); //������������A[lo, hi)
   void expand(); //�ռ䲻��ʱ����
   void shrink(); //װ�����ӹ�Сʱ���� 
   void merge ( Rank lo, Rank mi, Rank hi ); //�鲢�㷨
   void mergeSort ( Rank lo, Rank hi ); //�鲢�����㷨
   Rank partition ( Rank lo, Rank hi );
   void quickSort ( Rank lo, Rank hi );
   void heapSort ( Rank lo, Rank hi );
public:
// ���캯�� 
   T* check2(Rank lo, Rank hi, double m1, double m2);
   void bubbleSort (Rank n , Rank lo, Rank hi);
   Rank intervalSearch (Rank lo,Rank hi, double m, double n);
   bool bubble ( Rank lo, Rank hi ); //ɨ�轻��
   bool bubble ( Rank n, Rank lo, Rank hi ); //ɨ�轻��
   void bubbleSort ( Rank lo, Rank hi ); //���������㷨
   Vector ( int c = DEFAULT_CAPACITY, int s = 0, T v = 0 ) {
   //����Ϊc����ģΪs������Ԫ�س�ʼΪv 
   _elem = new T[_capacity = c]; 
   for( _size = 0; _size < s; _elem[_size++] = v );} //s<=c
   Vector ( T const* A, Rank n ) 
  	    { copyFrom ( A, 0, n ); } //�������帴��
   Vector ( T const* A, Rank lo, Rank hi )
    	{ copyFrom ( A, lo, hi ); } //����
   Vector ( Vector<T> const& V )
    	{ copyFrom ( V._elem, 0, V._size ); } //�������帴��
   Vector ( Vector<T> const& V, Rank lo, Rank hi )
   	    { copyFrom ( V._elem, lo, hi ); } //����
// ��������
   ~Vector() { delete [] _elem; } //�ͷ��ڲ��ռ�
// ֻ�����ʽӿ�
   Rank size() const { return _size; } //��ģ
   bool empty() const { return !_size; } //�п�

   int disordered() const; //�ж������Ƿ�������
   Rank find ( T const& e ) const { return find ( e, 0, _size ); } //���������������
   Rank find ( T const& e, Rank lo, Rank hi ) const; //���������������
   Rank search ( T const& e ) const //���������������
   { return ( 0 >= _size ) ? -1 : search ( e, 0, _size ); }
   Rank search ( T const& e, Rank lo, Rank hi ) const; //���������������
   Rank binSearch (T* A, T const& e, Rank lo, Rank hi); 
   Rank fibSearch (T* A, T const& e, Rank lo, Rank hi);
// ��д���ʽӿ�
   T& operator [] ( Rank r ) const; //�����±������������������������ʽ���ø�Ԫ��
   Vector<T>& operator = ( Vector<T> const& ); //���ظ�ֵ���������Ա�ֱ�ӿ�¡����
   T remove ( Rank r ); //ɾ����Ϊr��Ԫ��
   int remove ( Rank lo, Rank hi ); //ɾ����������[lo, hi)֮�ڵ�Ԫ��
   Rank insert ( Rank r, T const& e ); //����Ԫ��

   Rank insert ( T const& e ) 

   { return insert ( _size, e ); } //Ĭ����ΪĩԪ�ز���
   void unsort ( Rank lo, Rank hi ); //��[lo, hi)����
   void unsort()
    { unsort ( 0, _size ); } //��������
   int deduplicate(); //����ȥ��
   int uniquify(); //����ȥ��
// ����
void traverse ( void (* ) ( T& ) ); //������ʹ�ú���ָ�룬ֻ����ֲ����޸ģ�
template <typename VST> void traverse ( VST& ); //������ʹ�ú������󣬿�ȫ�����޸ģ�
}; //Vector


//��������������������������������������������������������������������������������������������������������������������
template <typename T> //Ԫ������
void Vector<T>::copyFrom ( T const* A, Rank lo, Rank hi ){ //����������A[lo,hi)Ϊ������������
	_elem = new T[_capacity = 2 * (hi - lo)]; _size = 0; //����ռ䣬��ģ���� 
	while (lo < hi) //A[lo, hi)�ڵ�Ԫ����һ 
	    _elem[_size++] = A[lo++]; //������_elem[0, hi - lo) 
}

template <typename T> 
Vector<T>& Vector<T>::operator= ( Vector<T> const& V) {
	if( _elem ) delete [] _elem; //�ͷ�ԭ������
	copyFrom (V._elem, 0, V.size());  //���帴��
	return *this; //���ص�ǰ��������ã��Ա���ʽ��ֵ 
}

template <typename T> 
void Vector<T>::expand() { //�����ռ䲻��ʱ���� 
	if( _size < _capacity ) return; //��δ��Աʱ���������� 
	if( _capacity < DEFAULT_CAPACITY ) _capacity = DEFAULT_CAPACITY; //��������С���� 
	T* oldElem = _elem; _elem = new T[_capacity <<=1]; //�����ӱ� 
	for( int i = 0; i < _size; i++) 
	    _elem[i] = oldElem[i]; //����ԭ�������ݣ�TΪ�������ͣ��������ظ�ֵ��������= ��) 
	delete [] oldElem; //�ͷ�ԭ�ռ� 
}

template <typename T> void Vector<T>::shrink() //װ�����ӹ�Сʱѹ��������ռ�ռ�
{
    if (_capacity<DEFAULT_CAPACITY<<1) return; //����������DEFAULT_CAPACITY����
    if (_size<<2> _capacity) return; //��25%Ϊװ�����ӵ���ֵ
    T* oldElem=_elem; _elem=new T[_capacity>>=1]; //��������
    for (int i=0;i<_size;i++) _elem[i]=oldElem[i]; //����ԭ�������� 
    delete [] oldElem; //�ͷ�ԭ�ռ� 
}

template <typename T> T&Vector<T>::operator[ ](Rank r) const //���������
{ return _elem[r]; } //assert: 0  <= r < _size

template <typename T> void permute ( Vector<T>& V ){ //�������������ʹ��Ԫ�صȸ��ʳ����ڸ�λ��
    for ( int i = V.size(); i > 0; i--) //�Ժ���ǰ
	    swap (V[i - 1], V[rand() % i] ); //V[i-1]��V[0,i)��ĳһ���Ԫ�ؽ��� 
}

template <typename T> void Vector<T>::unsort(Rank lo, Rank hi) { //�ȸ��������������[lo, hi) 
	T* V = _elem + lo; //��������_elem[lo, hi)������һ����V[0,hi-lo) 
	for (Rank i = hi - lo; i > 0; i--) //�Ժ���ǰ 
	    swap( V[i - 1],V[rand() % i] ); //��V[i-1]��[0,i)��ĳһԪ���漴���� 
}

template <typename T> //����������˳����ң��������һ��Ԫ��e��λ�ã�ʧ��ʱ������lo - 1
Rank Vector<T>::find(T const& e, Rank lo, Rank hi) const { //assert: 0 <= lo < hi <= _size
	while ((lo < hi--) && (e != _elem[hi])); //�Ӻ���ǰ��˳�����
	return hi; //��hi < lo������ζ��ʧ�ܣ�����hi������Ԫ�ص���
}
template <typename T>
Rank Vector<T>::intervalSearch (Rank lo,Rank hi, double m, double  n)
{
	int count = 0;
	for(int i=lo;i<hi;i++)
	{
		if(_elem[i]>=m&&_elem[i]<n)
			count++;
	}
	return count;
}

template <typename T>  //��e��Ϊ��Ϊr��Ԫ�ز���
Rank Vector<T>::insert(Rank r, T const& e) { //assert:0<=r<=_size
    expand();  //���б�Ҫ������
    for ( int i=_size;i>r;i-- ) _elem[i]=_elem[i-1];  //�Ժ���ǰ�����Ԫ���Դ˺���һ����Ԫ
    _elem[r]=e;//������Ԫ�� 
	_size++;  //��������
    return r;//������
}

template <typename T> int Vector<T>::remove(Rank lo, Rank hi) { //ɾ������(lo,hi)
    if (lo == hi) return 0; //����Ч�ʿ��ǣ����������˻����������remove(0,0)
    while(hi<_size) _elem[lo++] = _elem[hi++]; //[hi,_size]����ǰ��hi-lo����Ԫ
	_size=_size-hi+lo;//���¹�ģ
	shrink();//���б�Ҫ������
	return hi-lo;//���ر�ɾ��Ԫ����Ŀ
}

template <typename T> T Vector<T>::remove(Rank r) { //ɾ����������Ϊr��Ԫ��
	T e = _elem[r];//����ɾ��Ԫ��
	remove(r,r+1); //ɾ��rԪ�ص�Ч�ڶ�����(r,r+1)��ɾ��
	return e;
}

template <typename T> int Vector<T>::deduplicate(){
    int oldSize=_size;//��¼ԭ��ģ
    Rank i=1;//��elem[1]��ʼ
    while(i<_size)  //��ǰ�����һ���Ǹ�Ԫ��_elem[i]
        (find(_elem[i],0,i)<0)? //��ǰ׺��Ѱ����_elem[i]����ͬ�ߣ�������ֻ��һ����
		i++ : remove(i) ; //��û���ҵ�����������̣���i��һ��������ɾ����ͬ��
    return oldSize - _size;//���ر�ɾ��Ԫ�ظ���
}

template <typename T>
void Vector<T>::traverse ( void ( *visit )( T& )) //��������ָ�����
{   for (int i = 0; i < _size; i++) visit ( _elem[i] ); } //��������

template <typename T> template <typename VST> //Ԫ�����͡�������
void Vector<T>::traverse ( VST& visit ) //���������������
{   for ( int i = 0; i < _size; i++ ) visit ( _elem[i] ); } // ��������

template <typename T> struct Increase //�������󣺵���һ��T�����
	{   virtual void operator() ( T&e ) {e++;}}; //����T��ֱ�ӵ�����������++
	
template <typename T> void increase ( Vector<T> & V ) //ͳһ���������еĸ�Ԫ��
{   V.traverse(Increase<T>());} //��Increase<T>()Ϊ�����������б���

template <typename T> int Vector<T>::disordered() const { //������������������Ԫ�ضԵ�����
    int n = 0; //������
	for ( int i = 1; i < _size; i++ ) //��һ���_size-1������Ԫ��
		if ( _elem[i - 1] > _elem[i] ) n++; //��������� 
	return n; //���������ҽ���n=0;     
}

template <typename T> int Vector<T>::uniquify() { //���������ظ�Ԫ���޳��㷨����Ч�棩
	Rank i = 0, j = 0; //���Ի��조���ڡ�Ԫ�ص��� 
	while ( ++j < _size ) //��һɨ�裬ֱ��ĩԪ�� 
		if( _elem[i] != _elem[j] ) //������ͬ�� 
			_elem[++i] = _elem[j]; //���ֲ�ͬԪ��ʱ����ǰ����������ǰ���Ҳ� 
	_size = ++i; shrink(); //ֱ�ӽس�β������Ԫ�� 
	return j - 1; //������ģ�仯��������ɾ��Ԫ������
}

template <typename T> //����������������[lo,hi)�ڣ�ȷ��������e�����һ���ڵ���� 
Rank Vector<T>::search (T const& e, Rank lo,Rank hi) const{ //assert: 0 <= lo < hi <= _size  
	return (rand() % 2) ? //����50%�ĸ������ʹ�ö��ֲ��һ�Fibonacci���� 
			binSearch ( _elem, e, lo, hi ) : fibSearch ( _elem, e, lo, hi );
} 

//���ֲ����㷨���汾B��������������������[lo,hi)�ڲ���Ԫ��e��0 <= lo < hi <= _size
template <typename T> static Rank binSearch (T* A, T const& e, Rank lo, Rank hi){
	while (1 < hi - lo) { //ÿ������������һ�αȽ��жϣ���������֧���ɹ����Ҳ�����ǰ��ֹ 
		Rank mi = (lo + hi) >> 1; //���е�Ϊ��� 
		(e < A[mi]) ? hi = mi : lo = mi; //���ȽϺ�ȷ������[lo,mi)��[mi,hi) 
    } //����ʱhi = lo + 1,�����������һ��Ԫ��A[lo] 
    return (e == A[lo]) ? lo : -1; //���ҳɹ�ʱ���ض�Ӧ���ȣ�����ͳһ����-1 
} //�ж������Ԫ��ʱ�����ܱ�֤����������ߣ�����ʧ��ʱ���򵥵ط���-1��������ָʾʧ�ܵ�λ��


template <typename T> //��������������
void Vector <T>::bubbleSort (Rank lo, Rank hi) //assert: 0 <= lo < hi <= size
{while ( !bubble (lo, hi--) ); } //������ɨ�轻����ֱ��ȫ��
template <typename T> //��������������
void Vector <T>::bubbleSort (Rank n, Rank lo, Rank hi) //assert: 0 <= lo < hi <= size
{while ( !bubble (n, lo, hi--) ); } //������ɨ�轻����ֱ��ȫ��

template <typename T> bool Vector<T>::bubble(Rank lo, Rank hi){ //һ��ɨ�轻�� 
	bool sorted = true; //���������־ 
	while ( ++lo < hi) //�������ң���һ����������Ԫ�� 
		if ( _elem[lo - 1] > _elem[lo] ){ //�������� 
			sorted = false; //��ζ����δ�������򣬲���Ҫ 
			swap ( _elem[lo - 1], _elem[lo] ); //ͨ������ʹ�ֲ����� 
		}
	return sorted; //���������־ 
}
template <typename T> bool Vector<T>::bubble(Rank n,  Rank lo, Rank hi){ 
	bool sorted = true;//һ��ɨ�轻�� 
	if(n==-1)
	{	 //���������־ 
	while ( ++lo < hi) //�������ң���һ����������Ԫ�� 
		if ( _elem[lo - 1] < _elem[lo] ){ //�������� 
			sorted = false; //��ζ����δ�������򣬲���Ҫ 
			swap ( _elem[lo - 1], _elem[lo] ); //ͨ������ʹ�ֲ����� 
		}
	}
	return sorted; //���������־ 
}

template <typename T> //�����鲢����
void Vector<T>::mergeSort (Rank lo, Rank hi){ //0 <= lo < hi <= size
	if (hi - lo < 2) return; //��Ԫ��������Ȼ���򣬷��� 
	int mi = (lo + hi) / 2; //���е�Ϊ�� 
	mergeSort (lo, mi); mergeSort (mi, hi); //�ֱ����� 
	merge (lo, mi, hi); //�鲢 
} 

template <typename T> //���������Ĺ鲢
void Vector<T>::merge (Rank lo, Rank mi, Rank hi) {
	T* A = _elem + lo;
	int lb = mi - lo; T* B = new T[lb];
	for ( Rank i = 0 ; i < lb ; B[i] = A[i++] );
	int lc = hi - mi; T* C = _elem + mi;
	for ( Rank i = 0,j = 0,k = 0;(j < lb)||(k < lc);){
		if((j < lb)&&(!(k < lc)||(B[j] <= C[k]))) A[i++] = B[j++];
		if((k < lc)&&(!(j < lb)||(C[k] <  B[j]))) A[i++] = C[k++];
	}
}
template <typename T> 
T* Vector<T>::check2(Rank lo, Rank hi, double m1, double m2){
	int count=0;
	T* temp = new T[hi-lo];
	for(int i=lo;i<hi;i++)
	{
		if(_elem[i]>=m1 && _elem[i]<m2)
			temp[count++]=_elem[i];
	}

	for(int i=count;i<hi;i++)
		temp[i]='\0';
	return temp;
}



