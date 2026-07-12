#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    long long k;
    cin>>n>>k;
    vector<int> a(n);
    vector<long long> b(n);
    for(int i=0;i<n;i++){
        cin>>a[i]>>b[i];
    }
    map<int,long long> mp;
    for(int i=0;i<n;i++){
        mp[a[i]]+=b[i];
    }
    for(auto [val,cnt]:mp){
        if(k-cnt<=0){
            cout<<val<<endl;
            return 0;
        }else{
            k-=cnt;
        }
    }
    return 0;
}