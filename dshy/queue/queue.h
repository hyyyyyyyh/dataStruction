#include "../List/List.h" //以List为基类 
template <typename T> class queue: public List<T> { //队列模板类(继承List原有接口) 
public: //size()、empty()以及其它开放接口均可直接沿用 
	void enqueue ( T const& e ) { this->insertAslast ( e ); } //入队：尾部插入 
	T dequeue() { return this->remove ( this->first() ); } //出队：首部删除 
	T& front() { return this->first()->data; } //队首 
};

