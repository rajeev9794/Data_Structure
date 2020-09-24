#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


//Logic for finding cycle in the graph is
//Intially all nodes mark with 0 then when starting traversal mark the node with 1 and when
//exit from dfs mark as 2 and then during trrversal if we find any vertices which is having not exited from
// dfs then cycle exits.

//DFS O(m) space and time m is number of edges
class UnDirectedGraph
{
    public:
        int vertices,edges;
        int *color;
        int *parent;
        int start_cycle,end_cycle;
        vector<int> *edge;
        UnDirectedGraph(int n,int m)
        {
            edges=m;
            vertices=n;
            color=new int[n];
            color[n]={0};
            edge=new vector<int>[n];
            parent=new int[n];
            for(int i=0;i<n;i++)
            parent[i]=-1;
            start_cycle=-1;
            end_cycle=-1;
        }
        bool DfsCycleDetection(int,int);
        void FindCycle();

};
bool UnDirectedGraph::DfsCycleDetection(int start,int par)
{
    //In time for dfs
    color[start]=1;
    for(auto u:edge[start])
    {
        if(par==u)    //For skipping the parent edge within the graph
        continue;
        if(color[u]==0)
        {
            parent[u]=start;
            if(DfsCycleDetection(u,start))
                return true;
        }
        else if(color[u]==1)
        {
            //Cycle found
            start_cycle=u;
            end_cycle=start;
            return true;
            
        }
        
    }
    color[start]=2;
    return false;
}

void UnDirectedGraph::FindCycle()
{
    int cycle_found=-1;

    for(int i=0;i<vertices;i++)
    {

        if(color[i]==0 && DfsCycleDetection(i,parent[i]))
        {
            cycle_found=1;
            break;
        }
    }
    if(cycle_found==-1)
    {
        cout<<"Acyclic"<<endl;
    }
    else
    {
        cout<<"Cycle exist\n";
        while(start_cycle!=end_cycle)
        {
            cout<<end_cycle<<" ";
            end_cycle=parent[end_cycle];
        }
        cout<<start_cycle<<endl;
    }
    
       
}
int main()
{
    int n,m;
    cin>>n>>m;
    UnDirectedGraph g(n,m);
    for(int i=0;i<m;i++)
    {
        int x,y;
        cin>>x>>y;
        
        g.edge[x].push_back(y);
        g.edge[y].push_back(x);
    }
    g.FindCycle();
}