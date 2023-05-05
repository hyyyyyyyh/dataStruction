#include<iostream>
#include <stdlib.h>
#define BinNodePosi(T) BinNode<T>* //�ڵ�λ�� 
#define stature(p) ((p) ? (p)->height: -1) //�ڵ�߶�
//#define NULL 0 
typedef enum { RB_RED, RB_BLACK } RBColor; //�ڵ���ɫ
template <typename T> struct BinNode{
	T data;
	BinNodePosi(T) parent;
	BinNodePosi(T) lc;
	BinNodePosi(T) rc; //���ס�����
	int height;  //�߶ȡ�������ģ
	int npl; //Null Path Length(��ʽ�ѣ�Ҳ����ֱ����height����)
	RBColor color; //��ɫ(�����)
 //���캯��
    BinNode():
        parent( NULL ), lc( NULL ),rc( NULL ),height ( 0 ),npl( 1 ),color ( RB_RED ) {}
    BinNode( T e, BinNodePosi(T) p = NULL, BinNodePosi(T) lc = NULL, BinNodePosi(T) rc = NULL, int h = 0, int l = 1, RBColor c = RB_RED):
        data( e ), parent( p ), lc( lc ), rc( rc ),height ( h ),npl( 1 ),color ( c ) {}
//�����ӿ� 
    int size();
	BinNodePosi(T) insertAsLC( T const & ); //��Ϊ���Ӳ����½ڵ�
	BinNodePosi(T) insertAsRC( T const & ); //��Ϊ�Һ��Ӳ����½ڵ�
	BinNodePosi(T) succ(); //��������������£���ǰ�ڵ��ֱ�Ӻ��
	template <typename VST> void travLevel(VST &); //������α���
	template <typename VST> void travPre(VST &); //�����������
	template <typename VST> void travIn(VST &); //�����������
	template <typename VST> void travPost(VST &); //�����������
//�Ƚ������е���
	bool operator < (BinNode const& bn) { return  data < bn.data; } 
	bool operator > (BinNode const& bn) { return  data > bn.data; }
	bool operator<= (BinNode const& bn) { return  data <= bn.data; }
	bool operator>= (BinNode const& bn) { return  data >= bn.data; }
	bool operator!= (BinNode const& bn) { return  data != bn.data; }
	bool operator== (BinNode const& bn) { return  data == bn.data; }
};

#define IsRoot(x) (!((x).parent))
#define IsLChild(x) (!IsRoot(x) && (&(x)==(x).parent->lc))
#define IsRChild(x) (!IsRoot(x) && (&(x)==(x).parent->rc))
#define HasParent(x) (!IsRoot(x))
#define HasLChild(x) ((x).lc)
#define HasRChild(x) ((x).rc)
#define HasChild(x) (HasLChild(x) || HasRChild(x))	//����ӵ��һ������
#define HasBothChild(x) (HasLChild(x) && HasRChild(x))	//ͬʱӵ����������
#define IsLeaf(x) (!HasChild(x))
/************************************************************************************
*��BinNode�����ض���ϵ�Ľڵ㼰ָ��
*************************************************************************************/
#define sibling(p) (IsLChild(*(p))?(p)->parent->rc:(p)->parent->lc)	//�ֵ�
#define uncle(x) sibling((x)->parent)	//����
#define FromParentTo(x) /*���Ը��׵�����*/\
	(IsRoot(x)?_root:(IsLChild(x)?(x).parent->lc:(x).parent->rc))
 
#define IsBlack(p) (!(p) || (RB_BLACK == (p)->color))	//�ⲿ�ڵ�Ҳ�����ڽڵ�
#define IsRed(p) (!IsBlack(p))	//�Ǻڼ���
#define BlackHeightUpdated(x) (/*RedBlack�߶ȸ�������*/ \
	(stature((x).lc)==stature((x).rc)) && \
	((x).height == (IsRed(&x)?stature((x).lc):stature((x).lc)+1)) \
)

//��Ϊ���Ӳ���
template <typename T> BinNodePosi(T) BinNode<T>::insertAsLC(T const &e)
	{return lc = new BinNode( e, this);}
//��Ϊ�Һ��Ӳ���
template <typename T> BinNodePosi(T) BinNode<T>::insertAsRC(T const &e)
	{return rc = new BinNode( e, this);}


 template <typename T> template <typename VST>//Ԫ�����Ͳ�����
 void BinNode<T>::travIn(VST& visit){//�������������ͳһ���
    //switch( rand() % 5)
	switch(4){
    case 1:travIn_I1(this,visit);break;
    case 2:travIn_I2(this,visit);break;
    case 3:travIn_I3(this,visit);break;
    case 4:travIn_I4(this,visit);break;
    default:travIn_R(this,visit);break;
    }
 }
template <typename T>
int BinNode<T>::size(){
	int s = 1;//���뱾��
	if (lc) s += lc->size();
	if (rc) s += rc->size();
	return s;
}




