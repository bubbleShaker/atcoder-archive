#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;cin>>s;
    int n=s.size();
    stack<char> newS;
    for(int i=0;i<n;i++){
        if(i==0){
            newS.push(s[i]);
            continue;
        }
        if(newS.top()==s[i])continue;
        newS.push(s[i]);
    }
    int ans=newS.size()-1;
    cout<<ans<<endl;
    return 0;
}