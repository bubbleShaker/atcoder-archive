#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,a,b;
    cin>>n>>a>>b;
    vector<bool> dp(n+1);
    for(int i=1;i<=n;i++){
        if(i-a>=0){
            if(dp[i-a]==false){
                dp[i]=true;
            }
        }
        if(i-b>=0){
            if(dp[i-b]==false){
                dp[i]=true;
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