#include<bits/stdc++.h>
using namespace std;
/*
On Creation of Disjoint set Lets look each step significantly
1) Union by rank
2) Path Compression 
    Two logic for path compression
    1)Movement of parent pointer means in a group all have a same representative element
    
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
            rank=1;
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
        Node * FindParent(Node *);
        Node * FinNodeValue(int);
};

void DisjointSet::CreateSet(int node)
{
    Node *p=new Node(node);
    mp[node]=p;
}
//Path compression is applicable here
Node * DisjointSet::FindParent(Node *p)
{
    //Node *p=mp[node];

    if(p->parent==p)
    {
       return p;
    }
    else
    {
        return p->parent=FindParent(p->parent);
    }
    
}
Node * DisjointSet::FinNodeValue(int x)
{
    return mp[x];
}
void DisjointSet::Union(int node1,int node2)
{
     Node *n1=mp[node1];
     Node *n2=mp[node2];
     Node *par1=FindParent(n1);
     Node *par2=FindParent(n2);

     if(par1->rank<=par2->rank)
     {
        // mp[node1]=par2;

         par2->rank+=par1->rank;
         par1->parent=par2;
     }
     else if (par1->rank>par2->rank)
     {
         //mp[node2]=par1;
         par1->rank+=par2->rank;
         par2->parent=par1;
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
        if(ds.FindParent(ds.FinNodeValue(x))==ds.FindParent(ds.FinNodeValue(y)))
        {
            cout<<"Same loop\n";
        }
        else
        {
            cout<<"In different loop\n";
        }
        
    }

}
