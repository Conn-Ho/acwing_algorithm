#include<iostream>
#include<algorithm>

using namespace std;

const int N=100010;

 int a[N],b[N];

int n,m;

int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=0;i<m;i++){
        scanf("%d",&b[i]);
    }

    int i=0,j=0;
    while(i<n && j<m){
        if(a[i]==b[j]){
            i++;
        }
        j++;
    }

    if(i==n) puts("Yes");
    else puts("No");

}







