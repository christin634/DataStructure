//
// @author: Christinlj
// @date: 2022/6/13 15:36
// @description: 
//

#include "../header/BiTree.h"

//先序遍历
void PreOrder(BiTree root){
    if(root){
        cout<<root->data<<" ";
        PreOrder(root->lchild);
        PreOrder(root->rchild);
    }
}

//中序遍历
void InOrder(BiTree root){
    if(root){
        InOrder(root->lchild);
        cout<<root->data<<" ";
        InOrder(root->rchild);
    }
}

//后序遍历
void PostOrder(BiTree root){
    if(root){
        PostOrder(root->lchild);
        PostOrder(root->rchild);
        cout<<root->data<<" ";
    }
}

int main()
{
    BiTree root;
    CreateBiTreePreOrder(root);
    cout<<"PreOrder:";
    PreOrder(root);
    cout<<endl<<"InOrder:";
    InOrder(root);
    cout<<endl<<"PostOrder:";
    PostOrder(root);
    return 0;
}