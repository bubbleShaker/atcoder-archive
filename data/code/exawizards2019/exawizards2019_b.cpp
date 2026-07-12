#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    string s;
    cin>>n>>s;
    int countR=0,countB=0;
    for(char color:s){
        if(color=='R')countR++;
        if(color=='B')countB++;
    }
    if(countR>countB)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}