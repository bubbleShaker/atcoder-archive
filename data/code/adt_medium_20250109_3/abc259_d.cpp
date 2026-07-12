#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll=long long;
using P=pair<ll,ll>;

ll dist(P p1,P p2){
  auto [x1,y1]=p1;
  auto [x2,y2]=p2;
  return (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
}

int main(){
  int n;
  cin>>n;
  P s,t;
  cin>>s.first>>s.second>>t.first>>t.second;
  vector<pair<P,ll>> cir(n);
  for(int i=0;i<n;i++){
    auto &[p,r]=cir[i];
    auto &[x,y]=p;
    cin>>x>>y>>r;
  }
  
  //ufの生成
  dsu uf(n);
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      if(i==j)continue;
      ll r1=cir[i].second;
      ll r2=cir[j].second;
      if(dist(cir[i].first,cir[j].first)<=(r1+r2)*(r1+r2)){
        if(cir[i].second-cir[j].second>=0&&dist(cir[i].first,cir[j].first)>=(cir[i].second-cir[j].second)*(cir[i].second-cir[j].second)){
          uf.merge(i,j);
        }
        if(cir[j].second-cir[i].second>=0&&dist(cir[i].first,cir[j].first)>=(cir[j].second-cir[i].second)*(cir[j].second-cir[i].second)){
          uf.merge(i,j);
        }
      }
    }
  }
  
  //s,tがどの円に乗っているか探索
  vector<int> s_vec,t_vec;
  for(int i=0;i<n;i++){
    if(dist(cir[i].first,s)==cir[i].second*cir[i].second){
      s_vec.push_back(i);
    }
    if(dist(cir[i].first,t)==cir[i].second*cir[i].second){
      t_vec.push_back(i);
    }
  }
  
  //s,tが属する円について、同じ連結成分にあるか全探索
  for(int i=0;i<s_vec.size();i++){
    for(int j=0;j<t_vec.size();j++){
      if(uf.leader(s_vec[i])==uf.leader(t_vec[j])){
        cout<<"Yes"<<endl;
        return 0;
      }
    }
  }
  
  cout<<"No"<<endl;
  return 0;
}