#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;cin>>s;
    bool isOk=true;
    if(isupper(s[0])==false){
        isOk=false;
    }
    for(int i=1;i<s.size();i++){
        if(islower(s[i])==false){
            isOk=false;
        }
    }
    if(isOk){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }
    return 0;
}