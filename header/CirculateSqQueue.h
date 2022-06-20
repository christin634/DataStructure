//
// @author: Christinlj
// @date: 2022/6/18 10:41
// @description: 循环队列-顺序存储实现
//

#ifndef CLION_CIRCULATESQQUEUE_H
#define CLION_CIRCULATESQQUEUE_H

#include<iostream>
using namespace std;

const int MAXSIZE=50;
typedef int ElemType;
typedef struct{
    ElemType data[MAXSIZE];
    int front,rear;
}CirculateSqQueue;
//初始化
void InitQueue(CirculateSqQueue &q);
//判空
bool isEmpty(CirculateSqQueue q);
//入队
bool EnQueue(CirculateSqQueue &q,ElemType x);
//出队
bool DeQueue(CirculateSqQueue &q,ElemType &x);
#endif //CLION_CIRCULATESQQUEUE_H
