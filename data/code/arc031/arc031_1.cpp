#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;cin>>s;
    int n=s.size();
    for(int i=0;i<n;i++){
        if(s[i]!=s[n-i-1]){
            cout<<"NO"<<endl;
            return 0;
        }
    }
    cout<<"YES"<<endl;
    return 0;
}