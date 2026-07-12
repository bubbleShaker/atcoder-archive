#include <bits/stdc++.h>
using namespace std;

bool isGumojiretsu(string s){
    int n=s.size();
    if(n%2)return false;
    int d=n/2;
    string s1=s.substr(0,d);
    string s2=s.substr(d);
    return s1==s2;
}

int main(){
    string s;cin>>s;
    int n=s.size();
    for(int i=1;i<n;i++){
        string nowS=s.substr(0,n-i);
        if(isGumojiretsu(nowS)){
            cout<<nowS.size()<<endl;
            return 0;
        }
    }
    return 0;
}