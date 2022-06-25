//
// @author: Christinlj
// @date: 2022/6/25 18:25
// @description: 快速排序
//

#include<iostream>
#include<vector>
using namespace std;
typedef int ElemType;

//将a[low]~a[high]以第一个元素为枢纽，划分
int Partition(vector<ElemType> &a,int low,int high){
    ElemType pivot=a[low];  //当前第一个元素为枢轴
    while(low<high){
        while(low<high&&a[high]>=pivot) high--;
        a[low]=a[high]; //比枢纽小的，移到左边
        while(low<high&&a[low]<=pivot)  low++;
        a[high]=a[low]; //比枢纽大的移到右边
    }
    //一次划分完之后，low==high，该位置放pivot
    //此时满足左侧<枢纽<右侧
    a[low]=pivot;
    return low;
}
//快速排序
void QuickSort(vector<ElemType> &a,int low,int high){
    if(low<high){
        int pivotpos= Partition(a,low,high);    //划分
        //对两个子表排序
        QuickSort(a,low,pivotpos-1);
        QuickSort(a,pivotpos+1,high);
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
    QuickSort(a,0,a.size()-1);
    for (ElemType & it : a) {
        cout<<it<<' ';
    }
    return 0;
}