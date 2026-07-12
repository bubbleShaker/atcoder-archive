#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <set>
int main(){
  const std::vector<int> dx={-1,0,1,0};
  const std::vector<int> dy={0,1,0,-1};
  int h,w,y;
  std::cin>>h>>w>>y;
  std::vector<std::vector<int>> a(h,std::vector<int>(w));
  std::vector<std::vector<bool>> is_checked(h,std::vector<bool>(w));
  std::priority_queue<std::pair<int,std::pair<int,int>>,std::vector<std::pair<int,std::pair<int,int>>>,std::greater<std::pair<int,std::pair<int,int>>>> hq;//海面に面している区画の高さ
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      std::cin>>a[i][j];
      if(i==0||j==0||i==h-1||j==w-1){
        hq.push({a[i][j],{i,j}});//海に面している区画をhqに入れる
        is_checked[i][j]=true;//hqに入れたら確認済みとしておく(暫定)
      }
    }
  }
  std::queue<std::pair<int,int>> que;
  std::multiset<std::pair<int,int>> set;//沈没した区画の座標の集合
  for(int i=1;i<=y;i++){
    while(hq.empty()==false&&hq.top().first<=i){//沈没する区画を見ていく
      que.push(hq.top().second);//沈没する区画の座標をbfs用に保持
      hq.pop();
    }
    while(!que.empty()){//沈没する区画について、周囲への伝播を見ていく
      auto [x,y]=que.front();
      que.pop();
      set.insert({x,y});//沈没する区画の登録
      for(int j=0;j<4;j++){
        int nx=x+dx[j];
        int ny=y+dy[j];
        if(nx<0||nx>=h||ny<0||ny>=w){
          continue;
        }
        if(is_checked[nx][ny]){//既に海面に面している、もしくは沈没していると登録していたら無視
          continue;
        }
        if(a[nx][ny]<=i){//沈没する区画だったら
          que.push({nx,ny});//沈没する区画として登録
        }else{//沈没しない区画の場合
          hq.push({a[nx][ny],{nx,ny}});//海面に面している区画として登録
        }
        is_checked[nx][ny]=true;
      }
    }
    //答えの出力
    std::cout<<h*w-(int)set.size()<<'\n';
  }
  return 0;
}