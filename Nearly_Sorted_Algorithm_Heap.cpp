#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

class MinHeap
{
    public:
        int *arr;
        int capacity;
        int size;
        MinHeap(int n)
        {
            arr=new int[n];
            capacity=n;
            size=0;
        }
        ~MinHeap()
        {
            delete[] arr;
        }

        void swap(int &,int &);
        void insert(int);
        void DeleteTop();
        void Heapify(int );
        int  MinElement();
};
void MinHeap::swap(int &x,int &y)
{
    int t=x;
    x=y;
    y=t;
}
void MinHeap::insert(int x)
{
    int i=size;
    size++;
    arr[i]=x;
    while(i!=0 && arr[(i-1)/2]>x)
    {
        swap(arr[i],arr[(i-1)/2]);
        i=(i-1)/2;
    }
}
int MinHeap::MinElement()
{
    return arr[0];
}
void MinHeap::DeleteTop()
{
    arr[0]=arr[size-1];
    size--;
    Heapify(0);
}
void MinHeap::Heapify(int i)
{
    int id=i;
    if(2*i+1<size && arr[2*i+1]<arr[i])
    {
        id=2*i+1;
    }
    if(2*i+2<size && arr[2*i+2]<arr[id])
    {
        id=2*i+2;
    }

    if(id!=i)
    {
        swap(arr[i],arr[id]);
        Heapify(id);
    }
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        int a[n];
        for(int i=0;i<n;i++)
        cin>>a[i];
        MinHeap h(n);
        for(int i=0;i<k;i++)
        {
            h.insert(a[i]);

        }
        vector<int>v;
        int i=k;
        while(h.size!=0)
        {
            v.push_back(h.MinElement());
            h.DeleteTop();
            if(i<n)
            {
            h.insert(a[i]);
            i++;
            }
        }

        for(int i=0;i<n;i++)
        cout<<v[i]<<" ";
        cout<<endl;
    }
}