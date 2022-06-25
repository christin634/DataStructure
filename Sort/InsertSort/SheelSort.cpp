//
// @author: Christinlj
// @date: 2022/6/25 16:45
// @description: 希尔排序
//

#include<iostream>
#include<vector>
using namespace std;
typedef int ElemType;


void ShellSort(vector<ElemType> &a,int n){
    int d,i,j;  //d为步长
    //每次循环缩小步长，为1时即相当于整体直接插入排序
    //相隔d的元素间直接插入排序
    for (d = n/2; d >= 1 ; d/=2) {
        for (i = d+1; i <= n; ++i) {
            if(a[i]<a[i-d]){
                a[0]=a[i];  //a[0]暂存a[i]
                for (j = i-d; j > 0 && a[0]<a[j] ; j-=d) {
                    a[j+d]=a[j];
                }
                a[j+d]=a[0];
            }
        }
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
    cout<<"\nAfter:";
    ShellSort(a,a.size()-1);
    for (auto it=a.begin()+1;it!=a.end();it++) {
        cout<<*it<<' ';
    }
    return 0;
}