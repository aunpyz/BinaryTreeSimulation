#include <queue>
#include <stack>
#include <iomanip>
#include <vector>

using namespace std;

#ifndef Binary_Search_Tree
#define Binary_Search_Tree

template<class T> class Tree;

template<class T>
class Node
{
    public:
        Node() { left=right=nullptr; }
        Node(const T& el)
        {
            key=el;
            left=nullptr;
            right=nullptr;
            height = 0;
        }
        T key;
        Node *left, *right;
        int height;
};

template<class T>
class Tree
{
    public:
        Tree() { root = 0; }
        ~Tree() { clear(); }
        void clear() { clear(root); root = 0; }
        bool isEmpty() { return root == 0; }
        void inorder() { inorder(root); }
        void insert(const T& el)
        {
            insert(el, root);
        }
        void addLine(const T& ln);
        void deleteNode(Node<T> *& node);
        //print all nodes in a specific line
        T lineNode(int ln);
        //get list size
        int getListSize()
        {
            return lineList.size();
        }
        int getHeight()
        {
            return root->height;
        }
        void balance()
        {
            balance(root);
        }
        void singleRot_L(Node<T> *&k2){
            Node<T> *k1 = k2->left;
            k2->left = k1->right;
            k1->right = k2;

            k1->height = 1 + max(height(k1->left), height(k1->right));
            k2->height = 1 + max(height(k2->left), height(k2->right));

            k2 = k1;
        }
        void singleRot_R(Node<T> *&k2){
            Node<T> *k1 = k2->right;
            k2->right = k1->left;
            k1->left = k2;

            k1->height = 1 + max(height(k1->left), height(k1->right));
            k2->height = 1 + max(height(k2->left), height(k2->right));

            k2 = k1;
        }
        void doubleRot_L(Node<T> *&k2){
            singleRot_R(k2->left);
            singleRot_L(k2);
        }
        void doubleRot_R(Node<T> *&k2){
            singleRot_L(k2->right);
            singleRot_R(k2);
        }
    protected:
        Node<T> *root;
        vector<T> lineList;
        void clear(Node<T> *p);
        void inorder(Node<T> *p);
        void insert(const T& el, Node<T> *&node);
        int height(Node<T> *&node)
        {
            if(node == nullptr)
                return -1;
            else
                return node->height;
        }
        int max(int left, int right)
        {
            return (left>right)?left:right;
        }
        void balance(Node<T> *&node);
};

template<class T>
void Tree<T>::clear(Node<T> *p)
{
	if (p != 0)
    {
	     clear(p->left);
	     clear(p->right);
	     delete p;
	}
}

template<class T>
void Tree<T>::inorder(Node<T> *p)
{
	//TO DO! This is for an inorder tree traversal!
    if(p != NULL)
    {
        inorder(p->left);
        //cout << p->key << endl;
        int diff = height(p->left)-height(p->right);
        cout<<setw(10)<<p->key <<setw(10)<< p->height<<setw(10)<<((diff<0?diff*-1:diff)>1?"unbalance":"")<<endl;
        inorder(p->right);
    }
}

template<class T>
void Tree<T>::insert(const T &el, Node<T> *&node)
{
    if(isEmpty()){
        node = new Node<T>(el);
    }else{
        if(el > node->key){
            if(node->right == nullptr){
                node->right = new Node<T>(el);
            }else{
                insert(el, node->right);
            }
        }else if(node->key > el){
            if(node->left == nullptr){
                node->left = new Node<T>(el);
            }else{
                insert(el, node->left);
            }
        }
    }

    node->height = 1 + max(height(node->left), height(node->right));

	/*Node<T> *p = root, *prev = 0;
	while(p != 0)
    {
		prev = p;
		if(p->key < el) p=p->right;
		else p=p->left;
	}
	if(root == 0) root = new Node<T>(el);
	else if(prev->key<el) prev->right = new Node<T>(el);
	else
		prev->left = new Node<T>(el);*/
}

template<class T>
void Tree<T>::deleteNode(Node<T> *&node)
{
	Node<T> *prev, *tmp=node;
	if(node->right == 0) node = node->left;
	else if(node->left == 0) node = node->right;
	else
    {
		tmp = node->left;
		prev = node;
		while(tmp->right != 0)
		{
			prev = tmp;
			tmp=tmp->right;
		}
		node->key = tmp->key;
		if(prev == node) prev->left = tmp->left;
		else prev->right = tmp->left;
	}
	delete tmp;
}

//breadth first search **stack **queue
template<class T>
void Tree<T>::addLine(const T& ln)
{
    lineList.push_back(ln);
}

template<class T>
T Tree<T>::lineNode(int ln)
{
    return lineList.at(ln);
}

template<class T>
void Tree<T>::balance(Node<T> *&node)
{
    if(node->left!=0){
        balance(node->left);
    }
    if(node->right!=0){
        balance(node->right);
    }
    while(height(node->left)-height(node->right)>1 || height(node->right)-height(node->left)>1)
    {
        if(height(node->left)-height(node->right)>1){
            if(node->left->right==0){
                singleRot_L(node);
            }else{
                doubleRot_L(node);
            }
            balance(node->left);
            balance(node->right);
        }else if(height(node->right)-height(node->left)>1){
            if(node->right->left==0){
                singleRot_R(node);
            }else{
                doubleRot_R(node);
            }
            balance(node->left);
            balance(node->right);
        }
    }
    node->height = 1 + max(height(node->left), height(node->right));
}

#endif // Binary_Search_Tree
