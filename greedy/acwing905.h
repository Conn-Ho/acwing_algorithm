#include<iostream>
#include<algorithm>
using namespace std;
const int N=100010;
int n;
struct Range{
    int l,r;
    bool operator< (const Range &w)const{
        return r<w.r;
    }
}Range[N];

int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        int a,b;
        cin>>a>>b;
        Range[i]={a,b};
    }
    sort(Range,Range+n);
    int res=0,ed=-2e9;
    for(int i=0;i<n;i++){
        if(Range[i].l>ed){
            res++;
            ed=Range[i].r;
        }
    }
    cout<<res<<endl;
    return 0;
}