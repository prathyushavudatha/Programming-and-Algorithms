#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include "bst.h"

Node *newNode(Data d,Node *parent)
{
    Node *n=malloc(sizeof(Node));
    if(n==NULL)
    {
    exit(-1);                                                //memory allocation failed
    }
    n->data=d;
    n->left=NULL;
    n->right=NULL;
    n->parent=NULL;
    return n;
}

Tree *newTree()
{
    Tree *a=malloc(sizeof(Tree));
    if(a==NULL)
    {
    exit(-1);                                                //memory allocation failed
    }
    a->root=NULL;
    a->insert = insert;
    a->search = search;
    a->sort = sort;
    a->delete = deleteTree;
    a->compare = compare;
    a->removeData = removeData;
    a->clone = clone;
    return a;
}

Data *insert(Tree *bst, Data value)                                         //INSERT
{
    if(bst->root==NULL)
    {
    bst->root=newNode(value,NULL);
    }
    else
    {
    return insertNode(bst->root,value);
    }
}


Data *insertNode(Node *node, Data value)
{
    if(value.value < node->data.value )
    {
    if(node->left==NULL)
    {
    Node * n=newNode(value,NULL);
    n->parent = node;
    if(value.value < node->data.value)
    {
    node->left=n;
    }
    else
    if(value.value > node->data.value)
    {
    node->right=n;
    }
    return n;
    }
    else
    insertNode(node->left, value);
    }
    else if (value.value > node->data.value)
    {
    if(node->right==NULL)
    {
    Node *n=newNode(value,NULL);
    n->parent = node;
    if(value.value < node->data.value)
    {
    node->left=n;
    }
    else if(value.value > node->data.value)
    {
    node->right=n;
    }
    return n;
    }
    else
    insertNode(node->right, value);
    }
    else
    {
    return NULL;                                                  		//duplicate values cannot be inserted.
    }
}


Data *search(Tree *bst,Data value)                                                    //SEARCH
{
    if(bst->root==NULL)
    {
    return 0;                                                                  		//tree is empty
    }
    else if(value.value==bst->root->data.value)
    {
    return bst->root;                                         		            //search complete
    }
    else
    {
    searchNode(bst->root,value);
    }
}
int ind=0;
Node *searchNode(Node *node,Data value)
{
    if(node==NULL)
    {
    return NULL;                                                         		//tree is empty
    }
    else
    {
    if(value.value < node->data.value)
    {
    if(node->left!=NULL)
    {
    return searchNode(node->left, value);
    }
    else
    {
    return NULL;                                                                 					//value not found
    }
    }
    else if(value.value > node->data.value)
    {
    if(node->right!=NULL)
    {
    return searchNode(node->right,value);
    }
    else
    {
    return NULL;                                                                 					//value not found
    }
    }
    else if(value.value==node->data.value)
    {
    return node;                                                      				//search complete
    }
    else
    {
    return NULL;                                                                 			//value not found
    }
    }
}

void removeData(Tree *bst,Data value)                                           //REMOVE
{
    if(bst->root==NULL)
    {                                                          //tree is empty
    }
    else
    {
    Node*a=searchNode(bst->root,value);
    if(a!=NULL)
    {
    if(a->left==NULL&&a->right==NULL)
    {
    removeLeaf(bst,a);
    }
    else if(a->left==NULL||a->right==NULL)
    {
    shortCircuit(bst,a);
    }
    else
    {
    promotion(bst,a);
    }
    }
    else
    {}
    }
}

void removeLeaf(Tree *bst, Node *d_node)
{
    Node *parent=d_node->parent;                                                   //calling removed_node
    if(bst->root==d_node&&d_node->left==NULL&&d_node->right==NULL)
    {
    parent=bst->root;
    bst->root=NULL;
    parent->left=NULL;
    parent->right=NULL;
    parent->parent=NULL;
    free(parent);
    }
    else
    {
    if(parent->right==d_node)
    parent->right=NULL;
    else if(parent->left==d_node)
    parent->left=NULL;
    d_node->parent=NULL;                                                //node removed
    free(d_node);
    parent=NULL;
    free(parent);
    }
}

