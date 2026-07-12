#include <bits/stdc++.h>
using namespace std;
int main(){
    set<int> st1,st2,st3;
    st1.insert(1);
    st1.insert(3);
    st1.insert(5);
    st1.insert(7);
    st1.insert(8);
    st1.insert(10);
    st1.insert(12);
    st2.insert(4);
    st2.insert(6);
    st2.insert(9);
    st2.insert(11);
    st3.insert(2);
    int x,y;cin>>x>>y;
    bool isOk=false;
    if(st1.count(x)&&st1.count(y))isOk=true;
    if(st2.count(x)&&st2.count(y))isOk=true;
    if(st3.count(x)&&st3.count(y))isOk=true;
    if(isOk)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}