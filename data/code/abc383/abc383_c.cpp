#include <bits/stdc++.h>
using namespace std;
using P=pair<int,int>;//距離と座標の保持

vector<int> dx={-1,0,1,0};
vector<int> dy={0,1,0,-1};

int main(){
  const int INF=1e9;
  int h,w,d;
  cin>>h>>w>>d;
  vector<string> s(h);
  for(int i=0;i<h;i++){
    cin>>s[i];
  }
  vector dist(h,vector<int>(w,-INF));
  queue<P> que;
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      if(s[i][j]=='H'){
        que.push(make_pair(i,j));
        dist[i][j]=d;
      }
    }
  }
  while(!que.empty()){
    auto [x,y]=que.front();
    que.pop();
    for(int i=0;i<4;i++){
      int nx=x+dx[i];
      int ny=y+dy[i];
      if(nx<0||nx>=h||ny<0||ny>=w)continue;
      if(s[nx][ny]=='#')continue;//壁ならcontinue
      if(dist[nx][ny]!=-INF)continue;//到達済みならcontinue
      dist[nx][ny]=dist[x][y]-1;
      if(dist[nx][ny]==0)continue;//コスト0ならpushはしない
      que.push(make_pair(nx,ny));
    }
  }
  int ans=0;
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      if(dist[i][j]>=0){
        ans++;
      }
    }
  }
  cout<<ans<<endl;
  return 0;
}