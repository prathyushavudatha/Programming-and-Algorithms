#ifndef BST
#define BST

#define EMPTY 0

typedef struct
{
int value;
}Data;

typedef struct node
{
Data data;
struct node *left;
struct node *right;
struct node *parent;
}Node;

typedef struct Tree
{
Node * root;
Data *(*insert)(struct Tree *bst,Data value);
Data *(*search)(struct Tree *bst,Data value);
void (*sort)(struct Tree *t,Data *d);
void (*inOrder)(struct Node *n,Data *data);
void (*removeData)(struct Tree *bst,Data value);
struct Tree *(*clone)(struct Tree *t);
int (*compare)(struct Tree *t,struct Tree *copy);
void (*delete)(struct Tree *bst);


}Tree;

Node *newNode(Data d,Node *parent);
Tree *newTree();


Data *insert(Tree *bst,Data value);
Data *insertNode(Node *node,Data value);
Data *search(Tree *bst,Data value);
Node *searchNode(Node *node,Data value);
void sort(Tree *t,Data *d);
void inOrder(Node *n,Data *data);
void removeData(Tree *bst,Data value);
void removeLeaf(Tree *bst,Node *d_node);
void shortCircuit(Tree *bst,Node *d_node);
void promotion(Tree *bst,Node *d_node);
Tree *clone(Tree *t);
void cloneTree(Node *n,Tree *t);
int compare(Tree *t,Tree *copy);
int compareTreeNodes(Node *m,Node *c);
void deleteTree(Tree *bst);
void freeTree(Node *rootNode);

#endif
