#include<iostream>
#include<cstdlib>
using namespace std;

const int MAXSIZE = 50;
typedef int ElemType;

//顺序栈
typedef struct SqStack{
    ElemType *data;
    int top;
}SqStack;

bool InitStack(SqStack &s){
    if(!(s.data=(ElemType*)malloc(MAXSIZE*sizeof(ElemType)))){
        cout<<"No available memory!\n";
        return false;
    }
    s.top=-1;
    return true;
}

bool StackEmpty(SqStack &s){
    return s.top==-1;
}

bool Push(SqStack &s,ElemType x){
    if(s.top+1==MAXSIZE){
        cout<<"Stack full!"<<endl;
        return false;
    }
    s.data[++s.top]=x;
    return true;
}

bool Pop(SqStack &s,ElemType &x){
    if(StackEmpty(s)){
        cout<<"Stack empty!"<<endl;
        return false;
    }
    x = s.data[s.top--];
    return true;
}

bool GetTop(SqStack &s,ElemType &x){
    if(StackEmpty(s)){
        cout<<"Stack empty!"<<endl;
        return false;
    }
    x = s.data[s.top];
    return true;
}

int main()
{
    SqStack s;
    ElemType x;
    InitStack(s);
    for(int i=0;i<10;i++){
        Push(s,i);
    }
    for(int i=0;i<10;i++){
        Pop(s,x);
        cout<<x<<' ';
    }
    return 0;
}