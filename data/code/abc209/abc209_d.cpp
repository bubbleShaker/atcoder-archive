#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,Q;cin>>n>>Q;
    const int INF=1e9;
    vector<vector<int>> g(n);
    for(int i=0;i<n-1;i++){
        int a,b;cin>>a>>b;a--;b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vector<int> dist(n,-INF);
    queue<int> q;
    dist[0]=0;
    q.push(0);
    while(!q.empty()){
        int from=q.front();
        q.pop();
        for(int to:g[from]){
            if(dist[to]!=-INF)continue;
            q.push(to);
            dist[to]=dist[from]+1;
        }
    }
    while(Q--){
        int c,d;cin>>c>>d;c--;d--;
        if(abs(dist[c]-dist[d])%2==0){
            cout<<"Town"<<endl;
        }else{
            cout<<"Road"<<endl;
        }
    }
    return 0;
}