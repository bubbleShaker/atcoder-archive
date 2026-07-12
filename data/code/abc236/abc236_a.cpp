#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;cin>>s;
    int a,b;cin>>a>>b;a--;b--;
    for(int i=0;i<s.size();i++){
        if(i==a){
            cout<<s[b];
        }else if(i==b){
            cout<<s[a];
        }else{
            cout<<s[i];
        }
    }
    return 0;
}