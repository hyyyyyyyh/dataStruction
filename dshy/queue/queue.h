#include "../List/List.h" //��ListΪ���� 
template <typename T> class queue: public List<T> { //����ģ����(�̳�Listԭ�нӿ�) 
public: //size()��empty()�Լ��������Žӿھ���ֱ������ 
	void enqueue ( T const& e ) { this->insertAslast ( e ); } //��ӣ�β������ 
	T dequeue() { return this->remove ( this->first() ); } //���ӣ��ײ�ɾ�� 
	T& front() { return this->first()->data; } //���� 
};

