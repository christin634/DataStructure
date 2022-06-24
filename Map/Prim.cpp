//
// @author: Christinlj
// @date: 2022/6/23 21:54
// @description: 最小生成树 - Prim算法
// 以邻接矩阵表示图
//

#include"../header/AMGraph.h"
#include<map>
//最小生成树
typedef struct MSTree{
    VertexType vexs[MAX_VERTEX_NUM];    //顶点集合
    ArcType arcs[MAX_VERTEX_NUM][MAX_VERTEX_NUM];  //邻接矩阵--边表
    int vexnum;  //当前顶点数
    int weight; //权值之和
}MSTree;
//找到顶点在定点表中的位置，若无返回-1
int LocateVex(AMGraph G,VertexType v){
    for(auto i=0;i<G.vexnum;i++)
        if(v==G.vexs[i])
            return i;
    return -1;
}
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
    }
}
bool visited[MAX_VERTEX_NUM];   //标记数组,已加入T中的标记为true
/**
 * 选择包含T中顶点的权值最小的边
 * @param G
 * @param T
 * @param x x为T中已经有的边序号
 * @param y y为除T中以外的边序号
 */
void Select(AMGraph G,MSTree T,int &x,int &y){
    //符合条件的边加入map(边的权值，(x,y))
    //map自动按照键值从小到大排序
    map<int,map<int,int>> map;
    while(T.vexnum--){
        for(auto i=0;i<G.vexnum;i++){
            if(visited[i]){//从在T内的顶点开始找
                for(auto j=0;j<G.vexnum;j++){
                    if(!visited[j]&&G.arcs[i][j]!=INFINITY){//另一个顶点不在T内
                        map[G.arcs[i][j]]={{i,j}};
                    }
                }
            }
        }
    }
    x=map.begin()->second.begin()->first;
    y=map.begin()->second.begin()->second;
}
/**
 * Prim算法
 * @param G 图
 * @param T 最小生成树
 * @param start 开始顶点序号
 */
void Prim(AMGraph G,MSTree &T,int start){
    for(auto i=0;i<G.vexnum;i++)
        visited[i]= false;
    for(auto i=0;i<G.vexnum;i++)
        T.vexs[i]=0;
    for(auto i=0;i<G.vexnum;i++)
        for(auto j=0;j<G.vexnum;j++){
            T.arcs[i][j]=INFINITY;
        }
    T.weight=0;
    //序号为start的顶点加入MST
    T.vexnum=1;
    T.vexs[start]=G.vexs[start];
    visited[start]= true;
    int x,y;
    while(T.vexnum!=G.vexnum){//未包含所有顶点
        Select(G,T,x,y);
        T.weight+=G.arcs[x][y];
        T.arcs[x][y]=G.arcs[x][y];
        T.vexs[y]=G.vexs[y];
        visited[y]= true;
        T.vexnum++;
        cout<<T.vexs[x]<<"-("<<T.arcs[x][y]<<")->"<<T.vexs[y]<<endl;
    }
    cout<<"Total weight:"<<T.weight;
}
int main() {
    AMGraph G;
    MSTree T;
    CreateUDN(G);
    Prim(G,T,0);
    return 0;
}