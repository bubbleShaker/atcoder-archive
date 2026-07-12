#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
int main(){
    int a,b,c;cin>>a>>b>>c;
    if((b-a)==(c-b)){
        cout<<"YES"<<endl;
    }else cout<<"NO"<<endl;
    return 0;
}