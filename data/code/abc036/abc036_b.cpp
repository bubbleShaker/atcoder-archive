#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;cin>>n;
    vector<string> s(n);
    for(int i=0;i<n;i++)cin>>s[i];
    vector ans(n,vector<char>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            ans[i][j]=s[n-j-1][i];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<ans[i][j];
        }
        cout<<endl;
    }
    return 0;
}