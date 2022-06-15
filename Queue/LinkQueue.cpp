//
// @author: Christinlj
// @date: 2022/6/15 12:00
// @description: 队列
//
//typedef struct LinkNode {
//    ElemType data;
//    struct LinkNode *next;
//}LinkNode;
//typedef struct {
//    LinkNode *front,*rear;
//}LinkQueue;

#include"../header/LinkQueue.h"

//初始化
void InitQueue(LinkQueue &q){
    q.front=new LinkNode();
    if(q.front== nullptr){
        cout<<"No available memory"<<endl;
        return;
    }
    q.rear=q.front;
    q.front->next= nullptr;
}
//判空
bool QueueEmpty(LinkQueue q){
    return q.front==q.rear;
}
//入队
bool EnQueue(LinkQueue &q,ElemType x){
    LinkNode *node=new LinkNode();
    node->data=x;
    node->next= nullptr;
    q.rear->next=node;
    q.rear=node;
    return true;
}
//出队
bool DeQueue(LinkQueue &q,ElemType &x){
    if(QueueEmpty(q)){
        return false;
    }
    LinkNode *p=q.front->next;
    x=p->data;
    q.front->next=p->next;
    if(q.rear==p){
        q.rear=q.front;
    }
    delete p;
    return true;
}
//获取队头元素
bool GetHead(LinkQueue q,ElemType &x){
    if(QueueEmpty(q)){
        return false;
    }
    x=q.front->data;
    return true;
}

int main() {
    LinkQueue q;
    InitQueue(q);
    for (int i = 0; i < 10; ++i) {
        EnQueue(q,i);
    }
    int x;
    for (int i = 0; i < 10; ++i) {
        DeQueue(q,x);
        cout<<x<<' ';
    }
    return 0;
}