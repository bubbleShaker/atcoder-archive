#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;cin>>n;
    stack<int> stk;
    stk.push(0);
    for(int i=0;i<n;i++){
        int a;cin>>a;
        if(stk.top()+1==a){
            stk.push(a);
        }
    }
    int k=stk.size()-1;
    if(k==0){
        cout<<-1<<endl;
        return 0;
    }else{
        cout<<n-k<<endl;
    }
    return 0;
}