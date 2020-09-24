#include<bits/stdc++.h>
#include<algorithm>
using namespace std;



class TrieNode
{
    public:
        map<char,TrieNode * > node;
        map<char,int> Char_freq;
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
        void insert(string);
        string Search(string);
};

void Trie::insert(string s)
{
        TrieNode *curr=root;
        for(int i=0;i<s.size();i++)
        {
            TrieNode *p=curr->node[s[i]];
            if(p==NULL)
            {
                p=new TrieNode();
                curr->node[s[i]]=p;
                curr->Char_freq[s[i]]++;
                //cout<<curr->node[s[i]]<<endl;
            }
            else
            {
                curr->Char_freq[s[i]]++;
                //cout<<"here\n";
            }
            
            curr=p;
        }
        curr->EndofWord=true;
}

string Trie::Search(string s)
{
    TrieNode *curr=root;
    string res;
    int i=0,n=s.size();
    while(i<n)
    {
        if(curr->Char_freq[s[i]]>1)
        {
            res.push_back(s[i]);
           
            curr=curr->node[s[i]];
            i++;
            
        }
        else if(curr->Char_freq[s[i]]==1)
        {
            res.push_back(s[i]);
            i++;
            break;
        }
    }
    //cout<<"res="<<res<<endl;
    return res;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        int n;
        cin>>n;
        vector<string>v;
        for(int i=0;i<n;i++)
        {
            cin>>s;
            v.push_back(s);
        }

        vector<string>res;
        Trie tr;
        for(int i=0;i<n;i++)
        tr.insert(v[i]);

        for(int i=0;i<n;i++)
        {
            res.push_back(tr.Search(v[i]));
        }
        for(int i=0;i<n;i++)
        {
            cout<<res[i]<<endl;
        }
    }
}