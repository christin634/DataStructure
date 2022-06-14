//
// @author: Christinlj
// @date: 2022/6/13 15:18
// @description: 二叉树链式存储
//

#ifndef CLION_BITREE_H
#define CLION_BITREE_H

#include<iostream>
#include<cstdlib>
using namespace std;

typedef char ElemType;

typedef struct BiTNode{
    ElemType data;
    struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

//按先序次序创建二叉树,以#分隔
bool CreateBiTreePreOrder(BiTree &root){
    char ch;
    cin>>ch;
    if(ch=='#') root=nullptr;
    else{
        if(!(root=(BiTNode*)malloc(sizeof(BiTNode)))){
            cout<<"No available memory!"<<endl;
            return false;
        }
        root->data=ch;
        CreateBiTreePreOrder(root->lchild);
        CreateBiTreePreOrder(root->rchild);
    }
    return true;
}

//先序遍历
void PreOrder(BiTree root);

//中序遍历
void InOrder(BiTree root);

//后序遍历
void PostOrder(BiTree root);


#endif //CLION_BITREE_H
