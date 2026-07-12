#include <bits/stdc++.h>
using namespace std;
int main() {
    int n,k;
    cin>>n>>k;
    vector<int> ans;
    for(int i=0;i<n;i++){
        int val;
        cin>>val;
        if(val%k==0){
            ans.push_back(val/k);
        }
    }
    int m=ans.size();
    for(int i=0;i<m;i++){
        cout<<ans[i]<<" ";
    }
    return 0;
}