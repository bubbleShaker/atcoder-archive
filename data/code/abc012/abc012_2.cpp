#include <bits/stdc++.h>
using namespace std;

string toStr(int val){
    if(val<=9){
        string res="0"+to_string(val);
        return res;
    }else{
        return to_string(val);
    }
}

int main(){
    int n;cin>>n;
    int h=0,m=0,s=0;
    h=n/(60*60);
    n%=60*60;
    m=n/60;
    n%=60;
    s=n;
    string sH=toStr(h),sM=toStr(m),sS=toStr(s);
    cout<<sH<<":"<<sM<<":"<<sS<<endl;
    return 0;
}