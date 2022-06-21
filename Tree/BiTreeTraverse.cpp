//
// @author: Christinlj
// @date: 2022/6/14 15:28
// @description: 二叉树的非递归遍历
//

#include"../header/BiTree.h"
#include<stack>
#include<queue>

//先序遍历
void PreOrder(BiTree root){
    stack<BiTNode*> s;
    auto p=root;
    while(p||!s.empty()){
        if(p){
            cout<<p->data<<' ';
            s.push(p);
            p=p->lchild;
        }
        else{
            p=s.top();
            s.pop();
            p=p->rchild;
        }
    }
}

//中序遍历
void InOrder(BiTree root){
    stack<BiTNode*> s;
    auto p=root;
    while(p||!s.empty()){
        if(p){
            s.push(p);
            p=p->lchild;
        }
        else{
            p=s.top();
            s.pop();
            cout<<p->data<<' ';
            p=p->rchild;
        }
    }
}

/**
 * 后序遍历
 * ① 根节点入栈，沿着左孩子，依次入栈，直至左孩子为空；
 * ② 读取栈顶元素：
 *      若栈顶元素右孩子不空且未访问过，右子树转①；
 *      否则，弹出栈顶元素，并访问。
 * 每次出栈访问一个结点就相当于遍历完以该结点为根的子树，需将p置为nullptr
 * @param root
 */
void PostOrder(BiTree root){
    stack<BiTNode*> s;
    auto p = root;
    BiTNode *r= nullptr;
    while(p||!s.empty()){
        if(p){//走到最左
            s.push(p);
            p=p->lchild;
        }
        else{//右
            p=s.top();  //读栈顶结点，不弹出
            if(p->lchild&&p->rchild!=r){//右子树存在且未访问过，向右
                p=p->rchild;
            }
            else{//否则，弹出结点并访问
                p=s.top();
                s.pop();
                cout<<p->data<<' ';
                r=p;    //记录最近访问过的结点
                p= nullptr; //重置p指针
            }
        }
    }
}

void LayerTraverse(BiTree root){
    queue<BiTNode*> q;
    BiTree p;
    q.push(root);
    while(!q.empty()){
        p=q.front();
        q.pop();
        cout<<p->data<<' ';
        if(p->lchild!= nullptr){
            q.push(p->lchild);
        }
        if(p->rchild!= nullptr){
            q.push(p->rchild);
        }
    }
}

int getDepth(BiTree root){
    if(!root)   return 0;   //空树
    queue<BiTNode*> q;
    BiTNode *last=root,*p;    //last指向当前层最右结点,初始为第一层的根结点
    int depth=0;
    q.push(root);   //根结点入队
    while(!q.empty()){
        p=q.front();    //出队
        q.pop();
        if(p->lchild)   //左孩子入队
            q.push(p->lchild);
        if(p->rchild)   //右孩子入队
            q.push(p->rchild);
        if(p==last){//当前结点为该层最右结点
            depth++;    //层数+1
            last=q.back();  //最后结点改为下一层结点的最右结点，即为队列最后一个元素
        }
    }
    return depth;
}

int main() {
    BiTree root;
    CreateBiTreePreOrder(root);
    cout<<"PreOrder:";
    PreOrder(root);
    cout<<endl<<"InOrder:";
    InOrder(root);
    cout<<endl<<"LayerTraverse:";
    LayerTraverse(root);
    cout<<endl<<"PostOrder:";
    PostOrder(root);
    cout<<endl<<"Depth:"<<getDepth(root);
    return 0;
}
//ABD##E##C##
//PreOrder:A B D E C
//InOrder:D B E A C
//LayerTraverse:A B C D E
//PostOrder:D E B C A