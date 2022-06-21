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

int getDepth(BiTree root){
    if(!root){
        return 0;
    }
    int ldepth = getDepth(root->lchild);
    int rdepth = getDepth(root->rchild);
    return ldepth>rdepth?ldepth+1:rdepth+1;
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
    cout<<endl<<"Depth:"<<getDepth(root)<<endl;
    return 0;
}