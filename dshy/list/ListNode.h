#ifndef LISTNODE
#define LISTNODE
#include <cstddef>

#define ListNodePosi(T) ListNode<T>*
typedef int Rank;

template <typename T>
struct ListNode	{
	
	T data;                                                   //������ 
	ListNodePosi(T) pred;                                     //ֱ��ǰ��ָ�� 
	ListNodePosi(T) succ;                                     //ֱ�Ӻ��ָ�� 
	
	ListNode() {}                                             //Ĭ�Ϲ��캯�� ���header��trailer�ڵ�Ĺ��� Ĭ��ΪNULL 
	ListNode(T e, ListNodePosi(T) p = NULL, ListNodePosi(T) s = NULL):data(e), pred(s), succ(s) {}
	
	ListNodePosi(T) insertAsPred(const T &e);                 //�ڵ�ǰ�ڵ�ǰ�����½ڵ� 
	ListNodePosi(T) insertAsSucc(const T &e);                 //�ڵ�ǰ�ڵ������½ڵ� 
	
};

#endif 
