#include <bits/stdc++.h>
using namespace std;
long long powLL(long long a,long long b){
    long long ret=1;
    for(int i=0;i<b;i++){
        ret*=a;
    }
    return ret;
}
int main(){
    long long b;
    cin>>b;
    for(long long i=1;i<=15;i++){
        if(powLL(i,i)==b){
            cout<<i<<endl;
            return 0;
        }
    }
    cout<<-1<<endl;
    return 0;
}