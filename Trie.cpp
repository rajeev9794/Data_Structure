#include<bits/stdc++.h>
using namespace std;

class TrieNode 
{
    public:
        map<char,TrieNode *> Node;
        bool EndofWord;

        TrieNode()
        {
            EndofWord=false;
           // Node=new TrieNode();
        }
        void insert(string );
        void delete();
        void search();
};

void TrieNode::insert(string s)
{
    int n=s.size();

}