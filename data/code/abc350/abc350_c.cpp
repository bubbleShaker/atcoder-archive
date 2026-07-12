#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    vector<int> a(n+1),v(n+1);
    map<int,int> mp1,mp2;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        v[i]=i;
        mp1[i]=a[i];
        mp2[a[i]]=i;
    }
    vector<pair<int,int>> ans;
    for(int i=1;i<=n;i++){
        int j=mp2[i];
        if(i==j)continue;
        int l=min(i,j);
        int r=max(i,j);
        ans.push_back({l,r});
        swap(a[i],a[j]);
        mp2[a[i]]=i;
        mp2[a[j]]=j;
    }
    int m=ans.size();
    cout<<m<<endl;
    for(auto [l,r]:ans){
        cout<<l<<" "<<r<<endl;
    }
    return 0;
}