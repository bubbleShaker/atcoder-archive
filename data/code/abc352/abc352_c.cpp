#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
int main() {
    int n;
    cin>>n;
    vector<long long> a(n),b(n);
    fenwick_tree<long long> fw(n);
    for(int i=0;i<n;i++){
        cin>>a[i]>>b[i];
        fw.add(i,a[i]);
    }
    long long ans=0;
    for(int i=0;i<n;i++){
        fw.add(i,-a[i]);
        long long s=fw.sum(0,n);
        ans=max(ans,s+b[i]);
        fw.add(i,a[i]);
    }
    cout<<ans<<endl;
    return 0;
}