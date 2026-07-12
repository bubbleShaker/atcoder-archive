#include <bits/stdc++.h>
using namespace std;

int main(){
    string a,b;cin>>a>>b;
    string s;
    s+=a;
    s+=b;
    int val=stoi(s);
    for(int i=1;i*i<=100100;i++){
        if(i*i==val){
            cout<<"Yes"<<endl;
            return 0;
        }
    }
    cout<<"No"<<endl;
    return 0;
}