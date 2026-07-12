#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m;cin>>n>>m;
    map<int,set<char>> g;
    for(int i=0;i<m;i++){
        char s,c;cin>>s>>c;
        if(s=='1'&&c=='0'&&n!=1){
            cout<<-1<<endl;
            return 0;
        }
        g[s-'0'].insert(c);
    }
    vector<char> ans(n);
    for(int i=1;i<=n;i++){
        if(g[i].size()==0){
            if(i==1){
                if(n==1){
                    ans[i-1]='0';
                }else{
                    ans[i-1]='1';
                }
            }else{
                ans[i-1]='0';
            }
        }
        if(g[i].size()==1){
            for(char val:g[i]){
                ans[i-1]=val;
            }
        }
        if(g[i].size()>1){
            cout<<-1<<endl;
            return 0;
        }
    }
    for(int i=0;i<n;i++){
        cout<<ans[i];
    }
    cout<<endl;
    return 0;
}