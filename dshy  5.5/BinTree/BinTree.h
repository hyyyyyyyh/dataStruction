#include "BinNode.h" //引入二叉树节点类
#include "../queue/queue.h"
#include "../Stack/Stack.h"
template <typename T> class BinTree {
protected:
	int _size;//规模
	virtual int updateHeight( BinNodePosi(T) x); //更新节点x的高度
	void updateHeightAbove( BinNodePosi(T) x); //更新x及祖先的高度
public:
	public:
	BinNodePosi(T) _root; //根节点
    BinTree(): _size( 0 ), _root ( NULL ) {} //构造函数
    ~BinTree(){ if ( 0 < _size ) remove ( _root );} //析构函数 
	int size() const { return _size; } //规模 
	bool empty() const { return _root; } //判空 
	BinNodePosi(T) root() const { return _root; } //树根 
	BinNodePosi(T) insertAsRoot ( T const& e ); //插入根节点 
	BinNodePosi(T) insertAsLC( BinNodePosi(T) x, T const& e ); //e作为x的左孩子(原无)插入
	BinNodePosi(T) insertAsRC( BinNodePosi(T) x, T const& e ); //e作为x的右孩子(原无)插入
	BinNodePosi(T) attachAsLC( BinNodePosi(T) x,BinTree<T>* &S); //T作为x左子树接入 
	BinNodePosi(T) attachAsRC( BinNodePosi(T) x,BinTree<T>* &S); //T作为x右子树接入 
	int remove ( BinNodePosi(T) x ); //删除以位置x处节点为根的子树，返回该子树原先的规模
	BinTree<T>* secede (BinNodePosi(T) x ); //将子树x从当前树中摘除，并将其转换为一根独立子树
	template <typename VST> //操作器
	void travLevel ( VST& visit ) { if ( _root ) _root->travLevel ( visit ); } //层次遍历
	template <typename VST> //操作器
	void travPre ( VST& visit ) { if ( _root ) _root->travPre ( visit ); } //先序遍历
	template <typename VST> //操作器
	void travIn ( VST& visit ) { if ( _root ) _root->travIn ( visit ); } //中序遍历
	template <typename VST> //操作器
	void travPost ( VST& visit ) { if ( _root ) _root->travPost ( visit ); } //后序遍历
	bool operator< (BinTree<T> const& t ) //小于 
	{ return _root && t._root && lt ( _root, t._root ); }
	bool operator> (BinTree<T> const& t ) //大于 
	{ return _root && t._root && lt ( _root, t._root ); }
	bool operator== (BinTree<T> const& t ) //等于 
	{ return _root && t._root && ( _root == t._root ); }
	bool operator!= (BinTree<T> const& t ) //不等于 
	{ return _root && t._root && ( _root != t._root ); }
	bool operator<= (BinTree<T> const& t ) //小于 
	{ return _root && t._root && lt ( _root, t._root ); }
	bool operator>= (BinTree<T> const& t ) //小于 
	{ return _root && t._root && lt ( _root, t._root ); }
}; 
template <typename T> int BinTree<T>::updateHeight ( BinNodePosi(T) x ) //更新节点x高度
{ return x->height = 1 + max ( stature ( x->lc ), stature ( x->rc ) ); } //具体规则，因树而异

template <typename T> void BinTree<T>::updateHeightAbove (BinNodePosi(T) x ) //更新高度
{ while ( x ) { updateHeight ( x ); x = x->parent; } } //从x出发，覆盖历代祖先。可优化 

template <typename T> BinNodePosi(T) BinTree<T>::insertAsRoot(T const& e)
{
	_size = 1; return _root = new BinNode<T> (e);
} //将e当作根节点插入空的二叉树

template <typename T> BinNodePosi(T) BinTree<T>::insertAsLC(BinNodePosi(T) x,T const& e)
{
	_size++; x->insertAsLC(e); updateHeightAbove(x); return x->lc;
} //e插入为x的左孩子

template <typename T> BinNodePosi(T) BinTree<T>::insertAsRC(BinNodePosi(T) x,T const& e)
{
	_size++; x->insertAsRC(e); updateHeightAbove(x); return x->rc;
} //e插入为x的右孩子 

template <typename T> //二叉树子树接入算法：S作为节点x的左子树插入，S本身被置空
BinNodePosi(T) BinTree<T>::attachAsLC(BinNodePosi(T) x, BinTree<T>* &S)
{ //x->lc == NULL 
	if( x->lc = S->_root ) x->lc->parent = x; //接入 
	_size += S->_size; updateHeightAbove(x); //更新全树规模与x所有祖先的高度 
	S->_root = NULL; S->_size= 0; releases(S); S = NULL; return x; //释放原树，返回接入位置 
} 

template <typename T> //二叉树子树接入算法：S作为节点x的右子树插入，S本身被置空
BinNodePosi(T) BinTree<T>::attachAsRC(BinNodePosi(T) x, BinTree<T>* &S)
{ //x->rc == NULL 
	if( x->rc = S->_root ) x->rc->parent = x; //接入 
	_size += S->_size; updateHeightAbove(x); //更新全树规模与x所有祖先的高度 
	S->_root = NULL; S->_size = 0; releases(S); S = NULL; return x; //释放原树，返回接入位置 
} 

template <typename T> //二叉树删除x节点及其后代
int BinTree<T>::remove(BinNodePosi(T) x) //assert：x为二叉树中的合法位置 
{
	FromParentTo( *x ) = NULL; //切断来自父节点的指针 
	updateHeightAbove ( x->parent ); //更新祖先高度 
	int n = removeAt( x ); _size -= n; return n; //删除子树x，更新规模，返回删除节点总数 
}

