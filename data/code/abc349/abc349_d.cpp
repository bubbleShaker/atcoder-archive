#include <bits/stdc++.h>
using namespace std;
int main() {
    long long l,r;
    cin>>l>>r;
    vector<pair<long long,long long>> ret;
    while(l<r){
        for(int i=60;i>=0;i--){
            if(l%(1ll<<i)==0&&l+(1ll<<i)<=r){
                ret.push_back({l,l+(1ll<<i)});
                l+=(1ll<<i);
                break;
            }
        }
    }
    int m=ret.size();
    cout<<m<<endl;
    for(auto [al,ar]:ret){
        cout<<al<<" "<<ar<<endl;
    }
    return 0;
}