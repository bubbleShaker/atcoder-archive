#include <bits/stdc++.h>
using namespace std;

int main(){
    int a,b;cin>>a>>b;
    if(abs(a)<abs(b))cout<<"Ant"<<endl;
    else if(abs(a)>abs(b))cout<<"Bug"<<endl;
    else cout<<"Draw"<<endl;
    return 0;
}