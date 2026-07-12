#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    string s;
    cin>>n>>s;
    map<char,vector<long long>> rsw;
    rsw['R'].resize(n+1);
    rsw['G'].resize(n+1);
    rsw['B'].resize(n+1);
    for(int i=0;i<n;i++){
        long long valR=0,valG=0,valB=0;
        if(s[i]=='R')valR=1;
        if(s[i]=='G')valG=1;
        if(s[i]=='B')valB=1;
        rsw['R'][i+1]+=rsw['R'][i]+valR;
        rsw['G'][i+1]+=rsw['G'][i]+valG;
        rsw['B'][i+1]+=rsw['B'][i]+valB;
    }
    set<char> rgbSet;
    rgbSet.insert('R');
    rgbSet.insert('G');
    rgbSet.insert('B');
    long long ans=0;
    for(int i=0;i<n;i++){
        rgbSet.erase(s[i]);
        for(int j=i+1;j<n;j++){
            if(rgbSet.count(s[j])){
                rgbSet.erase(s[j]);
                for(char remainChar:rgbSet){
                    long long val=0;
                    if(j+(j-i)<n){
                        if(s[j+(j-i)]==remainChar)val=1;
                    }
                    ans+=rsw[remainChar][n]-rsw[remainChar][j+1]-val;
                }
                rgbSet.insert(s[j]);
            }
        }
        rgbSet.insert(s[i]);
    }
    cout<<ans<<endl;
    return 0;
}