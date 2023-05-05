#include<iostream>
#include <stdlib.h>
#define BinNodePosi(T) BinNode<T>* //节点位置 
#define stature(p) ((p) ? (p)->height: -1) //节点高度
//#define NULL 0 
typedef enum { RB_RED, RB_BLACK } RBColor; //节点颜色
template <typename T> struct BinNode{
	T data;
	BinNodePosi(T) parent;
	BinNodePosi(T) lc;
	BinNodePosi(T) rc; //父亲、孩子
	int height;  //高度、子树规模
	int npl; //Null Path Length(左式堆，也可以直接用height代替)
	RBColor color; //颜色(红黑树)
 //构造函数
    BinNode():
        parent( NULL ), lc( NULL ),rc( NULL ),height ( 0 ),npl( 1 ),color ( RB_RED ) {}
    BinNode( T e, BinNodePosi(T) p = NULL, BinNodePosi(T) lc = NULL, BinNodePosi(T) rc = NULL, int h = 0, int l = 1, RBColor c = RB_RED):
        data( e ), parent( p ), lc( lc ), rc( rc ),height ( h ),npl( 1 ),color ( c ) {}
//操作接口 
    int size();
	BinNodePosi(T) insertAsLC( T const & ); //作为左孩子插入新节点
	BinNodePosi(T) insertAsRC( T const & ); //作为右孩子插入新节点
	BinNodePosi(T) succ(); //（中序遍历意义下）当前节点的直接后继
	template <typename VST> void travLevel(VST &); //子树层次遍历
	template <typename VST> void travPre(VST &); //子树先序遍历
	template <typename VST> void travIn(VST &); //子树中序遍历
	template <typename VST> void travPost(VST &); //子树后序遍历
//比较器、判等器
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
#define HasChild(x) (HasLChild(x) || HasRChild(x))	//至少拥有一个孩子
#define HasBothChild(x) (HasLChild(x) && HasRChild(x))	//同时拥有两个孩子
#define IsLeaf(x) (!HasChild(x))
/************************************************************************************
*与BinNode具有特定关系的节点及指针
*************************************************************************************/
#define sibling(p) (IsLChild(*(p))?(p)->parent->rc:(p)->parent->lc)	//兄弟
#define uncle(x) sibling((x)->parent)	//叔叔
#define FromParentTo(x) /*来自父亲的引用*/\
	(IsRoot(x)?_root:(IsLChild(x)?(x).parent->lc:(x).parent->rc))
 
#define IsBlack(p) (!(p) || (RB_BLACK == (p)->color))	//外部节点也视作黑节点
#define IsRed(p) (!IsBlack(p))	//非黑即红
#define BlackHeightUpdated(x) (/*RedBlack高度更新条件*/ \
	(stature((x).lc)==stature((x).rc)) && \
	((x).height == (IsRed(&x)?stature((x).lc):stature((x).lc)+1)) \
)

//作为左孩子插入
template <typename T> BinNodePosi(T) BinNode<T>::insertAsLC(T const &e)
	{return lc = new BinNode( e, this);}
//作为右孩子插入
template <typename T> BinNodePosi(T) BinNode<T>::insertAsRC(T const &e)
	{return rc = new BinNode( e, this);}


 template <typename T> template <typename VST>//元素类型操作器
 void BinNode<T>::travIn(VST& visit){//二叉树中序遍历统一入口
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
	int s = 1;//计入本身
	if (lc) s += lc->size();
	if (rc) s += rc->size();
	return s;
}




