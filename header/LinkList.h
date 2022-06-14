//
// @author: Christinlj
// @date: 2022/6/14 15:12
// @description: 线性表-链式存储
//

#ifndef CLION_LINKLIST_H
#define CLION_LINKLIST_H
#include<iostream>
using namespace std;

typedef int ElemType;

typedef struct LNode{
    ElemType data;
    struct LNode *next;
}LNode,*LinkList;

//带头结点的单链表
bool InitList(LinkList &L);

//头插法建立单链表
void ListHeadInsert(LinkList &L);

//尾插法建立单链表
void ListTailInsert(LinkList &L);

//获取长度
int Length(LinkList L);

//找到第一个值为e的结点并返回
LNode *LocateElem(LinkList L);

//获取第i个结点
LNode *GetElem(LinkList L,int i);

//在第i个位置插入元素
bool ListInsert(LinkList &L, int i, ElemType e);

//删除第i个结点
bool ListDelete(LinkList &L, int i);

//输出链表
void PrintList(LinkList L);

//判空
bool Empty(LinkList L);

//销毁链表
void DestroyList(LinkList &L);
#endif //CLION_LINKLIST_H
