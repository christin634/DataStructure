//
// @author: Christinlj
// @date: 2022/6/22 9:57
// @description: HuffmanTree and HuffmanCoding
//

#include<iostream>
#include<vector>
#include<map>
#include<string>
using namespace std;

//静态二叉链表表示赫夫曼树
typedef struct{
    unsigned int weight;
    unsigned int parent,lchild,rchild;
}HTNode,*HuffmanTree;

/**
 * 选取权值最小且parent=0的两个结点，s1和s2返回其序号
 * @param ht
 * @param n 范围[1,n]
 * @param s1
 * @param s2
 */
void Select(HuffmanTree ht,int n,int &s1,int &s2){
    map<unsigned int,int> map;   // weight-index
    //获取parent=0的结点，按照weight-index放入map中
    //map中自动按照键值（权值）从小到大排序
    for(auto i=1;i<=n;i++){
        if(ht[i].parent==0){
            map[ht[i].weight]=i;
        }
    }
    auto i=map.begin();
    s1=i->second;
    i++;
    s2=i->second;
}

/**
 * 构造赫夫曼树
 * @param ht 引用
 * @param w 权值
 */
void CreateHuffmanTree(HuffmanTree &ht,vector<unsigned int> w){
    if(w.size()<=1) return;
    int n = w.size();   //权值
    int m = 2*n-1;
    ht = new HTNode[m+1];   //0号单元弃用
    for (auto i=1;i<=n;i++) {//叶子结点
        ht[i].parent=ht[i].lchild=ht[i].rchild=0;
        ht[i].weight=w[i-1];
    }
    for (auto i=n+1;i<=m;i++) {//非叶子结点
        ht[i].parent=ht[i].lchild=ht[i].rchild=ht[i].weight=0;
    }
    int s1,s2;
    for(auto i=n+1;i<=m;i++){   //建赫夫曼树
        Select(ht,i-1,s1,s2);
        ht[s1].parent=ht[s2].parent=i;
        ht[i].lchild=s1;
        ht[i].rchild=s2;
        ht[i].weight=ht[s1].weight+ht[s2].weight;
    }
}

/**
 *  从叶子到根，逆向求赫夫曼编码
 * @param ht HuffmanTree
 * @param hc HuffmanCoding
 * @param n 结点数
 */
void HuffmanCoding(HuffmanTree &ht,vector<string> &hc,int n){
    hc = vector<string>(n+1,string(n,'\0'));
    string cd(n,'\0');
    int start,i,j,p;
    for(i=1;i<=n;i++){
        start=n-1;  //每个编码结束符位置
        for(j=i,p=ht[i].parent;p!=0;j=p,p=ht[p].parent){//从叶子到根逆向
            if(ht[p].lchild==j) cd[--start]='0';
            else    cd[--start]='1';
        }
        hc[i]=new char[n-start];
        hc[i].assign(&cd[start],n-start);
    }
}

int main() {
    HuffmanTree ht;
    vector<unsigned int> weight;
    vector<string> hc;
    unsigned int w;
    cout<<"Please input weights of nodes:";
    while(cin>>w){
        weight.push_back(w);
        if(cin.get()=='\n') break;
    }
    CreateHuffmanTree(ht,weight);
    HuffmanCoding(ht,hc,weight.size());
    for (int i=1;i<=weight.size();i++){
        cout<<hc[i]<<' ';
        cout<<endl;
    }
    return 0;
}