#include <bits/stdc++.h>
using namespace std;

bool is_ng(vector<vector<pair<int,int>>> vec){
  for(int i=0;i<3;i++){
    vector<pair<int,int>> ts;
    for(int j=0;j<3;j++){
      ts.push_back(make_pair(vec[i][j].second,vec[i][j].first));
    }
    sort(ts.begin(),ts.end());
    if(ts[0].second==ts[1].second&&ts[0].second!=ts[2].second) return true;
  }
  
  for(int j=0;j<3;j++){
    vector<pair<int,int>> ts;
    for(int i=0;i<3;i++){
      ts.push_back(make_pair(vec[i][j].second,vec[i][j].first));
    }
    sort(ts.begin(),ts.end());
    if(ts[0].second==ts[1].second&&ts[0].second!=ts[2].second) return true;
  }
  
  vector<pair<int,int>> ts;
  for(int i=0;i<3;i++){
    ts.push_back(make_pair(vec[i][i].second,vec[i][i].first));
  }
  sort(ts.begin(),ts.end());
  if(ts[0].second==ts[1].second&&ts[0].second!=ts[2].second) return true;
  
  ts.clear();
  for(int i=0;i<3;i++){
    ts.push_back(make_pair(vec[i][2-i].second,vec[i][2-i].first));
  }
  sort(ts.begin(),ts.end());
  if(ts[0].second==ts[1].second&&ts[0].second!=ts[2].second) return true;
  
  return false;
}

int main(){
  vector<int> c(9);
  vector<int> p(9);
  for(int i=0;i<9;i++) cin>>c[i],p[i]=i;
  double ng_cnt=0;
  double sum=362880;
  do{
    vector<vector<pair<int,int>>> vec(3,vector<pair<int,int>>(3));
    for(int i=0;i<3;i++){
      for(int j=0;j<3;j++){
        vec[i][j]=make_pair(c[i*3+j],p[i*3+j]);
      }
    }
    if(is_ng(vec)) ng_cnt++;
  }while(next_permutation(p.begin(),p.end()));
  double ans=(sum-ng_cnt)/sum;
  cout<<fixed<<setprecision(10);
  cout<<ans<<endl;
  return 0;
}