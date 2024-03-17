#include<iostream>
#include<algorithm>
using namespace std;
const int N=200010;
int n;
int a[N];
int main(){
    cin>>n;
    while(n--){
        int x;
        cin>>x;

        for(int i=1;i<=x;i++){
            cin>>a[i];
        }
        sort(a,a+x+1);
        //  for(int i=1;i<=x;i++){
        //       cout<<a[i]<<" ";
        //   }
        //  cout<<endl;
        int cnt;
        for(int i=0;i<=x;i++){
            if(a[i]!=a[i-1] && (a[i]-a[i-1]<x)){cnt++;}
        }
        cout<<cnt<<endl;
        cnt=0;
    }

}