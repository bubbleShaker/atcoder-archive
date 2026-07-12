#include <bits/stdc++.h>
using namespace std;
int main() {
    const int64_t MOD=1e8;
    int64_t n;
    cin>>n;
    vector<int64_t> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    int64_t ans=0;
    for(int i=0;i<n;i++){
        ans+=(n-1)*a[i];
    }
    int64_t cnt=0;
    for(int i=0;i<n;i++){
        if(a[i]*2>=MOD){
            cnt+=n-(i+1);
        }else{
            int64_t sv=MOD-a[i];
            int64_t ind=lower_bound(a.begin(),a.end(),sv)-a.begin();
            cnt+=n-ind;
        }
    }
    ans-=cnt*MOD;
    cout<<ans<<endl;
    return 0;
}