//
// @author: Christinlj
// @date: 2022/6/15 11:58
// @description: 队列-链式存储
//

#ifndef CLION_LINKQUEUE_H
#define CLION_LINKQUEUE_H
#include<iostream>
using namespace std;

typedef int ElemType;
typedef struct LinkNode {
    ElemType data;
    struct LinkNode *next;
}LinkNode;
typedef struct {
    LinkNode *front,*rear;
}LinkQueue;
//初始化
void InitQueue(LinkQueue &q);
//判空
bool QueueEmpty(LinkQueue q);
//入队
bool EnQueue(LinkQueue &q,ElemType x);
//出队
bool DeQueue(LinkQueue &q,ElemType &x);
//获取队头元素
bool GetHead(LinkQueue q,ElemType &x);

#endif //CLION_LINKQUEUE_H
