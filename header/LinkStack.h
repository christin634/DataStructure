//
// @author: Christinlj
// @date: 2022/6/15 10:25
// @description: 栈-链式存储
//

#ifndef CLION_LINKSTACK_H
#define CLION_LINKSTACK_H

#include<iostream>
using namespace std;

typedef int ElemType;
typedef struct LinkNode{
    ElemType data;
    struct LinkNode *next;
}LinkNode;

typedef struct LinkStack{
    LinkNode *top;  //指向栈顶元素
    int size;   //栈大小
}LinkStack;

//初始化
bool InitStack(LinkStack &s);
//判空
bool StackEmpty(LinkStack s);
//进栈
bool Push(LinkStack &s,ElemType x);
//出栈
bool Pop(LinkStack &s,ElemType &x);
//获取栈顶元素
bool GetTop(LinkStack s,ElemType &x);
//销毁
void DestroyStack(LinkStack &s);

#endif //CLION_LINKSTACK_H
