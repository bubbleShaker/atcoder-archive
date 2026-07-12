#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
int main(){
    const vector<int> dx={-1,-1,0,0,1,1};
    const vector<int> dy={-1,0,-1,1,0,1};
    int n;cin>>n;
    map<pair<int,int>,int> pointMap;
    for(int i=0;i<n;i++){
        int x,y;cin>>x>>y;
        pointMap[{x,y}]=i;
    }
    dsu uf(n);
    for(auto [point,ind]:pointMap){
        auto [x,y]=point;
        for(int i=0;i<6;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(pointMap.count({nx,ny})){
                uf.merge(ind,pointMap[{nx,ny}]);
            }
        }
    }
    set<int> leaderSet;
    for(int i=0;i<n;i++){
        leaderSet.insert(uf.leader(i));
    }
    cout<<leaderSet.size()<<endl;
    return 0;
}