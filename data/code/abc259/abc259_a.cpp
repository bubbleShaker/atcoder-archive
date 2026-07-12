#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m,x,t,d;cin>>n>>m>>x>>t>>d;
    if(x<=m&&m<=n){
        cout<<t<<endl;
    }else{
        cout<<t-(x-m)*d<<endl;
    }
    return 0;
}