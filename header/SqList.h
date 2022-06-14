//
// @author: Christinlj
// @date: 2022/6/14 19:43
// @description: 线性表-顺序存储
//

#ifndef CLION_SQLIST_H
#define CLION_SQLIST_H

#include<iostream>
using namespace std;

const int MAXSIZE = 100;

typedef int ElemType;

typedef struct{
    ElemType *data;
    int length;
}SqList;

//初始化
bool InitList(SqList &L);

//返回长度
int Length(SqList L);

//找到第一个值为e的元素，返回其位置
int LocateElem(SqList L,ElemType e);

//获取第i个元素，赋值给e
bool GetElem(SqList L,int i,ElemType &e);

//在第i个位置上插入元素e
bool ListInsert(SqList &L, int i, ElemType e);

//删除第i个位置上的元素，e返回删除元素的值
bool ListDelete(SqList &L, int i, ElemType &e);

//输出顺序表
void PrintList(SqList L);

//线性表判空
bool Empty(SqList L);

//销毁顺序表
void DestroyList(SqList &L);

#endif //CLION_SQLIST_H
