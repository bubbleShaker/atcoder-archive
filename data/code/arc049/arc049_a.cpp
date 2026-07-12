#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;cin>>s;
    int a,b,c,d;cin>>a>>b>>c>>d;
    string ans;
    int n=s.size();
    for(int i=0;i<n;i++){
        if(i==a||i==b||i==c||i==d)ans+="\"";
        ans+=s[i];
    }
    if(d==n)ans+="\"";
    cout<<ans<<endl;
    return 0;
}