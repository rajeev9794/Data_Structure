#include<bits/stdc++.h>
using namespace std;
/*
On Creation of Disjoint set Lets look each step significantly
1) Union by rank
2) Path Compression 
    Two logic for path compression
    1)Movement of parent pointer means in a group all have a same representative element
    2)
*/
class Node
{
    public:
        int rank;
        int data;
        Node *parent;

        Node(int val)
        {
            data=val;
            rank=0;
            parent=this;

        }

};

class DisjointSet
{
    private:
        unordered_map<int ,Node *>mp;

    public:    
        void CreateSet(int);
        void Union(int,int);
        Node * FindParent(int);
};

void DisjointSet::CreateSet(int node)
{
    Node *p=new Node(node);
    mp[node]=p;
}
//Path compression is applicable here
Node * DisjointSet::FindParent(int node)
{
    Node *p=mp[node];

    if(p->data!=node)
    {
        return mp[node]=FindParent(p->data);
    }
    else
    {
        return p;
    }
    
}
void DisjointSet::Union(int node1,int node2)
{
     Node *par1=FindParent(node1);
     Node *par2=FindParent(node2);

     if(par1->rank<=par2->rank)
     {
         mp[node1]=par2;
         par2->rank+=1;
     }
     else if (par1->rank>par2->rank)
     {
         mp[node2]=par1;
         par1->rank+=1;
     }
}

int main()
{
    int n;
    cin>>n;
    DisjointSet ds;
    int x,y;
    for(int i=0;i<n;i++)
    {
        cin>>x>>y;
        ds.CreateSet(x);
        ds.CreateSet(y);
        ds.Union(x,y);
    }
    //Query Processing

    for(int i=0;i<5;i++)
    {
        cin>>x>>y;
        if(ds.FindParent(x)==ds.FindParent(y))
        {
            cout<<"Same loop\n";
        }
        else
        {
            cout<<"In different loop\n";
        }
        
    }

}
