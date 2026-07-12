#include <bits/stdc++.h>
using namespace std;
int main() {
    int n,h,w;
    cin>>n>>h>>w;
    vector<pair<int,int>> ab(n);
    for(int i=0;i<n;i++){
        cin>>ab[i].first>>ab[i].second;
    }
    vector<int> p(n);
    for(int i=0;i<n;i++){
        p[i]=i;
    }
    auto dfs=[&](auto dfs,int ind,int bit,vector<string> grid)->void{
        int si=-1,sj=-1;
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                if(grid[i][j]=='.'&&si==-1){
                    si=i;
                    sj=j;
                }
            }
        }
        if(si==-1){
            // for(int i=0;i<h;i++){
            //     cerr<<grid[i]<<endl;
            // }
            cout<<"Yes"<<endl;
            exit(0);
        }
        if(ind==n){
            return;
        }
        auto [a,b]=ab[p[ind]];
        if(bit&(1<<p[ind])){//回転する
            swap(a,b);
        }
        for(int i=0;i<a;i++){
            for(int j=0;j<b;j++){
                int ni=si+i;
                int nj=sj+j;
                if(ni>=h||nj>=w){
                    return;
                }
                if(grid[ni][nj]!='.'){
                    return;
                }else{
                    grid[ni][nj]='0'+p[ind];
                }
            }
        }
        dfs(dfs,ind+1,bit,grid);
    };
    do{
        for(int bit=0;bit<(1<<n);bit++){
            vector<string> grid(h,string(w,'.'));
            dfs(dfs,0,bit,grid);
        }
    }while(next_permutation(p.begin(),p.end()));
    cout<<"No"<<endl;
    return 0;
}