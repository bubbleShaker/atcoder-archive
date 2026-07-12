#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    string ans;
    bool flag=false;
    int n=s.size();
    for(int i=0;i<n;i++){
        if(s[i]=='|'){
            flag=!flag;
            continue;
        }
        if(flag)continue;
        ans+=s[i];
    }
    cout<<ans<<endl;
    return 0;
}