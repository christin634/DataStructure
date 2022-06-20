//
// @author: Christinlj
// @date: 2022/6/18 10:46
// @description: 
//

#include"../header/CirculateSqQueue.h"
//初始化
void InitQueue(CirculateSqQueue &q){
    q.front=q.rear=0;
}
//判空
bool isEmpty(CirculateSqQueue q){
    return q.front==q.rear;
}
//入队
bool EnQueue(CirculateSqQueue &q,ElemType x){
    //判断是否队满，牺牲一个存储单元
    if((q.rear+1)%MAXSIZE==q.front) return false;
    q.data[q.rear]=x;
    q.rear=(q.rear+1)%MAXSIZE;
    return true;
}
//出队
bool DeQueue(CirculateSqQueue &q,ElemType &x){
    if(isEmpty(q))  return false;
    x=q.data[q.front];
    q.front=(q.front+1)%MAXSIZE;
    return true;
}
int main() {

    return 0;
}