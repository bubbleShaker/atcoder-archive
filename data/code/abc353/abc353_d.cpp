#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using mint=modint998244353;
int64_t keta(int v){
    mint ret=0;
    while(v>0){
        v/=10;
        ret++;
    }
    return ret.val();
}
int main() {
    int64_t n;
    cin>>n;
    vector<int64_t> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    mint ans=0;
    mint rsw=a[0];
    mint x=10;
    for(int i=1;i<n;i++){
        ans+=i*a[i];
        ans+=rsw*x.pow(keta(a[i]));
        rsw+=a[i];
    }
    cout<<ans.val()<<endl;
    return 0;
}