#include <iostream>
using namespace std;

const int N=100010;

int a[N],s[N];

int n;

//需要复习和思考
int main(){
    cin>>n;

    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int res=0;

    for(int i=0,j=0;i<n;i++){
        s[a[i]]++;
        while(s[a[i]]>1){
            //将a[j]记录清空 后移一位
            s[a[j]]--;
            j++;
        }
        res=max(res,i-j+1);
    }

    return res;
}

