#include <bits/stdc++.h>
using namespace std;
using P=pair<int,char>;

int main(){
  const int INF=2e9;
  int n,m;
  cin>>n>>m;
  map<int,vector<P>> x_mp,y_mp;
  for(int i=0;i<m;i++){
    int x,y;
    char c;
    cin>>x>>y>>c;
    x_mp[x].push_back(make_pair(y,c));
    y_mp[y].push_back(make_pair(x,c));
  }
  int y_whi_min=INF;
  for(auto [x,vec]:x_mp){
    // cout<<"x is "<<x<<endl;
    int y_bla_max=0;
    sort(vec.begin(),vec.end());
    for(auto [y,c]:vec){
      // cout<<"y is "<<y<<endl;
      // if(c=='W'){
      //   cout<<"color is W"<<endl;
      // }else{
      //   cout<<"color is B"<<endl;
      // }
      if(c=='W'){
        y_whi_min=min(y_whi_min,y);
      }
      if(c=='B'){
        y_bla_max=max(y_bla_max,y);
      }
    }
    if(y_whi_min!=INF&&y_whi_min<=y_bla_max){
      cout<<"No"<<endl;
      return 0;
    }
    // cout<<endl;
  }
  cout<<"Yes"<<endl;
  return 0;
}