    #include<iostream>
    using namespace std;
    const int N=100010;
    int n;
    int k;
    int a[N];
    int quick_sort_k(int a[],int l,int r,int k){
        int i=l-1,j=r+1;
        int x=a[(l+r)/2];
        if(l>=r) return a[l];
        while(i<j){
            while(a[++i]<x);
            while(a[--j]>x);
            if(i<j) swap(a[i],a[j]);
        }
        int sl=j-l+1;
        if(k<=sl){return quick_sort_k(a,l,j,k);}
        else{
            return quick_sort_k(a,j+1,r,k-sl);
        }
    }
    int main(){
        cin>>n>>k;
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        cout<<quick_sort_k(a,0,n-1,k);
        return 0;
    }