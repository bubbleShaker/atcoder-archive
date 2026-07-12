#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<bool> isPrime(n+1,true);
    for(int i=2;i<=n;i++){
        if(isPrime[i]==false)continue;
        for(int j=2;i*j<=n;j++){
            isPrime[i*j]=false;
        }
    }
    for(int i=2;i<=n;i++){
        if(isPrime[i]){
            cout<<i<<endl;
        }
    }
    return 0;
}