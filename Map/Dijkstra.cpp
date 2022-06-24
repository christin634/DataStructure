//
// @author: Christinlj
// @date: 2022/6/24 14:35
// @description: 迪杰斯特拉算法求带权图单源最短路径--带权无向图为例
//

#include"../header/AMGraph.h"
#include<map>
#include<vector>
#include<algorithm>
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
//输出最短路径
void PrintPath(AMGraph G,vector<int> path){
    cout<<G.vexs[path[0]];
    for(auto i=1;i<path.size();i++){
        cout<<"->"<<G.vexs[path[i]];
    }
}
void sort_by_dist(const map<int,int>& map,int &i,int &w){//map按值升序排列
    vector<pair<int, int>> vtMap;
    vtMap.reserve(map.size());
    for (auto & it : map)
        vtMap.emplace_back(it.first, it.second);
    sort(vtMap.begin(), vtMap.end(),
         [](const pair<int, int> &x, const pair<int, int> &y) -> int {
             return x.second < y.second;    //按长度升序
         });
    i=vtMap.begin()->first;
    w=vtMap.begin()->second;
}
void Dijkstra(AMGraph G,VertexType v0){
    vector<int> path[G.vexnum];   //存储路径序号
    map<int,int> dist; //最短路径,顶点序号-长度
    bool s[G.vexnum]; //标记是否已求得最短路径
    for(auto i=0;i<G.vexnum;i++)
        s[i]=false;
    int start= LocateVex(G,v0);
    int flag=1; //标记已求得最短路径顶点数
    s[start]= true; //源点加入
    for(auto i=0;i<G.vexnum;i++){
        path[i].push_back(start);
    }
    for(auto i=0;i<G.vexnum;i++){//初始化，dist[i]为源点到i距离
        dist.insert({i,G.arcs[start][i]});
        path[i].push_back(i);
    }
    while(flag<G.vexnum){
        //找到最短路径，输出
        int i,w;    //序号，距离
        sort_by_dist(dist,i,w);
        s[i]= true; //加入S
        PrintPath(G,path[i]);
        cout<<"\t\t distance:"<<w<<endl;
        dist.erase(dist.find(i));   //从dist中删除
        flag++;
        //更新
        for(auto j=0;j<G.vexnum;j++){
            if(!s[j]){
                if(G.arcs[i][j]!=INFINITY&&(w+G.arcs[i][j])<dist[j]){
                    dist[j]=w+G.arcs[i][j];
                    path[j].assign(path[i].begin(),path[i].end());//更新路径为start->...->i
                    path[j].push_back(j);   //再加上i->j
                }
            }
        }
    }
}

int main() {
    AMGraph G;
    VertexType v0;  //源点
    CreateUDN(G);
    cout<<"Input from which vertex start:";
    cin>>v0;
    Dijkstra(G,v0);
    return 0;
}
//1 2 10
//1 3 2
//3 4 2
//3 6 11
//2 5 1
//4 5 4
//4 6 6
//5 7 7
//6 7 3