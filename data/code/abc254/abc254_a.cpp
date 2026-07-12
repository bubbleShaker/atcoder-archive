#include <bits/stdc++.h>
using namespace std;
string toStr(int n){
    string res;
    if(0<=n&&n<=9){
        res+="0";
        res+=to_string(n);
    }else{
        res=to_string(n);
    }
    return res;
}
int main(){
    int n;cin>>n;
    cout<<toStr(n%100)<<endl;
    return 0;
}