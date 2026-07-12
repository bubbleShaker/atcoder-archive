#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;cin>>n;
    string s;cin>>s;
    bool isBarExist=false;
    bool isDangoExist=false;
    for(int i=0;i<n;i++){
        if(s[i]=='-')isBarExist=true;
        if(s[i]=='o')isDangoExist=true;
    }
    if(isBarExist==false||isDangoExist==false){
        cout<<-1<<endl;
        return 0;
    }
    int ans=0;
    int sum=0;
    for(int i=0;i<n;i++){
        if(s[i]=='o')sum++;
        else sum=0;
        ans=max(sum,ans);
    }
    cout<<ans<<endl;
    return 0;
}