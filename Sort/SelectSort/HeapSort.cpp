//
// @author: Christinlj
// @date: 2022/6/25 19:32
// @description: 堆排序--大根堆
// a[1]-a[n],完全二叉树
//

#include<iostream>
using namespace std;
typedef int ElemType;
const int MAXLEN = 50;

//调整以k为根的子树
void HeadAdjust(ElemType a[],int k,int len){
    a[0]=a[k];  //暂存根
    for (int i = 2*k; i <=len ; i*=2) {//
        if(i<len&&a[i]<a[i+1]){//筛选出子节点中最大的元素及位置
            i++;
        }
        if(a[0]>=a[i])   break;  //根大于子节点中最大元素，筛选结束
        else{
            a[k]=a[i];  //将a[i]调整到双亲结点上
            k=i;    //修改k值，以便继续筛选
        }
    }
    a[k]=a[0];  //被筛选结点放入最终位置
}

void BuildMaxHeap(ElemType a[],int len){
    for (int i = len/2; i>0 ; i--) {//从i=len/2~1，反复调整
        HeadAdjust(a,i,len);
    }
}

void HeapSort(ElemType a[],int len){
    BuildMaxHeap(a,len);    //初始建堆
    for (int i = len; i >1 ; i--) {//n-1趟交换和建堆
        //堆顶元素换到堆底
        auto t=a[i];
        a[i]=a[1];
        a[1]=t;
        HeadAdjust(a,1,i-1);//调整剩余i-1个元素
    }
}
int main() {
    ElemType a[MAXLEN+1];
    int len;
    cout<<"Please input size of heap:";
    cin>>len;
    cout<<"Please input sequence:";
    for (int i = 1; i <= len; ++i) {
        cin>>a[i];
    }
    cout<<"Before:";
    for (auto i=1;i<=len ; i++) {
        cout<<a[i]<<' ';
    }
    cout<<"\nAfter:";
    HeapSort(a,len);
    for (auto i=1;i<=len ; i++) {
        cout<<a[i]<<' ';
    }
    return 0;
}