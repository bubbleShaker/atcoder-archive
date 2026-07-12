#include <bits/stdc++.h>
using namespace std;

using P=pair<int,int>;
int H,W;
vector<vector<char>> c;
vector<vector<bool>> seen;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

void dfs(P p){
  seen[p.first][p.second]=true;
  for(int i=0;i<4;i++){
    int nx=p.first+dx[i];
    int ny=p.second+dy[i];
    if(nx<0||H<=nx||ny<0||W<=ny) continue;
    if(seen[nx][ny]) continue;
    if(c[nx][ny]=='#') continue;
    dfs(make_pair(nx,ny));
  }
}

int main(){
  cin>>H>>W;
  c.assign(H,vector<char>(W,'.'));
  P s,g;
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      cin>>c[i][j];
      if(c[i][j]=='s') s=make_pair(i,j);
      if(c[i][j]=='g') g=make_pair(i,j);
    }
  }
  seen.assign(H,vector<bool>(W,false));
  dfs(s);
  if(seen[g.first][g.second]){
    cout<<"Yes"<<endl;
  }else{
    cout<<"No"<<endl;
  }
}