template <typename T> //删除x节点及其后代，返回删除节点数
static int removeAt(BinNodePosi(T) x) //assert：x为二叉树中的合法位置 
{
	if ( !x ) return 0; //递归基：空树 
	int n = 1 + removeAt ( x->lc ) + removeAt( x->rc );
	release( x->data ); release( x ); return n; //释放被摘除节点，并返回删除节点总数 
}

template <typename T> //二叉树子树分离算法：将子树x从当前树中摘除，并将其转换为一根独立子树 
BinTree<T>* BinTree<T>::secede (BinNodePosi(T) x ) //assert：x为二叉树中的合法位置  
{
	FromParentTo( *x ) = NULL; //切断来自父节点的指针 
	updateHeightAbove ( x->parent ); //更新祖先高度 
	BinTree<T>* S = new BinTree<T>; S->_root = x; x->parent = NULL; //新树以x为根
	S->_size = x->size(); _size -= S->_size; return S; //更新规模，返回分离出来的子树 
}
//先序遍历
template <typename T, typename VST> void travPre(BinNodePosi(T) x, VST& visit) {
	if( !x ) return;
	visit( x->data );
	travPre_R( x->lc, visit );
	travPre_R( x->rc, visit );
}
//后序遍历
template <typename T, typename VST> void travPost(BinNodePosi(T) x, VST& visit) {
	if( !x ) return;
	travPost( x->lc, visit );
	travPost( x->rc, visit );
	visit( x->data );
}
//中序遍历
template <typename T, typename VST> void travIn(BinNodePosi(T) x, VST& visit) {
	if( !x ) return;
	travIn( x->lc, visit );
	visit( x->data );
	travIn( x->rc, visit );
}

template <typename T> BinNodePosi(T) BinNode<T>::succ(){ //定位节点v的直接后继 
	BinNodePosi(T) s = this; //记录后继的临时变量
	if( rc ) { //若有右孩子，则直接后继必在右子树中，具体地就是
	  s = rc; //右子树中
	  while ( HaslChild ( *s )) s = s->lc; //最靠左(最小）的节点
	} else { //否则，直接后继应是“将当前节点包含于其左子树中的最低祖先”，具体地就是
	   while ( IsRChild ( *s )) s = s->parent; //逆向地沿右向分支，不断朝左上方移动
	   s = s->parent; //最后再朝右上方移动一步，即抵达直接后继(如果存在) 
	} 
	return s;
}

//层次遍历
template <typename T> template <typename VST> void BinNode<T>::travLevel ( VST& visit){
	Queue<BinNodePosi(T)> Q;
	Q.enqueue( this );
	while( !Q.empty()){
		BinNodePosi(T) x = Q.dequeue();visit( x->data);
		if( HasLChild(*x )) Q.enqueue( x->lc );
		if( HasRChild(*x )) Q.enqueue( x->rc );
	}
}

template <typename T, typename VST>
static void visitAlongLeftBranch( BinNodePosi(T) x, VST& visit, Stack<BinNodePosi(T)>& S) {
	while( x ) {
		visit( x->data );
		S.push( x->rc );
		x = x->lc;
	}
}

template <typename T, typename VST>
void travPre_I2( BinNodePosi(T) x, VST& visit ) {
	Stack<BinNodePosi(T)> S;
	while(true) {
		visitAlongLeftBranch(x, visit, S);
		if( S.empty() ) break;
		x = S.pop();
	}
}


template <typename T>
static void goAlongLeftBranch( BinNodePosi(T) x, Stack<BinNodePosi(T)>& S) {
	while( x ) {
		S.push( x );
		x = x->lc;
	}
}

template <typename T, typename VST>
void travIn_I1 (BinNodePosi(T) x, VST& visit)//迭代版中序遍历 
{
	Stack<BinNodePosi(T)> S;//support stack
	while( true )
	{
		goAlongLeftBranch( x, S );
		if( S.empty() ) break;
		x = S.pop();
		visit ( x->data );
		x = x->rc;
	}
}

template <typename T, typename VST>
void travIn_I2 (BinNodePosi(T) x, VST& visit)//迭代版中序遍历 
{
	Stack<BinNodePosi(T)> S;//support stack
	while( true )
	
		if( x ){
			S.push( x );
			x = x->lc;
		} else if( !S.empty() ){
			x = S.pop();
			visit( x->data );
			x = x->rc;
		} else 
			break;
	
}

template <typename T, typename VST>
void travIn_I3 (BinNodePosi(T) x, VST& visit)//迭代版中序遍历 
{
	bool backtrack = false;
	while( true )
		if( !backtrack && HasLChild( *x ) )
			x = x->lc;
		else{
			visit(x->data);
			if(HasRChild(*x)){
				x = x->rc;
				backtrack = false;
			}else{
				if(!(x = x->succ())) break;
				backtrack = true;
			}
		}
}


template <typename T>
static void gotoHLVFL (Stack<BinNodePosi(T)>& S) 
{
	while( BinNodePosi(T) x = S.top())
		if( HasLChild( *x )){
			if( HasRChild( *x ) ) S.push( x->rc );
			S.push( x->lc );
		} else
			S.push( x->rc );
	S.pop();
}

template <typename T, typename VST>
void travPost_I(BinNodePosi(T) x, VST& visit){
	Stack<BinNodePosi(T)> S;
	if( x ) S.push( x );
	while( !S.empty( ) ){
		if(S.top()!=x->parent)
			gotoHLVFL( S );
		x = S.pop(); visit( x-> data);
	}
}


