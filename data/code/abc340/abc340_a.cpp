#include <bits/stdc++.h>
using namespace std;
int main(){
    int a,b,d;cin>>a>>b>>d;
    vector<int> ans;
    while(a!=b){
        ans.push_back(a);
        a+=d;
    }
    ans.push_back(a);
    int n=ans.size();
    for(int i=0;i<n;i++){
        cout<<ans[i]<<" \n"[i+1==n];
    }
    return 0;
}