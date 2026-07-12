#include <bits/stdc++.h>
using namespace std;
int main(){
    int k;cin>>k;
    string s;cin>>s;
    int n=s.size();
    if(n<=k)cout<<s<<endl;
    else{
        cout<<s.substr(0,k)+"..."<<endl;
    }
    return 0;
}