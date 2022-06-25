//
// @author: Christinlj
// @date: 2022/6/25 19:14
// @description: 简单选择排序
//

#include<iostream>
#include<vector>
using namespace std;
typedef int ElemType;

//第i趟排序，遍历a[i]-a[n-1],选择最小的元素与a[i]交换
void SelectSort(vector<ElemType> &a,int n){
    for (int i = 0; i < n-1; ++i) {//n-1趟
        int min=i;  //最小元素位置
        for (int j = i; j < n; ++j) {//从a[i]~a[n-1]中选出最小元素
            if(a[j]<a[min]) min=j;
        }
        if(min!=i){
            auto t=a[i];
            a[i]=a[min];
            a[min]=t;
        }
    }
}

int main() {
    vector<ElemType> a;
    ElemType x;
    cout<<"Please input sequence:";
    while(cin>>x){
        a.push_back(x);
        if(cin.get()=='\n') break;
    }
    cout<<"Before:";
    for (ElemType & it : a) {
        cout<<it<<' ';
    }
    cout<<"\nAfter:";
    SelectSort(a,a.size());
    for (ElemType & it : a) {
        cout<<it<<' ';
    }
    return 0;
}