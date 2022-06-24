//
// @author: Christinlj
// @date: 2022/6/22 15:21
// @description: 并查集
// 数组下标代表元素名，数组索引代表根
//

#include<iostream>
using namespace std;
const int MAXSIZE=50;
int UFSets[MAXSIZE];

//初始化
void Init(int s[]){
    for (int i=0;i<MAXSIZE;i++) {
        s[i]=-1;
    }
}
//在并查集中查找并返回包含元素x的根
int Find(int s[],int x){
    while(s[x]>=0)  x=s[x];
    return x;
}
//将s的子集r2并入r1，要求r1与r2不相交
void Union(int s[],int r1,int r2){
    int fx1 = Find(s,r1),fx2 = Find(s,r2);
    if(fx1!=fx2){//不相交则合并
        s[fx2]=fx1;
    }
}

int main() {
    Init(UFSets);
    Union(UFSets,1,2);
    Union(UFSets,3,4);
    Union(UFSets,5,6);
    Union(UFSets,7,8);
    Union(UFSets,8,9);
    Union(UFSets,1,8);
    Union(UFSets,0,5);
    Union(UFSets,1,9);
    //输出的-1个数即为集合数，-1即为根节点
    for(int i=1;i<10;i++){
        cout<<UFSets[i]<<' ';
    }
    return 0;
}