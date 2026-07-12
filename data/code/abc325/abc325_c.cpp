#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
int main(){
    int h,w;cin>>h>>w;
    int count=0;
    vector<int> dx={-1,-1,0,1,1,1,0,-1};
    vector<int> dy={0,1,1,1,0,-1,-1,-1};
    vector<string> s(h);
    for(int i=0;i<h;i++){
        cin>>s[i];
    }
    map<pair<int,int>,int> sensorMap;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(s[i][j]=='#'){
                sensorMap[{i,j}]=count;
                count++;
            }
        }
    }
    dsu uf(count);
    for(auto [point,number]:sensorMap){
        auto [x,y]=point;
        for(int i=0;i<8;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(sensorMap.count({nx,ny})){
                uf.merge(sensorMap[{x,y}],sensorMap[{nx,ny}]);
            }
        }
    }
    set<int> leaderSet;
    for(int i=0;i<count;i++){
        leaderSet.insert(uf.leader(i));
    }
    cout<<leaderSet.size()<<endl;
    return 0;
}