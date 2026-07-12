#include <bits/stdc++.h>
using namespace std;

long long keta(long long n){
    if(n==0){
        return 0;
    }
    long long res=0;
    while(n>0){
        res++;
        n/=10;
    }
    return res;
}

int main(){
    long long a,b,x;cin>>a>>b>>x;
    long long ok=0,ng=(long long)1e9;
    while(abs(ok-ng)>1){
        long long i=(ok+ng)/2;
        // cout<<"i:"<<i<<endl;
        if(a*i+b*keta(i)<=x){
            ok=i;
            // cout<<"ok"<<endl;
        }else{
            ng=i;
            // cout<<"ng"<<endl;
        }
    }
    if(a*ng+b*keta(ng)<=x){
        ok=ng;
    }
    if(ok==0){
        cout<<0<<endl;
    }else{
        cout<<ok<<endl;
    }
    return 0;
}