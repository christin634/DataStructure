//
// @author: Christinlj
// @date: 2022/6/23 14:45
// @description: 图-邻接表
//

#include"../header/AMGraph.h"
#include<queue>
#include<stack>
//找到顶点在定点表中的位置，若无返回-1
int LocateVex(AMGraph G,VertexType v){
    for(auto i=0;i<G.vexnum;i++)
        if(v==G.vexs[i])
            return i;
    return -1;
}

//创建无向图
void CreateUDG(AMGraph &G){
    cout<<"Please input the number of vertex and arc:";
    cin>>G.vexnum>>G.arcnum;
    cout<<"Please input information about "<<G.vexnum<<" vertexs:";
    for(auto i=0;i<G.vexnum;i++)
        cin>>G.vexs[i];
    //初始化邻接矩阵，全部置为0
    for(auto i=0;i<G.vexnum;i++)
        for(auto j=0;j<G.vexnum;j++){
            G.arcs[i][j]=0;
        }
    cout<<"Please input arc's imformation:\n";
    //输入内容为两个结点
    VertexType v1,v2;
    for(auto i=0;i<G.arcnum;i++){
        cin>>v1>>v2;
        auto x= LocateVex(G,v1),y= LocateVex(G,v2);
        G.arcs[x][y]=G.arcs[y][x]=1;
    }
}
//创建有向图
void CreateDG(AMGraph &G){
    cout<<"Please input the number of vertex and arc:";
    cin>>G.vexnum>>G.arcnum;
    cout<<"Please input information about "<<G.vexnum<<" vertexs:";
    for(auto i=0;i<G.vexnum;i++)
        cin>>G.vexs[i];
    //初始化邻接矩阵，全部置为0
    for(auto i=0;i<G.vexnum;i++)
        for(auto j=0;j<G.vexnum;j++){
            G.arcs[i][j]=0;
        }
    cout<<"Please input arc's imformation:\n";
    //输入内容为两个结点,同一条边无需输入两次
    VertexType v1,v2;
    for(auto i=0;i<G.arcnum;i++){
        cin>>v1>>v2;
        auto x= LocateVex(G,v1),y= LocateVex(G,v2);
        G.arcs[x][y]=1;
    }
}
void Print(AMGraph G){
    for(auto i=0;i<G.vexnum;i++){
        cout<<G.vexs[i]<<":";
        for(auto j=0;j<G.vexnum;j++){
            cout<<G.arcs[i][j]<<' ';
        }
        cout<<endl;
    }
}

//找到顶点v的第一个邻接点，返回索引，无则返回-1
int FirstNeighbor(AMGraph G,int v){
    for(auto i=0;i<G.vexnum;i++)
        if(G.arcs[v][i]==1)
            return i;
    return -1;
}
//找到顶点v的在w之后的邻接点，返回索引，无则返回-1
int NextNeighbor(AMGraph G,int v,int w){
    for(auto i=w+1;i<G.vexnum;i++)
        if(G.arcs[v][i]==1)
            return i;
    return -1;
}
bool visited[MAX_VERTEX_NUM];   //访问标记数组
//BFS搜索图G
void BFSTraverse(AMGraph G){
    for(auto i=0;i<G.vexnum;i++)
        visited[i]= false;
    for(auto i=0;i<G.vexnum;i++)
        if(!visited[i])
            BFS(G,i);
}
//BFS搜索图G,从顶点v(v为索引)开始
void BFS(AMGraph G,int v){
    queue<int> q;
    visit(G,v);
    visited[v]= true;
    q.push(v);
    while(!q.empty()){
        //顶点出列
        v = q.front();
        q.pop();
        //访问v的所有邻接点
        for(auto w= FirstNeighbor(G,v);w>=0;w= NextNeighbor(G,v,w))
            if (!visited[w]) {
                visit(G, w);
                visited[w] = true;
                q.push(w);
            }
    }
}
//访问顶点v
void visit(AMGraph G,int  v){
    cout<<G.vexs[v]<<' ';
}

//DFS搜索图G
void DFSTraverse(AMGraph G){
    for(auto i=0;i<G.vexnum;i++)
        visited[i]= false;
    for(auto i=0;i<G.vexnum;i++)
        if(!visited[i])
            DFS(G,i);
}
//DFS搜索图G,从顶点v(v为索引)开始
void DFS(AMGraph G,int v){
    visit(G,v);
    visited[v]= true;
    for(auto w= FirstNeighbor(G,v);w>=0;w= NextNeighbor(G,v,w))
        if(!visited[w])
            DFS(G,w);
}

//从v开始，非递归DFS
void DFS_Non_RC(AMGraph G,int v){
    //访问标记数组，记录是否已经入过栈
    for(auto i=0;i<G.vexnum;i++)
        visited[i]= false;
    stack<int> stack;
    stack.push(v);
    visited[v]= true;
    while(!stack.empty()){
        auto p=stack.top();
        stack.pop();    //出栈后访问
        visit(G,p);
        for(auto w= FirstNeighbor(G,p);w>=0;w= NextNeighbor(G,p,w))
            if(!visited[w]){//未入过栈的，先入栈
                stack.push(w);
                visited[w]= true;
            }
    }
}

int main() {
    AMGraph G;
    int graphKind;
    cout<<"Choose to create what kind of graph:\n";
    cout<<"0.Directed Graph\n1.Undirected Graph\n";
    cin>>graphKind;
    switch(graphKind){
        case DG:
            CreateDG(G);break;
        case UDG:
            CreateUDG(G);break;
        default:break;
    }
    cout<<"Matrix:\n";
    Print(G);
    cout<<"BFS:\n";
    BFSTraverse(G);
    cout<<"\nDFS:\n";
    DFSTraverse(G);
    cout<<"\nNon_Recursion_DFS:\n";
    DFS_Non_RC(G,0);
    return 0;
}