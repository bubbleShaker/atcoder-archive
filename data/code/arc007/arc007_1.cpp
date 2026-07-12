#include <bits/stdc++.h>
using namespace std;
int main(){
    char x;
    string s;
    cin>>x>>s;
    string ans;
    for(int i=0;i<s.size();i++){
        if(s[i]==x)continue;
        ans+=s[i];
    }
    cout<<ans<<endl;
    return 0;
}