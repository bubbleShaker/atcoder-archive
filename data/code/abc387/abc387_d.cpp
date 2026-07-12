#include <bits/stdc++.h>
using namespace std;
using P=pair<int,int>;
using ll=long long;
vector<int> dx={-1,0,1,0};
vector<int> dy={0,1,0,-1};

int main(){
  const ll INF=1e18;
  int h,w;
  cin>>h>>w;
  vector<string> s(h);
  for(int i=0;i<h;i++)cin>>s[i];
  vector visited(h,vector(w,vector<ll>(2,INF)));
  vector<queue<pair<P,int>>> que(2);
  P goal;
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      if(s[i][j]=='S'){
        que[0].push({make_pair(i,j),1});
        que[1].push({make_pair(i,j),2});
        visited[i][j][0]=0;
        visited[i][j][1]=0;
      }
      if(s[i][j]=='G'){
        goal=make_pair(i,j);
      }
    }
  }
  for(int ptn=0;ptn<=1;ptn++){
    while(!que[ptn].empty()){
      auto [p,d]=que[ptn].front();
      auto [x,y]=p;
      que[ptn].pop();
      for(int i=0;i<4;i++){
        if((i%2)==(d%2))continue;
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(nx<0||nx>=h||ny<0||ny>=w)continue;
        if(s[nx][ny]=='#')continue;
        if(visited[nx][ny][ptn]!=INF)continue;
        visited[nx][ny][ptn]=visited[x][y][ptn]+1;
        que[ptn].push({make_pair(nx,ny),i});
      }
    }
  }
  auto [gx,gy]=goal;
  ll ans=min(visited[gx][gy][0],visited[gx][gy][1]);
  if(ans==INF){
    cout<<-1<<endl;
  }else{
    cout<<ans<<endl;
  }
  return 0;
}