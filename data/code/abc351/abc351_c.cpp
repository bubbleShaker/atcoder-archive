#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    stack<int> stk;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        stk.push(a);
        if(stk.size()<=1){
            continue;
        }else{
            while(stk.size()>=2){
                int tp=stk.top();
                stk.pop();
                if(tp==stk.top()){
                    stk.pop();
                    stk.push(tp+1);
                }else{
                    stk.push(tp);
                    break;
                }
            }
        }
    }
    cout<<stk.size()<<endl;
    return 0;
}