#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m;cin>>n>>m;
    vector<vector<int>> g(n+1);
    for(int i=0;i<m;i++){
        int a,b;cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vector<int> stepCount(n+1,-1);
    vector<int> ans(n+1);
    stepCount[1]=0;
    queue<int> que;
    que.push(1);
    while(!que.empty()){
        int from=que.front();
        que.pop();
        for(int to:g[from]){
            if(stepCount[to]!=-1)continue;
            que.push(to);
            stepCount[to]=stepCount[from]+1;
            ans[to]=from;
        }
    }
    for(int i=1;i<=n;i++){
        if(stepCount[i]==-1){
            cout<<"No"<<endl;
            return 0;
        }
    }
    cout<<"Yes"<<endl;
    for(int i=2;i<=n;i++){
        cout<<ans[i]<<endl;
    }
    return 0;
}