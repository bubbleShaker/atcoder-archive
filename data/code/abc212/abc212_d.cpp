#include <bits/stdc++.h>
using namespace std;
int main(){
    int q;cin>>q;
    long long s=0;
    priority_queue<long long,vector<long long>,greater<long long>> que;
    while(q--){
        int val;cin>>val;
        if(val==1){
            long long x;cin>>x;
            que.push(x-s);
        }
        if(val==2){
            long long x;cin>>x;
            s+=x;
        }
        if(val==3){
            long long res=que.top()+s;
            que.pop();
            cout<<res<<endl;
        }
    }
    return 0;
}