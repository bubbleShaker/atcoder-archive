#include <bits/stdc++.h>
using namespace std;
using P=pair<int,int>;
vector<int> dx={-1,0,1,0};
vector<int> dy={0,1,0,-1};
vector<char> c_vec={'v','<','^','>'};

int main(){
  int h,w;
  cin>>h>>w;
  vector<string> t(h);
  for(int i=0;i<h;i++){
    cin>>t[i];
  }
  queue<pair<P,char>> que;//座標と移動方向
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      if(t[i][j]=='E'){
        que.push({{i,j},'.'});
      }
    }
  }
  while(!que.empty()){
    auto xyc=que.front();
    auto [xy,c]=xyc;
    que.pop();
    for(int i=0;i<4;i++){
      auto [x,y]=xy;
      int nx=x+dx[i];
      int ny=y+dy[i];
      if(nx>=0&&nx<h&&ny>=0&&ny<w&&t[nx][ny]!='#'&&t[nx][ny]=='.'){
        t[nx][ny]=c_vec[i];
        que.push({{nx,ny},c_vec[i]});
      }
    }
  }
  for(int i=0;i<h;i++){
    cout<<t[i]<<endl;
  }
  return 0;
}