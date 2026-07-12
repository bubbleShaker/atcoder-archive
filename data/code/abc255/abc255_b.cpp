#include <iostream>
#include <vector>
#include <cmath>
#include <set>
#include <iomanip>
int main(){
  const double INF=2e9;
  int n,k;
  std::cin>>n>>k;
  std::set<int> set;
  for(int i=0;i<k;i++){
    int a;
    std::cin>>a;
    a--;
    set.insert(a);
  }
  std::vector<double> x(n),y(n);
  for(int i=0;i<n;i++){
    std::cin>>x[i]>>y[i];
  }
  std::vector<double> min_dist(n,INF);//点iが照らされるための最小距離を記録していく
  double ans=0;
  for(int i=0;i<n;i++){
    if(!set.count(i)){ //ランプを持っている人からの距離を見る
      continue;
    }
    for(int j=0;j<n;j++){ //人iから人jの距離を見る
      if(set.count(j)){ //人jがランプを持っていたら無視
        continue;
      }
      double dist=std::sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
      min_dist[j]=std::min(min_dist[j],dist);
    }
  }
  for(int i=0;i<n;i++){
    if(!set.count(i)){
      ans=std::max(ans,min_dist[i]);
    }
  }
  std::cout<<std::fixed<<std::setprecision(10);
  std::cout<<ans<<'\n';
  return 0;
}