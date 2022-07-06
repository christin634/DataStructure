//
// @author: Christinlj
// @date: 2022/6/14 19:43
// @description: 线性表-顺序存储
//

//typedef struct{
//    ElemType *data;
//    int length;
//}SqList;

#include"../header/SqList.h"
//初始化
bool InitList(SqList &L){
    L.data=new ElemType[MAXSIZE];
    if(L.data== nullptr){
        cout<<"No available memory!"<<endl;
        return false;
    }
    L.length=0;
    return true;
}

//返回长度
int Length(SqList L){ return L.length;  }

//找到第一个值为e的元素，返回其位置
int LocateElem(SqList L,ElemType e){
    for (auto i = 0;i<L.length;i++) {
        if(L.data[i]==e){
            return i+1;
        }
    }
    return -1;
}

//获取第i个元素，赋值给e
bool GetElem(SqList L,int i,ElemType &e){
    if(i<1||i>L.length){
        return false;
    }
    e=L.data[i-1];
    return true;
}

//在第i个位置上插入元素e
bool ListInsert(SqList &L, int i, ElemType e){
    if(i<1||i>L.length+1||i>=MAXSIZE){
        return false;
    }
    for(auto j =L.length;j>=i;j--){
        L.data[j]=L.data[j-1];
    }
    L.data[i-1]=e;
    L.length++;
    return true;
}

//删除第i个位置上的元素，e返回删除元素的值
bool ListDelete(SqList &L, int i, ElemType &e){
    if(i<1||i>L.length){
        return false;
    }
    e=L.data[i-1];
    for(auto j=i-1;j<L.length-1;j++){
        L.data[j]=L.data[j+1];
    }
    L.length--;
    return true;
}

//输出顺序表
void PrintList(SqList L){
    for (auto i=0;i<L.length;i++) {
        cout<<L.data[i]<<' ';
    }
    cout<<endl;
}

//线性表判空
bool Empty(SqList L){
    return L.length==0;
}

//销毁顺序表
void DestroyList(SqList &L){
    delete[] L.data;
    L.length=0;
}

int main()
{
    SqList ls;
    ElemType e;
    InitList(ls);
    for(int i=1;i<=10;i++){
        ListInsert(ls,i,i-1);
    }
    PrintList(ls);
    ListDelete(ls,5,e);
    PrintList(ls);
    DestroyList(ls);
    return 0;
}