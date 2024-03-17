#include<iostream>
#include<algorithm>
using namespace std;
const int N=50010;
typedef pair<int,int> PII;
PII cows[N];
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int w,s;
        cin>>w>>s;
        cows[i]={w+s,w};
    }
    sort(cows,cows+n);
    int res=-2e9,sum=0;
    for(int i=0;i<n;i++){
        int w=cows[i].second,s=cows[i].first-w;
        res=max(res,sum-s);
        sum+=w;
    }
    cout<<res;
    return 0;
}