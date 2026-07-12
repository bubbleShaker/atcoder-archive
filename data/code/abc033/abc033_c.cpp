#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;cin>>s;
    int n=s.size();
    int ans=0,val=1;
    for(int i=0;i<=n;i++){
        if(i==n){
            ans+=val;
            break;
        }
        if(s[i]=='+'){
            ans+=val;
            val=1;
        }else if(s[i]=='*'){
            continue;
        }else if(s[i]=='0'){
            val=0;
        }
    }
    cout<<ans<<endl;
    return 0;
}