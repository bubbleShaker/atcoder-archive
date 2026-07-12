#include <bits/stdc++.h>
using namespace std;
int main(){
  int r,c;
  cin>>r>>c;
  int sy,sx;
  cin>>sy>>sx;
  int gy,gx;
  cin>>gy>>gx;
  sy--;
  sx--;
  gy--;
  gx--;
  vector<string> s(r);
  for(int i=0;i<r;i++){
    cin>>s[i];
  }
  const int INF=1e9;
  const vector<int> dx={-1,0,1,0};
  const vector<int> dy={0,1,0,-1};
  vector<vector<int>> dist(r+1,vector<int>(c+1,INF));
  auto bfs=[&](){
    queue<pair<int,int>> que;
    que.push({sy,sx});
    dist[sy][sx]=0;
    while(!que.empty()){
      auto [uy,ux]=que.front();
      que.pop();
      for(int i=0;i<4;i++){
        int ny=uy+dx[i];
        int nx=ux+dy[i];
        if(s[ny][nx]=='#'||dist[ny][nx]!=INF){
          continue;
        }
        dist[ny][nx]=dist[uy][ux]+1;
        que.push({ny,nx});
      }
    }
  };
  bfs();
  cout<<dist[gy][gx]<<'\n';
}