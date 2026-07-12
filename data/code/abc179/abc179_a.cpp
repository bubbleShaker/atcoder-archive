#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;cin>>s;
    int n=s.size();
    if(s[n-1]=='s'){
        s+="es";
    }else{
        s+="s";
    }
    cout<<s<<endl;
    return 0;
}