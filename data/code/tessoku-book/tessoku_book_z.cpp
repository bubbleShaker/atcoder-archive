#include <bits/stdc++.h>
using namespace std;
bool is_prime(int n){
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            return false;
        }
    }
    return true;
}
int main(){
    int q;
    cin>>q;
    while(q--){
        int x;
        cin>>x;
        if(is_prime(x)){
            cout<<"Yes"<<endl;
        }else{
            cout<<"No"<<endl;
        }
    }
    return 0;
}