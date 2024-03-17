#include<iostream>
using namespace std;
const int N=1010;
int n;
int main(){
    cin>>n;
    int a,b;
    while(n--){
        cin>>a>>b;
        int c=max(a,b);
        int d=min(a,b);
        if((c=d*2)&&(d%2==1)){cout<<"No"<<endl;}
        else{
            cout<<"Yes"<<endl;
        }
    }
    return 0;
}