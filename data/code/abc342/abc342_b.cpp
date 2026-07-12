#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;cin>>n;
    map<int,int> ValIndMap;
    for(int i=0;i<n;i++){
        int p;cin>>p;
        ValIndMap[p]=i;
    }
    int q;cin>>q;
    while(q--){
        int a,b;cin>>a>>b;
        if(ValIndMap[a]<ValIndMap[b]){
            cout<<a<<endl;
        }else{
            cout<<b<<endl;
        }
    }
    return 0;
}