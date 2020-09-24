#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

class SegmentTree
{
    public:
        int *tree;
        SegmentTree()
        {
            tree=new int[100005];      
        }
        SegmentTree(int n)
        {
            tree=new int[3*n+1];
            CreateSegmentTree(0,n-1,1);
        }
        void CreateSegmentTree(int,int,int);
        void UpdateSegmentTree(int,int,int,int);
        int QuerySegemntTree(int,int,int,int);
};

void SegmentTree::CreateSegmentTree(int start,int end,int index)
{
    if(start==end)
    {
        tree[index]=1;
        return;
    }
    else
    {
        int mid=(start+end)/2;
        CreateSegmentTree(start,mid,2*index);
        CreateSegmentTree(mid+1,end,2*index+1);
        tree[index]=tree[2*index]+tree[2*index+1];
    }
    
}

void SegmentTree::UpdateSegmentTree(int pos,int start,int end,int index)
{
    if(start==end)
    {
        tree[index]-=1;
        return;
    }
    else
    {
        int mid=(start+end)/2;
        if(mid>=pos)
        {
            //Value updated on left side
            UpdateSegmentTree(pos,start,mid,2*index);
        }
        else
        {
            UpdateSegmentTree(pos,mid+1,end,2*index+1);
        }
        tree[index]=tree[2*index]+tree[2*index+1];
        
    }
    
}

int SegmentTree::QuerySegemntTree(int spaces,int start,int end,int index)
{
    if(start>end)
    return 0;
    if(start==end)
    return start;
    int left_spaces=tree[2*index];
    int right_spaces=tree[2*index+1];
    if(left_spaces>=spaces)
    return QuerySegemntTree(spaces,start,(start+end)/2,2*index);
    else
    {
        return QuerySegemntTree(spaces-left_spaces,(start+end)/2+1,end,2*index+1);
    }
    
    
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<pair<int,int> > v(n);
        for(int i=0;i<n;i++)
        {
            cin>>v[i].first;
        }
        for(int i=0;i<n;i++)
        cin>>v[i].second;

        sort(v.begin(),v.end());

        SegmentTree s(n);
       // s.CreateSegmentTree(0,n-1,1);
        vector<int> ans(n);
        for(int i=0;i<n;i++)
        {
            int index=s.QuerySegemntTree(v[i].second+1,0,n-1,1);
            ans[index]=v[i].first;
            s.UpdateSegmentTree(index,0,n-1,1);
        }

        for(int i=0;i<n;i++)
        cout<<ans[i]<<" ";
        cout<<endl;
    }
}