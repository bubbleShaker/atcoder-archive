#include <bits/stdc++.h>
using namespace std;

int main(){
  int r,c;
  cin>>r>>c;
  vector<string> b(r);
  for(int i=0;i<r;i++) cin>>b[i];
  vector<pair<int,int>> bomb_vec;
  vector<int> num;
  for(int i=0;i<r;i++){
    for(int j=0;j<c;j++){
      if(b[i][j]!='.'&&b[i][j]!='#'){
        bomb_vec.push_back({i,j});
        num.push_back(b[i][j]-'0');
      }
    }
  }
  for(int i=0;i<bomb_vec.size();i++){
    auto [x,y]=bomb_vec[i];
    for(int si=0;si<r;si++){
      for(int sj=0;sj<c;sj++){
        if(abs(x-si)+abs(y-sj)<=num[i]){
          b[si][sj]='.';
        }
      }
    }
  }
  for(int i=0;i<r;i++){
    cout<<b[i]<<endl;
  }
  return 0;
}