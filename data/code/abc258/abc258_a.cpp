#include <bits/stdc++.h>
using namespace std;

string toStr(int val){
    string res;
    res=to_string(val);
    if(res.size()==1){
        res+='0';
        reverse(res.begin(),res.end());
    }
    return res;
}

int main(){
    int k;cin>>k;
    int h=21,m=0;
    h+=k/60;
    m+=k%60;
    cout<<toStr(h)<<":"<<toStr(m)<<endl;
    return 0;
}