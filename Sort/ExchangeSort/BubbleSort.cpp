//
// @author: Christinlj
// @date: 2022/6/25 17:53
// @description: 冒泡排序
//

#include<iostream>
#include<vector>
using namespace std;
typedef int ElemType;

//冒泡排序--排序结果为非递减序列
//从前往后，每次排序后，将最大的元素交换到待排序列的最后(也可从后往前)
void BubbleSort(vector<ElemType> &a,int n){
    bool flag;   //标记变量，本轮是否发生交换
    for (int i = 0; i < n-1; ++i) {//最多进行n-1趟
        flag=false;
        //每一趟排序过后，有一个元素在最终位置上
        for (int j = 0; j < n - i - 1; ++j) {
            if(a[j]>a[j+1]){
                auto t=a[j];
                a[j]=a[j+1];
                a[j+1]=t;
                flag= true;
            }
        }
        if(!flag)   break;  //未发生交换，说明已经有序
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
    BubbleSort(a,a.size());
    for (ElemType & it : a) {
        cout<<it<<' ';
    }
    return 0;
}