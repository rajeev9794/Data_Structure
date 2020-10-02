//This algo tells that we have to find minimum distance to all position to every other  remaining position
//This is Developed by Floyd 
// It's approach is Dynamic Programming concept which we used to develop for solution 
// if we want to move from u to v via intermediate node w 
// if dis[u][v]>dis[u][w]+dis[v][w] then we update value of dis[u][v]
// This solution is O(n^3) solution to find minimum distance from starting node to every other node. 
// What are the optimization technic we need to apply here to find out the result of problem. 

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int test;
    cin>>test;
    while(test--)
    {
        int vertices;
        cin>>vertices;
        vector<vector<int> > edges(vertices,vector<int> (vertices)),dis(vertices,vector<int>(vertices));
        //edge[i][j] shows the connected component of graph
        //if edge[i][j]=1e9+7 it is not connected else they have some weight of connected component

        const int mx=1e7;
        for (int i = 0; i < vertices; i++)
        {
            for (int j = 0; j < vertices; j++)
            {
                /* code */
                cin>>edges[i][j];
                dis[i][j]=edges[i][j];
            }
            
        }


        //Compute shortest path
    for(int k=0;k<vertices;k++)
    {
        for (int i = 0; i < vertices; i++)
        {
            /* code */
            if(dis[i][k]!=INT_MAX)
            {
                 for(int j=0;j<vertices;j++)
                {
                
                    if(dis[k][j]!=mx && dis[i][j]>dis[i][k]+dis[k][j])
                    {
                        dis[i][j]=dis[i][k]+dis[k][j];
                    }
                }

            }
        }
    }
        for(int i=0;i<vertices;i++)
        {
            for(int j=0;j<vertices;j++)
            cout<<dis[i][j]<<" ";
            cout<<endl;
        }
        cout<<endl;
        


        

    }
}