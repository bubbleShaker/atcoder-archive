#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,q;
    cin>>n>>q;
    vector<long long> r(n);
    for(int i=0;i<n;i++){
        cin>>r[i];
    }
    sort(r.begin(),r.end());
    vector<long long> rsw(n+1);
    for(int i=0;i<n;i++){
        rsw[i+1]+=rsw[i]+r[i];
    }
    while(q--){
        long long x;
        cin>>x;
        int ind=lower_bound(rsw.begin(),rsw.end(),x)-rsw.begin();
        if(rsw[ind]>x)ind--;
        if(ind==n+1)ind--;
        cout<<ind<<endl;
    }
    return 0;
}