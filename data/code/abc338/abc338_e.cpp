#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;cin>>n;
    stack<int> stk;
    map<int,int> numIndMap;
    vector<int> a(n+1),b(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i];
        numIndMap[a[i]]=i;
        numIndMap[b[i]]=i;
    }
    for(int i=1;i<=2*n;i++){
        if(stk.empty()){
            stk.push(numIndMap[i]);
            continue;
        }else{
            if(stk.top()==numIndMap[i]){
                stk.pop();
            }else{
                stk.push(numIndMap[i]);
            }
        }
    }
    if(!stk.empty()){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }
    return 0;
}