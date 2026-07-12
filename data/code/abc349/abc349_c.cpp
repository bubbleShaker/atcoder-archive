#include <bits/stdc++.h>
using namespace std;
string tol(string s){
    string ret;
    int n=s.size();
    for(int i=0;i<n;i++){
        ret+=tolower(s[i]);
    }
    return ret;
}
int main(){
    string s,t;
    cin>>s>>t;
    string tt=(tol(t));
    int n=s.size();
    if(tt[2]!='x'){
        int cnt=0;
        for(int i=0;i<n;i++){
            if(cnt==3)break;
            if(s[i]==tt[cnt]){
                cnt++;
            }
        }
        if(cnt==3){
            cout<<"Yes"<<endl;
            return 0;
        }
    }else{
        int cnt=0;
        for(int i=0;i<n;i++){
            if(cnt==2)break;
            if(s[i]==tt[cnt]){
                cnt++;
            }
        }
        if(cnt==2){
            cout<<"Yes"<<endl;
            return 0;
        }
    }
    cout<<"No"<<endl;
    return 0;
}