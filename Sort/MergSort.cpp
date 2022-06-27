//
// @author: Christinlj
// @date: 2022/6/27 9:01
// @description: 2路归并排序
//

#include<iostream>
using namespace std;
typedef int ElemType;

//辅助数组
ElemType *b;
/**
 * 将a[low..mid]和a[mid+1..high]合成一个有序表
 * @param a
 * @param low
 * @param mid
 * @param high
 */
void Merge(ElemType* a,int low,int mid,int high){
    int i,j,k;
    for (k=low;k<=high;k++)
        b[k]=a[k];
    for (i = low,j=mid+1,k=low; i <= mid && j<=high; k++) {
        if(b[i]<=b[j]){
            a[k]=b[i++];
        }else{
            a[k]=b[j++];
        }
    }
    while(i<=mid)   a[k++]=b[i++];
    while(j<=high)  a[k++]=b[j++];
}
void MergeSort(ElemType *a,int low,int high){
    if(low<high){
        int mid=(low+high)/2;   //从中间划分两个子序列
        MergeSort(a,low,mid);   //左侧序列递归排序
        MergeSort(a,mid+1,high);    //右侧序列递归排序
        Merge(a,low,mid,high);
    }
}
int main() {
    ElemType *a ;
    int n;
    cout<<"Please input size of sequence:";
    cin>>n;
    b=new ElemType[n];
    a=new ElemType[n];
    cout<<"Please input sequence:";
    for (int i = 0; i < n; ++i) {
        cin>>a[i];
    }
    cout<<"Before:";
    for (int i = 0; i < n; ++i) {
        cout<<a[i]<<' ';
    }
    cout<<"\nAfter:";
    MergeSort(a,0,n-1);
    for (int i = 0; i < n; ++i) {
        cout<<a[i]<<' ';
    }
    return 0;
}