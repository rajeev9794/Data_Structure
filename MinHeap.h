#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
class MinHeap
{
private:
    /* data */
    int capacity;
    int *arr;
public:
    int size;
    MinHeap(int n)
    {
        capacity=n;
        size=0;
        arr=new int[n];
    }
    ~MinHeap()
    {
        delete[] arr;
    }
    void insert(int );
    void swap(int &,int &);
    void Delete();
    void Min();
    void Heapify();
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
    while(i!=0 && arr[(i-1)/2]<x)
    {
        swap(arr[i],arr[(i-1)/2]);
        i=(i-1)/2;
    }

}
void MinHeap::Heapify(int i)
{
    int id=i;
    if(2*i+1<size && arr[2*i+1]<arr[i])
    id=2*i+1;
    if(2*i+2<size && arr[2*i+2]<arr[id])
    id=2*i+2;

    if(id!=i)
    {
        swap(arr[id],arr[i]);
        Heapify(id);
    }
}
void MinHeap::Delete()
{
    arr[0]=arr[size-1];
    size--;
    Heapify(0);
}
int MinHeap::Min()
{
    return arr[0];
}



