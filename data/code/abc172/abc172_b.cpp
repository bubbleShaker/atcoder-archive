#include <bits/stdc++.h>
using namespace std;
int main(){
    int count=0;
    string s,t;
    cin>>s>>t;
    int n=s.size();
    for(int i=0;i<n;i++){
        if(s[i]!=t[i])count++;
    }
    cout<<count<<endl;
    return 0;
}