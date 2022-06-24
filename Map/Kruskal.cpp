//
// @author: Christinlj
// @date: 2022/6/24 9:19
// @description: 最小生成树-Kruskal算法
//

#include"../header/AMGraph.h"
#include<map>
//最小生成树
typedef struct MSTree{
    VertexType vexs[MAX_VERTEX_NUM];    //顶点集合
    ArcType arcs[MAX_VERTEX_NUM][MAX_VERTEX_NUM];  //邻接矩阵--边表
    int vexnum;  //当前顶点数
    int arcnum; //当前边数
    int weight;
    int UFSets[MAX_VERTEX_NUM]; //并查集
}MSTree;
//找到顶点在定点表中的位置，若无返回-1
int LocateVex(AMGraph G,VertexType v){
    for(auto i=0;i<G.vexnum;i++)
        if(v==G.vexs[i])
            return i;
    return -1;
}
//multimap可允许多个键值相同
//自动按照键值从小到大排序,权值-(x，y)
//pain为边(x,y)
multimap<int,pair<int,int>> arc_map;
//创建无向网
void CreateUDN(AMGraph &G){
    cout<<"Please input the number of vertex and arc:";
    cin>>G.vexnum>>G.arcnum;
    cout<<"Please input information about "<<G.vexnum<<" vertexs:";
    for(auto i=0;i<G.vexnum;i++)
        cin>>G.vexs[i];
    //初始化邻接矩阵，全部置为∞
    for(auto i=0;i<G.vexnum;i++)
        for(auto j=0;j<G.vexnum;j++){
            G.arcs[i][j]=INFINITY;
        }
    cout<<"Please input arc's imformation:\n";
    //输入内容为两个结点，边的权值
    VertexType v1,v2;
    ArcType w;
    for(auto i=0;i<G.arcnum;i++){
        cin>>v1>>v2>>w;
        auto x= LocateVex(G,v1),y= LocateVex(G,v2);
        G.arcs[x][y]=G.arcs[y][x]=w;
        //边信息放入map中，自动排序
        arc_map.insert({ w, {x,y} });
    }
}
//初始化
void Init(AMGraph G,MSTree &T){
    T.vexnum=G.vexnum;
    T.weight=T.arcnum=0; //初始边数为0
    for(auto i=0;i<T.vexnum;i++)
        T.vexs[i]=G.vexs[i];
    for(auto i=0;i<T.vexnum;i++)
        for(auto j=0;j<T.vexnum;j++){
            T.arcs[i][j]=INFINITY;
        }
    for (int i=0;i<T.vexnum;i++) {
        T.UFSets[i]=-1;
    }
}
//在并查集中查找并返回包含元素x的根
int Find(int s[],int x){
    while(s[x]>=0)  x=s[x];
    return x;
}
//将s的子集r2并入r1，要求r1与r2不相交
bool Union(int s[],int r1,int r2){
    int fx1 = Find(s,r1),fx2 = Find(s,r2);
    if(fx1!=fx2){//不相交则合并
        s[fx2]=fx1;
        return true;
    }
    return false;   //相交
}
void Kruskal(AMGraph G,MSTree &T){
    Init(G,T);
    while(T.arcnum<T.vexnum-1){//边数最大为顶点数-1
        auto w=arc_map.begin()->first;
        auto x=arc_map.begin()->second.first,y=arc_map.begin()->second.second;
        if(Union(T.UFSets,x,y)){//合并成功
            T.arcs[x][y]=w;
            T.weight+=w;
            T.arcnum++;
            cout<<T.vexs[x]<<"-("<<T.arcs[x][y]<<")->"<<T.vexs[y]<<endl;
        }
        arc_map.erase(arc_map.begin());
    }
    cout<<"Total weight:"<<T.weight;
}
int main() {
    AMGraph G;
    MSTree T;
    CreateUDN(G);
    Kruskal(G,T);
    return 0;
}
//1 2 6
//1 3 1
//1 4 5
//2 3 5
//2 5 3
//3 4 5
//3 5 6
//3 6 4
//4 6 2
//5 6 6