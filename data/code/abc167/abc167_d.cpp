#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    long long k;
    cin>>n>>k;
    vector<int> a(n);
    vector<vector<int>> g(n);
    for(int i=0;i<n;i++){
        int a;cin>>a;a--;
        g[i].push_back(a);
    }
    
    auto dfs=[&](auto dfs,int from,long long count)->int{
        if(count==0){
            return from;
        }
        int ans;
        for(int to:g[from]){
            ans=dfs(dfs,to,count-1);
        }
        return ans;
    };
    
    if(k<=n){
        cout<<dfs(dfs,0,k)+1<<endl;
        return 0;
    }else{
        vector<int> visitedCount(n);
        int from=0;
        bool inCicle=false;
        vector<int> cicleRoute;
        long long m=0;
        while(1){
            visitedCount[from]++;
            if(visitedCount[from]==2){
                inCicle=true;
            }
            if(visitedCount[from]==3){
                break;
            }
            if(inCicle){
                cicleRoute.push_back(from);
            }
            for(int to:g[from]){
                from=to;
            }
            if(!inCicle)m++;
        }
        long long l=cicleRoute.size();
        long long remainK=k-m;
        cout<<cicleRoute[remainK%l]+1<<endl;
    }
    return 0;
}