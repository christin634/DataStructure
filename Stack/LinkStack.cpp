//
// @author: Christinlj
// @date: 2022/6/15 10:30
// @description: 栈-链式存储
//
//typedef struct LinkNode{
//    ElemType data;
//    struct LinkNode *next;
//}LinkNode;
//
//typedef struct LinkStack{
//    LinkNode *top;  //指向栈顶元素
//    int size;   //栈大小
//}LinkStack;


#include"../header/LinkStack.h"
//初始化
bool InitStack(LinkStack &s){
    s.top= nullptr;
    s.size=0;
    return true;
}
//判空
bool StackEmpty(LinkStack s){
    return s.size==0;
}
//进栈
bool Push(LinkStack &s,ElemType x){
    LinkNode *node = new LinkNode();
    node->data=x;
    node->next=s.top;
    s.top=node;
    s.size++;
    return true;
}
//出栈
bool Pop(LinkStack &s,ElemType &x){
    if(StackEmpty(s)){
        return false;
    }
    x=s.top->data;
    s.top=s.top->next;
    s.size--;
    return true;
}
//获取栈顶元素
bool GetTop(LinkStack s,ElemType &x){
    if(StackEmpty(s)){
        return false;
    }
    x=s.top->data;
    return true;
}
//销毁
void DestroyStack(LinkStack &s){
    LinkNode *node;
    for(int i=0;i<s.size;i++){
        node=s.top;
        s.top=s.top->next;
        delete node;
    }
    s.size=0;
}
int main() {
    LinkStack s;
    InitStack(s);
    for(int i=0;i<10;i++){
        Push(s,i);
    }
    int x,y;
    for(int i=0;i<10;i++){
        Pop(s,x);
        GetTop(s,y);
        cout<<x<<' '<<y<<' ';
    }
    DestroyStack(s);
    return 0;
}