//
// @author: Christinlj
// @date: 2022/6/15 10:07
// @description: 栈-顺序存储
//

#ifndef CLION_SQSTACK_H
#define CLION_SQSTACK_H

#include<iostream>
using namespace std;

const int MAXSIZE = 50;
typedef int ElemType;

typedef struct SqStack{
    ElemType *data;
    int top;
}SqStack;

//初始化
bool InitStack(SqStack &s);
//判空
bool StackEmpty(SqStack s);
//进栈
bool Push(SqStack &s,ElemType x);
//出栈
bool Pop(SqStack &s,ElemType &x);
//获取栈顶元素
bool GetTop(SqStack s,ElemType &x);
//销毁
void DestroyStack(SqStack &s);

#endif //CLION_SQSTACK_H
