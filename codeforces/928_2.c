#include<iostream>
#include<string>
using namespace std;
int t;
int main(){
    cin>>t;
    int num=0;
    string str;
    int line;

    while(t--){
        cin>>line;
        while(line--){
            getline(cin,str);
             for(int i=0;i<str.size();i++){
                 if(str[i]=='1'){
                num++;
                  }
                   if(num == 1){
                 cout<<"TRIANGLE"<<endl;
          }


        }
             num=0;
   
        }

             cout<<"SQUARE"<<endl;
        }

    return 0;
}