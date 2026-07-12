#include <bits/stdc++.h>
using namespace std;
const long long INF=(long long)1e18;
int main() {
    long long n,a,b;
    cin>>n>>a>>b;
    const long long MOD=a+b;
    long long ma=-INF,mi=INF;
    long long mad=-INF;
    set<long long> st;
    vector<long long> d(n);
    for(int i=0;i<n;i++){
        cin>>d[i];
    }
    long long sb=d[0]-1;
    for(int i=0;i<n;i++){
        // d[i]-=sb;
        d[i]%=MOD;
        if(d[i]==0){
            d[i]=MOD;
        }
        st.insert(d[i]);
        // cout<<d[i]<<" \n"[i+1==n];
        ma=max(ma,d[i]);
        mi=min(mi,d[i]);
    }
    vector<long long> v(st.begin(),st.end());
    int m=v.size();
    for(int i=0;i<m-1;i++){
        mad=max(mad,v[i+1]-v[i]-1);
    }
    long long cmp=min(ma-mi+1,MOD-mad);
    if(cmp<=a){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }
    return 0;
}