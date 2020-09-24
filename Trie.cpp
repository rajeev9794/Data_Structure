#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

class TrieNode 
{
    public:
        map<char,TrieNode *> Node;
        bool EndofWord;
        
        TrieNode()
        {
            //Node =new map<char,TrieNode *>();
            EndofWord=false;
           // Node=new TrieNode();
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
        bool search(string);
        void Delete(string);
        void display();
};
void Trie::insert(string s)
{
    int n=s.size();
    TrieNode *curr=root;
    for(int i=0;i<n;i++)
    {
        char c=s[i];
        TrieNode *p=curr->Node[c];
        if(p==NULL)
        {
            p=new TrieNode();
            curr->Node[c]=p;            
        }
        curr=p;

    }
    curr->EndofWord=true;
}
bool Trie::search(string s)
{
    TrieNode *curr=root;
    int i=0;
    while(!curr->EndofWord && i<s.size())
    {
        curr=curr->Node[s[i]];
        i++;
        //cout<<"i="<<i<<endl;
        if(curr==NULL)
        return false;

    }
    if(i==s.size() && curr->EndofWord)
    return true;
    else
    {
        return false;
    }
    
}
void Trie::display()
{
    TrieNode *curr=root;
    while(!curr->EndofWord)
    {
        
        char ch;
        for(auto it=curr->Node.begin();it!=curr->Node.end();it++)
        {
            cout<<it->first<<" ";
            ch=it->first;
            break;
        }
        curr=curr->Node[ch];

    }
}
void Trie::Delete(string s)
{
    TrieNode *curr=root;
    for(int i=0;i<s.size();i++)
    {
        curr=curr->Node[s[i]];
        if(curr==NULL)
        {
            cout<<"Deletion Not Possible\n";
            return ;
        }
    }
    if(curr->EndofWord==true)
    {curr->EndofWord=false;
    cout<<"Element Deleted\n";
    }
    else
    {
        cout<<"Not find for deletion \n";
    }
    
}
int main()
{
    Trie p;
    //=new Trie();
    string s;
    int t;
    cin>>t;
    while(t--)
    {
    cin>>s;
    p.insert(s);
    }
    cin>>t;
    cout<<"Enter test case for search\n";
    while(t--)
    {
        string s;
        cin>>s;
        if(p.search(s))
        {
         cout<<"find\n";
        }
        else
        {
            cout<<"Not find\n";
        }
        p.Delete(s);
    }
}