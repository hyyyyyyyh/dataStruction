#include "BinNode.h" //����������ڵ���
#include "../queue/queue.h"
#include "../Stack/Stack.h"
template <typename T> class BinTree {
protected:
	int _size;//��ģ
	virtual int updateHeight( BinNodePosi(T) x); //���½ڵ�x�ĸ߶�
	void updateHeightAbove( BinNodePosi(T) x); //����x�����ȵĸ߶�
public:
	public:
	BinNodePosi(T) _root; //���ڵ�
    BinTree(): _size( 0 ), _root ( NULL ) {} //���캯��
    ~BinTree(){ if ( 0 < _size ) remove ( _root );} //�������� 
	int size() const { return _size; } //��ģ 
	bool empty() const { return _root; } //�п� 
	BinNodePosi(T) root() const { return _root; } //���� 
	BinNodePosi(T) insertAsRoot ( T const& e ); //������ڵ� 
	BinNodePosi(T) insertAsLC( BinNodePosi(T) x, T const& e ); //e��Ϊx������(ԭ��)����
	BinNodePosi(T) insertAsRC( BinNodePosi(T) x, T const& e ); //e��Ϊx���Һ���(ԭ��)����
	BinNodePosi(T) attachAsLC( BinNodePosi(T) x,BinTree<T>* &S); //T��Ϊx���������� 
	BinNodePosi(T) attachAsRC( BinNodePosi(T) x,BinTree<T>* &S); //T��Ϊx���������� 
	int remove ( BinNodePosi(T) x ); //ɾ����λ��x���ڵ�Ϊ�������������ظ�����ԭ�ȵĹ�ģ
	BinTree<T>* secede (BinNodePosi(T) x ); //������x�ӵ�ǰ����ժ����������ת��Ϊһ����������
	template <typename VST> //������
	void travLevel ( VST& visit ) { if ( _root ) _root->travLevel ( visit ); } //��α���
	template <typename VST> //������
	void travPre ( VST& visit ) { if ( _root ) _root->travPre ( visit ); } //�������
	template <typename VST> //������
	void travIn ( VST& visit ) { if ( _root ) _root->travIn ( visit ); } //�������
	template <typename VST> //������
	void travPost ( VST& visit ) { if ( _root ) _root->travPost ( visit ); } //�������
	bool operator< (BinTree<T> const& t ) //С�� 
	{ return _root && t._root && lt ( _root, t._root ); }
	bool operator> (BinTree<T> const& t ) //���� 
	{ return _root && t._root && lt ( _root, t._root ); }
	bool operator== (BinTree<T> const& t ) //���� 
	{ return _root && t._root && ( _root == t._root ); }
	bool operator!= (BinTree<T> const& t ) //������ 
	{ return _root && t._root && ( _root != t._root ); }
	bool operator<= (BinTree<T> const& t ) //С�� 
	{ return _root && t._root && lt ( _root, t._root ); }
	bool operator>= (BinTree<T> const& t ) //С�� 
	{ return _root && t._root && lt ( _root, t._root ); }
}; 
template <typename T> int BinTree<T>::updateHeight ( BinNodePosi(T) x ) //���½ڵ�x�߶�
{ return x->height = 1 + max ( stature ( x->lc ), stature ( x->rc ) ); } //���������������

template <typename T> void BinTree<T>::updateHeightAbove (BinNodePosi(T) x ) //���¸߶�
{ while ( x ) { updateHeight ( x ); x = x->parent; } } //��x�����������������ȡ����Ż� 

template <typename T> BinNodePosi(T) BinTree<T>::insertAsRoot(T const& e)
{
	_size = 1; return _root = new BinNode<T> (e);
} //��e�������ڵ����յĶ�����

template <typename T> BinNodePosi(T) BinTree<T>::insertAsLC(BinNodePosi(T) x,T const& e)
{
	_size++; x->insertAsLC(e); updateHeightAbove(x); return x->lc;
} //e����Ϊx������

template <typename T> BinNodePosi(T) BinTree<T>::insertAsRC(BinNodePosi(T) x,T const& e)
{
	_size++; x->insertAsRC(e); updateHeightAbove(x); return x->rc;
} //e����Ϊx���Һ��� 

