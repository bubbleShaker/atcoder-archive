#include <bits/stdc++.h>
using namespace std;
int main(){
    int a,b;cin>>a>>b;
    if(a>b&&b!=1)cout<<"Alice"<<endl;
    else if(a<b&&a==1)cout<<"Alice"<<endl;
    else if(a!=b)cout<<"Bob"<<endl;
    else cout<<"Draw"<<endl;
    return 0;
}