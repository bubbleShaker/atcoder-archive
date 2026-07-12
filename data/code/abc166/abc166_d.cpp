#include <bits/stdc++.h>
using namespace std;

long long powLong(long long a,long long n){
    long long res=1;
    while(n>0){
        res*=a;
        n--;
    }
    return res;
}

int main(){
    long long x;cin>>x;
    for(long long a=1;a<=(long long)1e2;a++){
        for(long long b=1;b<=(long long)1e2;b++){
            if(powLong(a,5)+powLong(b,5)==x){
                cout<<a<<" "<<-b<<endl;
                return 0;
            }
        }
    }
    for(long long a=1;a<=120;a++){
        for(long long b=0;b<a;b++){
            if(powLong(a,5)-powLong(b,5)==x){
                cout<<a<<" "<<b<<endl;
                return 0;
            }
        }
    }
    return 0;
}