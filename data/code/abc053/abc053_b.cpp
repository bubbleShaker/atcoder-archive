#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;cin>>s;
    int indA=-1;
    int n=s.size();
    int ans=0;
    for(int i=0;i<n;i++){
        if(s[i]=='A'){
            if(indA==-1)indA=i;
        }
        if(s[i]=='Z'){
            ans=i-indA+1;
        }
    }
    cout<<ans<<endl;
    return 0;
}