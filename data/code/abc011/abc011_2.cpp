#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;cin>>s;
    string ans;
    int n=s.size();
    for(int i=0;i<n;i++){
        if(i==0)ans+=toupper(s[i]);
        else{
            ans+=tolower(s[i]);
        }
    }
    cout<<ans<<endl;
    return 0;
}