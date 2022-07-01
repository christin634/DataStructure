//
// @author: Christinlj
// @date: 2022/6/30 18:20
// @description: 
//

#include"../header/AMGraph.h"
#include<stack>

//结点入度
int Indegree[MAX_VERTEX_NUM]={0};

//找到顶点在定点表中的位置，若无返回-1
int LocateVex(AMGraph G,VertexType v){
    for(auto i=0;i<G.vexnum;i++)
        if(v==G.vexs[i])
            return i;
    return -1;
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
    //输入内容为两个结点
    VertexType v1,v2;
    for(auto i=0;i<G.arcnum;i++){
        cin>>v1>>v2;
        auto x= LocateVex(G,v1),y= LocateVex(G,v2);
        G.arcs[x][y]=1;
        Indegree[y]++;
    }
}

bool TopologicalSort(AMGraph &G){
    //内容为节点序号
    stack<int> stack;
    for (int i = 0; i < G.vexnum; ++i) {//入度为0的顶点入栈
        if(Indegree[i]==0)  stack.push(i);
    }
    int cnt=0;  //记录当前已输出顶点
    while(!stack.empty()){
        int i = stack.top();
        stack.pop();
        cout<<G.vexs[i]<<' ';
        cnt++;
        //所有指向i顶点的顶点入度-1，入度为0的入栈
        for (auto j=0;j<G.vexnum;j++) {
            Indegree[j]--;
            if(Indegree[j]==0)  stack.push(j);
        }
    }
    return cnt>=G.vexnum;
}

int main() {
    AMGraph G;
    CreateDG(G);
    cout<<"TopologicalSort"<<endl;
    TopologicalSort(G);
    return 0;
}