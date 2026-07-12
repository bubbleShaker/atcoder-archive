#include <bits/stdc++.h>
using namespace std;
long long a,b,n;
long long calc(long long x){
    return a*x/b-a*(x/b);
}
int main(){
    cin>>a>>b>>n;
    if(n>=b){
        cout<<calc(b-1)<<endl;
    }else{
        cout<<calc(n)<<endl;
    }
    return 0;
}