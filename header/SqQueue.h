//
// @author: Christinlj
// @date: 2022/6/15 11:00
// @description: 循环队列-顺序存储
//

#ifndef CLION_SQQUEUE_H
#define CLION_SQQUEUE_H

#include<iostream>
using namespace std;

typedef int ElemType;
const int MAXSIZE=50;

typedef struct {
    ElemType *data;
    int rear,front;
}SqQueue;

//初始化
void InitQueue(SqQueue &q);
//判空
bool QueueEmpty(SqQueue q);
//入队
bool EnQueue(SqQueue &q,ElemType x);
//出队
bool DeQueue(SqQueue &q,ElemType &x);
//获取队头元素
bool GetHead(SqQueue q,ElemType &x);
#endif //CLION_SQQUEUE_H
