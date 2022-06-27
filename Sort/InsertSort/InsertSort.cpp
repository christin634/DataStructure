//
// @author: Christinlj
// @date: 2022/6/25 15:56
// @description: 直接插入排序,折半插入排序
// a[1]-a[n],a[0]为哨兵
//

#include<iostream>
#include<vector>
using namespace std;
typedef int ElemType;

/**
 * 直接插入排序,结果为非递减有序
 * @param a 序列
 * @param n a中元素数目
 */
void DirectedInsertSort(vector<ElemType> a,int n){
    int i,j;
    //依次将a[2]~a[n]插入已排序序列(a[1]...a[i-1])
    for(i=2;i<=n;i++)
        if(a[i]<a[i-1]){
            a[0]=a[i];  //a[0]为哨兵，暂存待插入元素
            for(j=i-1;a[0]<a[j];j--)//找到应该插入的位置
                a[j+1]=a[j];
            //复制到插入位置，退出循环后a[0]>a[j]
            //所以插入到a[j+1]
            a[j+1]=a[0];
        }
    cout<<"\nDirectedInsertSort:";
    for (auto it=a.begin()+1;it!=a.end();it++) {
        cout<<*it<<' ';
    }
}

/**
 * 折半插入排序,结果为非递减有序
 * 使用折半查找找到插入位置
 * @param a 序列
 * @param n a中元素数目
 */
void BInsertSort(vector<ElemType> &a,int n){
    int i,j,low,high,mid;
    //依次将a[2]~a[n]插入已排序序列(a[1]...a[i-1])
    for(i=2;i<=n;i++)
        if(a[i]<a[i-1]){
            a[0]=a[i];  //a[0]为哨兵，暂存待插入元素
            low=1;high=i-1;
            while(low<=high){//使用折半查找有序子表
                mid=(low+high)/2;
                if(a[mid]>a[0]) high=mid-1;
                else    low=mid+1;
            }
            for(j=i-1;j>=high+1;j--)//移动
                a[j+1]=a[j];
            //复制到插入位置，退出循环后a[0]>a[j]
            //所以插入到a[j+1]
            a[j+1]=a[0];
        }
}

int main() {
    vector<ElemType> a;
    ElemType x;
    a.push_back(0);
    cout<<"Please input sequence:";
    while(cin>>x){
        a.push_back(x);
        if(cin.get()=='\n') break;
    }
    cout<<"Before:";
    for (auto it=a.begin()+1;it!=a.end();it++) {
        cout<<*it<<' ';
    }
    DirectedInsertSort(a,a.size()-1);
    cout<<"\nBInsertSort:";
    BInsertSort(a,a.size()-1);
    for (auto it=a.begin()+1;it!=a.end();it++) {
        cout<<*it<<' ';
    }
    return 0;
}