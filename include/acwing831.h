#include<iostream>
using namespace std;
const int N=100010,M=1000010;
char p[N],s[M];
int n,m;
int ne[N];
int main(){
    cin>>n>>p+1;
    cin>>m>>s+1;
    for(int i=2,j=0;i<=n;i++){
        while(j && p[i]!=p[j+1]) j=ne[j];//相当于对p串自己做模式匹配
        if(p[i]==p[j+1])j++;
        ne[i]=j; 
    }

    
    for(int i=1,j=0;i<=m;i++){
        while(j && s[i] !=p[j+1] ) j=ne[j];//前缀只能从头开始，所以ne[j]保存的就是对应j位置的相等前后缀长度
        //这句代码太妙了

        if(s[i]==p[j+1]) j++;
        if(j==n){
            cout<<i-n<<" ";
            j=ne[j];
        }
    }
    return 0;
}