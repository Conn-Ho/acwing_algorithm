#include<iostream>
#include<algorithm>
using namespace std;
const int N=100010;
int a[N];

int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    int ans;
    for(int i=0;i<n;i++){
        ans+=abs(a[i]-a[n/2]);
    }
    cout<<ans;
    return 0;
}