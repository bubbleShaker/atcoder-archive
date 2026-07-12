#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;cin>>s;
    bool thereIsA=false,thereIsB=false;
    for(int i=0;i<3;i++){
        if(s[i]=='A')thereIsA=true;
        if(s[i]=='B')thereIsB=true;
    }
    if(thereIsA&&thereIsB)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}