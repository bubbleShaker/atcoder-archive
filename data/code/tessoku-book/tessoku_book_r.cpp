#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,s;
    cin>>n>>s;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vector<bool> dp(600100);
    dp[0]=true;
    for(int i=0;i<n;i++){
        for(int j=600000;j>=0;j--){
            if(j-a[i]>=0&&dp[j-a[i]]==true){
                dp[j]=true;
            }
        }
    }
    if(dp[s]==true){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }
    return 0;
}