template <typename T> //���������������㷨��S��Ϊ�ڵ�x�����������룬S�����ÿ�
BinNodePosi(T) BinTree<T>::attachAsLC(BinNodePosi(T) x, BinTree<T>* &S)
{ //x->lc == NULL 
	if( x->lc = S->_root ) x->lc->parent = x; //���� 
	_size += S->_size; updateHeightAbove(x); //����ȫ����ģ��x�������ȵĸ߶� 
	S->_root = NULL; S->_size= 0; releases(S); S = NULL; return x; //�ͷ�ԭ�������ؽ���λ�� 
} 

template <typename T> //���������������㷨��S��Ϊ�ڵ�x�����������룬S�����ÿ�
BinNodePosi(T) BinTree<T>::attachAsRC(BinNodePosi(T) x, BinTree<T>* &S)
{ //x->rc == NULL 
	if( x->rc = S->_root ) x->rc->parent = x; //���� 
	_size += S->_size; updateHeightAbove(x); //����ȫ����ģ��x�������ȵĸ߶� 
	S->_root = NULL; S->_size = 0; releases(S); S = NULL; return x; //�ͷ�ԭ�������ؽ���λ�� 
} 

template <typename T> //������ɾ��x�ڵ㼰����
int BinTree<T>::remove(BinNodePosi(T) x) //assert��xΪ�������еĺϷ�λ�� 
{
	FromParentTo( *x ) = NULL; //�ж����Ը��ڵ��ָ�� 
	updateHeightAbove ( x->parent ); //�������ȸ߶� 
	int n = removeAt( x ); _size -= n; return n; //ɾ������x�����¹�ģ������ɾ���ڵ����� 
}

template <typename T> //ɾ��x�ڵ㼰����������ɾ���ڵ���
static int removeAt(BinNodePosi(T) x) //assert��xΪ�������еĺϷ�λ�� 
{
	if ( !x ) return 0; //�ݹ�������� 
	int n = 1 + removeAt ( x->lc ) + removeAt( x->rc );
	release( x->data ); release( x ); return n; //�ͷű�ժ���ڵ㣬������ɾ���ڵ����� 
}

template <typename T> //���������������㷨��������x�ӵ�ǰ����ժ����������ת��Ϊһ���������� 
BinTree<T>* BinTree<T>::secede (BinNodePosi(T) x ) //assert��xΪ�������еĺϷ�λ��  
{
	FromParentTo( *x ) = NULL; //�ж����Ը��ڵ��ָ�� 
	updateHeightAbove ( x->parent ); //�������ȸ߶� 
	BinTree<T>* S = new BinTree<T>; S->_root = x; x->parent = NULL; //������xΪ��
	S->_size = x->size(); _size -= S->_size; return S; //���¹�ģ�����ط������������ 
}
//�������
template <typename T, typename VST> void travPre(BinNodePosi(T) x, VST& visit) {
	if( !x ) return;
	visit( x->data );
	travPre_R( x->lc, visit );
	travPre_R( x->rc, visit );
}
//�������
template <typename T, typename VST> void travPost(BinNodePosi(T) x, VST& visit) {
	if( !x ) return;
	travPost( x->lc, visit );
	travPost( x->rc, visit );
	visit( x->data );
}
//�������
template <typename T, typename VST> void travIn(BinNodePosi(T) x, VST& visit) {
	if( !x ) return;
	travIn( x->lc, visit );
	visit( x->data );
	travIn( x->rc, visit );
}

template <typename T> BinNodePosi(T) BinNode<T>::succ(){ //��λ�ڵ�v��ֱ�Ӻ�� 
	BinNodePosi(T) s = this; //��¼��̵���ʱ����
	if( rc ) { //�����Һ��ӣ���ֱ�Ӻ�̱����������У�����ؾ���
	  s = rc; //��������
	  while ( HaslChild ( *s )) s = s->lc; //���(��С���Ľڵ�
	} else { //����ֱ�Ӻ��Ӧ�ǡ�����ǰ�ڵ���������������е�������ȡ�������ؾ���
	   while ( IsRChild ( *s )) s = s->parent; //������������֧�����ϳ����Ϸ��ƶ�
	   s = s->parent; //����ٳ����Ϸ��ƶ�һ�������ִ�ֱ�Ӻ��(�������) 
	} 
	return s;
}

//��α���
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
void travIn_I1 (BinNodePosi(T) x, VST& visit)//������������� 
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
void travIn_I2 (BinNodePosi(T) x, VST& visit)//������������� 
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
void travIn_I3 (BinNodePosi(T) x, VST& visit)//������������� 
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


