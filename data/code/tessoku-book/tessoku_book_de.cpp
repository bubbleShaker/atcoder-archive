#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    cin>>n>>k;
    vector<int> a(k);
    for(int i=0;i<k;i++){
        cin>>a[i];
    }
    vector<bool> dp(n+1);
    for(int i=1;i<=n;i++){
        for(int j=0;j<k;j++){
            if(i-a[j]>=0&&dp[i-a[j]]==false){
                dp[i]=true;
                continue;
            }
        }
    }
    if(dp[n]){
        cout<<"First"<<endl;
    }else{
        cout<<"Second"<<endl;
    }
    return 0;
}