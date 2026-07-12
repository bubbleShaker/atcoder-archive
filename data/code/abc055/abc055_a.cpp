#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;cin>>n;
    int ans=0;
    ans+=800*n;
    ans-=200*(n/15);
    cout<<ans<<endl;
    return 0;
}