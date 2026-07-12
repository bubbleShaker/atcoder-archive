#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;cin>>s;
    int n=s.size();
    vector<int> ans(n);
    for(int i=0;i<n-1;i++){
        if(s[i]=='R'&&s[i+1]=='L'){
            ans[i]++;
            ans[i+1]++;
            int rInd=i-1;
            int lInd=i+2;
            int cnt=0;
            while(rInd>=0&&s[rInd]=='R'){
                if(cnt%2==0){
                    ans[i+1]++;
                }else{
                    ans[i]++;
                }
                rInd--;
                cnt++;
            }
            cnt=0;
            while(lInd<n&&s[lInd]=='L'){
                if(cnt%2==0){
                    ans[i]++;
                }else{
                    ans[i+1]++;
                }
                lInd++;
                cnt++;
            }
        }
    }
    for(int i=0;i<n;i++){
        cout<<ans[i]<<" \n"[i+1==n];
    }
    return 0;
}