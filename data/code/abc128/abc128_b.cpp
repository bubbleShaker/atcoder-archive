#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
int main(){
    int n;cin>>n;
    vector<tuple<string,int,int>> tplVec(n);
    for(int i=1;i<=n;i++){
        string s;
        int p;
        cin>>s>>p;
        tplVec[i-1]={s,p,i};
    }
    auto f=[&](tuple<string,int,int> tpl1,tuple<string,int,int> tpl2){
        auto [s1,p1,i1]=tpl1;
        auto [s2,p2,i2]=tpl2;
        if(s1==s2){
            return p1>p2;
        }else{
            return s1<s2;
        }
    };
    sort(tplVec.begin(),tplVec.end(),f);
    for(auto [s,p,i]:tplVec){
        cout<<i<<endl;
    }
    return 0;
}