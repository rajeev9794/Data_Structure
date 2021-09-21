/*
We have to find the longest substring which is also a prefix of a given string
z(i)  it represents the length of string which is prefix of a given string and also substring of string whose
starting position is i and having a length of z(i).
aabxcaabxde
|__| |__|  we are getting this type of box
Running Time of this algo is O(n) because by Amortized analysis we find this algo
*/

#include<bits/stdc++.h>
using namespace std;
vector<int> Z_Algorithm(string s)
{
    int len=s.size();
    vector<int>v(len,0);
    int l=0,r=0;
    for(int i=1;i<len;i++)
    {
        if(i<=r)
        {
            v[i]=min(r-i+1,v[i-l]);
        }
        while(i+v[i]<len && s[v[i]]==s[i+v[i]])
        v[i]++;
        if(i+v[i]-1>r)
        {
            l=i;
            r=i+v[i]-1;
        }
    }
    return v;
}
/*
void Cal()
{
    string s;
    cin>>s;
    vector<int>v;
    v=Z_Algorithm(s);
    int len=v.size();
    unordered_map<int,pair<int,int> >mp;
    for(int i=1;i<len;i++)
    {
        if(mp.find(v[i])==mp.end())
        {
            
        }
    }
}*/
int CountStringFrequency(string target,string pattern)
{
    vector<int>v;
    string res=pattern+"$"+target;
    v=Z_Algorithm(res);
    int len=pattern.size(),n=res.size(),ans=0;
    for (int i = len; i < n; i++)
    {
        if(v[i]==len)
        ans++;
    }
    return ans;
    
}

int main()
{
    #ifndef ONLINE_JUDGE 
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
    #endif 
    int t;
    cin>>t;
    while(t--)
    {
        string s,pat;
        cin>>s>>pat;
        int ans=CountStringFrequency(s,pat);
        cout<<ans<<endl;
        /*
        vector<int>v;
        v=Z_Algorithm(s);
        for(int i=0;i<v.size();i++)
        cout<<v[i]<<" ";
        cout<<endl;*/
    }
}