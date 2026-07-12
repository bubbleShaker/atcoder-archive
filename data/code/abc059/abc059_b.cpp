#include <bits/stdc++.h>
using namespace std;
int main(){
    string a,b;cin>>a>>b;
    if(a.size()==b.size()){
        if(a>b){
            cout<<"GREATER"<<endl;
        }else if(a<b){
            cout<<"LESS"<<endl;
        }else{
            cout<<"EQUAL"<<endl;
        }
    }else if(a.size()<b.size()){
        cout<<"LESS"<<endl;
    }else{
        cout<<"GREATER"<<endl;
    }
    return 0;
}