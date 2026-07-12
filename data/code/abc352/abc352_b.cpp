#include <bits/stdc++.h>
using namespace std;
int main() {
    string s,t;
    cin>>s>>t;
    int n=s.size();
    int m=t.size();
    int j=0;
    vector<int> ans;
    for(int i=0;i<n;i++){
        while(j<m&&s[i]!=t[j]){
            j++;
        }
        ans.push_back(j+1);
        j++;
    }
    for(int i=0;i<n;i++){
        cout<<ans[i]<<" \n"[i+1==n];
    }
    return 0;
}