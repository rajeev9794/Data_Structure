#include<bits/stdc++.h>
#include<algorithm>
#define ll long long int
using namespace std;

class TrieNode
{
    public: 
       map<int,TrieNode *> node;
       bool EndofWord;

       TrieNode()
       {
           EndofWord=false;
       }
};

class Trie
{
    public:
        TrieNode *root;
        Trie()
        {
            root=new TrieNode();
        }
        void insert(int);
        ll search(int);
        void Delete(int);
};

void Trie::insert(int x)
{
    TrieNode *curr=root;
    for(int i=31;i>=0;i--)
    {
        int val=(1<<i & x)==0?0:1;
        TrieNode *p=curr->node[val];
        if(p==NULL)
        {
            p=new TrieNode();
            //p->node[val]
            curr->node[val]=p;
        }
        curr=p;
    }
    curr->EndofWord=true;
}

ll Trie::search(int x)
{
    TrieNode *curr=root;
    long long int ans=0;
    for(int i=31;i>=0;i--)
    {
        int val=(1<<i & x)==0?1:0;
        TrieNode *p=curr->node[val];
        if(p==NULL)
        {
            if(val==0)
            {ans+=(1<<i);
            curr=curr->node[1];
            }
            else
            {
                curr=curr->node[0];
            }
            
        }
        else
        {
            ans+=((1<<i)*val);
            curr=curr->node[val];
        }

        
    }
    return ans;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        int a[n],b[m];
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        Trie tr;
        for(int i=0;i<n;i++)
        {
            tr.insert(a[i]);
        }

        for(int i=0;i<m;i++)
        cin>>b[i];

        ll ans=0;
        for(int i=0;i<m;i++)
        {
            ll tmp=tr.search(b[i]);
            //cout<<b[i]<<"  "<<tmp<<endl;
            ans=max(ans,tmp^b[i]);
        }
        cout<<ans<<endl;

    }
}