#include"../header/SqStack.h"

//初始化
bool InitStack(SqStack &s) {
    s.data=new ElemType[MAXSIZE];
    if(!s.data){
        cout<<"No available memory!"<<endl;
        return false;
    }
    s.top=-1;   //栈顶指针指向当前栈顶
    return true;
}
//判空
bool StackEmpty(SqStack s){
    return s.top==-1;
}
//进栈
bool Push(SqStack &s,ElemType x){
    if(s.top==MAXSIZE-1){
        return false;
    }
    s.data[++s.top]=x;
    return true;
}
//出栈
bool Pop(SqStack &s,ElemType &x){
    if(s.top==-1){
        return false;
    }
    x=s.data[s.top--];
    return true;
}
//获取栈顶元素
bool GetTop(SqStack s,ElemType &x){
    if(s.top==-1){
        return false;
    }
    x=s.data[s.top];
    return true;
}
//销毁
void DestroyStack(SqStack &s){
    delete s.data;
    s.top=-1;
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