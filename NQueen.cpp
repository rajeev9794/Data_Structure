
#include<bits/stdc++.h>
#include<algorithm>
using namespace std;



void solve(int current,vector<vector<string> > &a,pair<int,int> position[],int n)
{
    if(current==n)
    {
        vector<string>s;
        for(int j=0;j<n;j++)
        {
            string s1;
            for(int i=0;i<n;i++)
            {
                if(position[j].second==i)
                s1.push_back('Q');
                else
                s1.push_back('.');
            }
            s.push_back(s1);
        }
        a.push_back(s);
        
        return ;
    }
    
    for(int i=0;i<n;i++)
    {
        bool safeposition=true;
        for(int j=0;j<current;j++)
        {
            if(position[j].second==i || position[j].second+position[j].first==i+current || position[j].second-position[j].first==i-current)
            {
                safeposition=false;
                break;
            }
        }
        
        if(safeposition)
        {
            position[current].first=current;
            position[current].second=i;
            solve(current+1,a,position,n);
        }
    }

}
vector<vector<string> > solveNQueens(int A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details
    vector<vector<string> >a;
    //Position *p;
    pair<int,int> p[A];
    //vector<Position>p(A);
    solve(0,a,p,A);
    return a;

}


void Display(vector<vector<string> > &s)
{
    for(int i=0;i<s.size();i++)
    {
        for(int j=0;j<s[i].size();j++)
        {
            cout<<s[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<string> >s;
        s=solveNQueens(n);
        Display(s);
        cout<<endl;
    }
}