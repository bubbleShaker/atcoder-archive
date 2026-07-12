#include <bits/stdc++.h>
using namespace std;

int main(){
    int a,b,c;cin>>a>>b>>c;
    vector<int> cnt(10);
    cnt[a]++;
    cnt[b]++;
    cnt[c]++;
    if(cnt[5]==2&&cnt[7]==1)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}