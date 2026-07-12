#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;cin>>n;
    vector<pair<int,int>> ps;
    for(int i=0;i<n;i++){
        int a,b;cin>>a>>b;
        ps.push_back({a,b});
    }
    sort(ps.rbegin(),ps.rend());
    cout<<ps[0].first+ps[0].second<<endl;
    return 0;
}