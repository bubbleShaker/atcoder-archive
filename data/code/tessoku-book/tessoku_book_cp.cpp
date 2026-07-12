#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> h(n+1),dp(n+1);
    for(int i=1;i<=n;i++){
        cin>>h[i];
    }
    for(int i=2;i<=n;i++){
        if(i==2){
            dp[i]=abs(h[i-1]-h[i]);
        }else{
            dp[i]=min(dp[i-1]+abs(h[i-1]-h[i]),dp[i-2]+abs(h[i-2]-h[i]));
        }
    }
    vector<int> ans;
    int place=n;
    while(1){
        ans.push_back(place);
        if(place==1)break;
        if(dp[place]-abs(h[place-1]-h[place])==dp[place-1]){
            place--;
        }else{
            place-=2;
        }
    }
    reverse(ans.begin(),ans.end());
    int k=ans.size();
    cout<<k<<endl;
    for(int i=0;i<k;i++){
        cout<<ans[i]<<" \n"[i+1==k];
    }
    return 0;
}