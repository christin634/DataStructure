//
// @author: Christinlj
// @date: 2022/6/15 11:48
// @description: 循环队列-顺序存储
//
//typedef struct {
//    ElemType *data;
//    int rear,front;
//}SqQueue;

#include"../header/SqQueue.h"

//初始化
void InitQueue(SqQueue &q){
    q.data=new ElemType[MAXSIZE];
    if(q.data== nullptr){
        cout<<"No available memory"<<endl;
        return;
    }
    q.rear=q.front=0;
}
//判空
bool QueueEmpty(SqQueue q){
    return q.rear==q.front;
}
//入队
bool EnQueue(SqQueue &q,ElemType x){
    if((q.rear+1)%MAXSIZE==q.front){//队满
        return false;
    }
    q.data[q.rear]=x;
    q.rear=(q.rear+1)%MAXSIZE;
    return true;
}
//出队
bool DeQueue(SqQueue &q,ElemType &x){
    if(QueueEmpty(q)){
        return false;
    }
    x=q.data[q.front];
    q.front=(q.front+1)%MAXSIZE;
    return true;
}
//获取队头元素
bool GetHead(SqQueue q,ElemType &x){
    if(QueueEmpty(q)){
        return false;
    }
    x=q.data[q.front];
    return true;
}

int main() {
    SqQueue q;
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