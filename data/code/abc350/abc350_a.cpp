#include <bits/stdc++.h>
using namespace std;
int f(int n1,int n2,int n3){
    return 100*n1+10*n2+n3;
}

int main() {
    string s;
    cin>>s;
    int n1=s[3]-'0';
    int n2=s[4]-'0';
    int n3=s[5]-'0';
    if(1<=f(n1,n2,n3)&&f(n1,n2,n3)<=349&&f(n1,n2,n3)!=316){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }
    return 0;
}