void shortCircuit(Tree *bst, Node *d_node)
{
    Node*parent=d_node->parent;                                          //calling shortcircuit
    Node*c;
    if(bst->root==d_node)
    {
    parent=bst->root;
    if(d_node->left!=NULL&&d_node->right==NULL)
    {
    bst->root=d_node->left;
    d_node->left->parent=NULL;
    free(d_node);
    return;
    }
    else if(d_node->left==NULL&&d_node->right!=NULL)
    {
    bst->root=d_node->right;
    d_node->right->parent=NULL;
    free(d_node);
    return;
    }
    }
    if(d_node->left!=NULL&&d_node->right==NULL)
    {
    if(parent->right==d_node)
    {
    parent->right=d_node->left;
    c=d_node->left;
    c->parent=d_node->parent;
    }
    else
    {
    parent->left=d_node->left;
    c=d_node->left;
    c->parent=d_node->parent;
    }
    d_node->parent=NULL;
    d_node->left=NULL;
    d_node->right=NULL;
    free(d_node);
    parent=NULL;
    free(parent);
    c=NULL;
    free(c);
    }
    else if(d_node->left==NULL&&d_node->right!=NULL)
    {
    if(parent->right==d_node)
    {
    parent->right=d_node->right;
    c=d_node->right;
    c->parent=d_node->parent;
    }
    else
    {
    parent->left=d_node->right;
    c=d_node->right;
    c->parent=d_node->parent;
    }
    d_node->parent=NULL;
    d_node->left=NULL;
    d_node->right=NULL;
    free(d_node);                                            	              //node removed
    parent=NULL;
    free(parent);
    c=NULL;
    free(c);
    }
}

Node*findMininBST(Node*d_node)
{
    if(d_node==NULL)
    {
    return NULL;
    }
    if(d_node->left!=NULL)
    return findMininBST(d_node->left);
    else
    {
    return d_node;                                           		//found
    }
}

void promotion(Tree *bst,Node *d_node)
{
    Node *a=findMininBST(d_node->right);                         	//calling promotion
    d_node->data=a->data;
    if(a->left==NULL&&a->right==NULL)
    {
    removeLeaf(bst,a);
    }
    else if(a->left==NULL||a->right==NULL)
    {
    shortCircuit(bst,a);
    }
}


Tree *clone(Tree *t)                                          //TESTING THE TREE
{
    Tree*newTreeclone=NULL;
    if(t->root!=NULL)
    {
    newTreeclone=newTree();
    cloneTree(t->root,newTreeclone);
    }
    return newTreeclone;
}

void cloneTree(Node *n,Tree *t)
{
    if(n!=NULL)
    {
    insert(t,n->data);
    cloneTree(n->left,t);
    cloneTree(n->right,t);
    }
}

int compare(Tree *t,Tree *copy)
{
    int compare_val=0;
    if(t!=NULL&&copy!=NULL)
    compare_val=compareTreeNodes(t->root,copy->root);
    return compare_val;
}
int compareTreeNodes(Node *m, Node *c)
{
    int r_val=0;
    if(m!=NULL&&c!=NULL)
    {
    if(m->data.value==c->data.value)
    r_val=1;
    compareTreeNodes(m->left,c->left);
    compareTreeNodes(m->right,c->right);
    }
    return r_val;
}


void sort(Tree *t,Data *d)
{
    if(t->root!=NULL)
    inOrder(t->root,d);
}
void inOrder(Node *n,Data *data)
{
    if(n!=NULL)
    {
    inOrder(n->left,data);
    data[ind]=n->data;
    ind++;
    inOrder(n->right,data);
    }
}

void f_tree(Node *n)
{
    Node*a=NULL;
    a=n;
    if(a)
    {
    f_tree(a->left);
    f_tree(a->right);
    free(a);
}
}

void deleteTree(Tree *bst)
{
 f_tree(bst->root);
 bst->root==NULL;
 free(bst);
}
