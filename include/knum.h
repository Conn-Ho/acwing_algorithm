#include<iostream>

using namespace std;

const int N=100000;

int q[N];

int n,k;


int quick_sort(int l,int r,int k){
    if(l==r) return q[l];

    int x=q[(l+r)/2],i=l-1,j=r+1;

    while(i<j){
        while(q[++i]<x);
        while(q[--j]>x);
        if(i<j){swap(q[i],q[j]);}
    }

    int sl=j-l+1;
    if(k<=sl){return quick_sort(l,j,k);}
    else{
        return quick_sort(j+1,r,k-sl);
    }
}

//int main(){
//
//    cin>>n;
//    cin>>k;
//    for(int i=0;i<n;i++){
//        cin>>q[i];
//    }
//
//    cout<<quick_sort(0,n-1,k)<<endl;
//
//    return 0;
//
//}