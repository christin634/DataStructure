//
// Created by Christinlj on 2022/5/14.
//

#include"../header/LinkList.h"

//初始化带头结点的单链表
bool InitList(LinkList &L){
    L = (LinkList)new LNode();
    if(!L){
        cout<<"No available memory."<<endl;
        return false;
    }
    L->next= nullptr;
    return true;
}

//头插法建立单链表
void ListHeadInsert(LinkList &L){
    InitList(L);
    ElemType x;
    LNode *node;
    while(cin>>x){
        node = new LNode();
        node->data=x;
        node->next=L->next;
        L->next=node;
        if(cin.get()=='\n') break;
    }
}

//尾插法建立单链表
void ListTailInsert(LinkList &L){
    InitList(L);
    ElemType x;
    LNode *node,*r=L;
    while(cin>>x){
        node = new LNode();
        node->data=x;
        node->next= nullptr;
        r->next=node;
        r=node;
        if(cin.get()=='\n') break;
    }
}

int Length(LinkList L){
    LNode *p = L->next;
    int cnt=0;
    while(p){
        p=p->next;
        cnt++;
    }
    return cnt;
}
//按序查找第一个值为e的元素，返回次序
LNode *LocateElem(LinkList L,ElemType e){
    LNode *p=L->next;
    while(p!= nullptr&&p->data!=e){
        p=p->next;
    }
    return p;
}
//按序查找第i个结点
LNode* GetElem(LinkList L,int i){
    if(i<1){
        return nullptr;
    }
    if(i==0){
        return L;
    }
    int j=1;
    LNode *p=L->next;
    while(p&&j<i){
        p=p->next;
        j++;
    }
    return p;   //i如果大于表长，返回nullptr
}

//将元素e插入第i个位置
bool ListInsert(LinkList &L, int i, ElemType e){
    if(i<1||i>Length(L)+1){
        return false;
    }
    //找到待插入结点的前驱
    LNode *p= GetElem(L,i-1),*q=new LNode();
    q->data=e;q->next= nullptr;
    q->next = p->next;
    p->next = q;
    return true;
}

//删除第i个结点
bool ListDelete(LinkList &L, int i){
    if(i<1&&i>Length(L)){//不包含头结点
        return false;
    }
    LNode *p = GetElem(L,i-1),*q=p->next;
    p->next=q->next;
    delete q;
    return true;
}

void PrintList(LinkList L){
    LNode *p=L->next;
    while(p){
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}

bool Empty(LinkList L){
    return L->next==nullptr;
}

void DestroyList(LinkList &L){
    delete L;
}

int main()
{
    LinkList ls1,ls2;
    ListHeadInsert(ls1);
    ListTailInsert(ls2);
    PrintList(ls1);
    PrintList(ls2);
    DestroyList(ls1);
    DestroyList(ls2);
    return 0;
}