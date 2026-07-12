#include <bits/stdc++.h>
using namespace std;
int main() {
    string s;
    cin>>s;
    int n=s.size();
    string x=s.substr(0,n-2);
    int y=s[n-1]-'0';
    if(0<=y&&y<=2){
        cout<<x+'-'<<endl;
    }else if(3<=y&&y<=6){
        cout<<x<<endl;
    }else{
        cout<<x+'+'<<endl;
    }
    return 0;
}