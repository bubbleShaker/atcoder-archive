#include <iostream>
#include <vector>
#include <cmath>
int main(){
  const long long INF=4e18;
  int n,m;
  std::cin>>n>>m;
  std::vector<long long> a(n),b(n),c(m),d(m);
  for(int i=0;i<n;i++){
    std::cin>>a[i]>>b[i];
  }
  for(int i=0;i<m;i++){
    std::cin>>c[i]>>d[i];
  }
  for(int i=0;i<n;i++){
    long long dist_min=INF;
    int ret;
    for(int j=0;j<m;j++){
      long long dist=std::abs(a[i]-c[j])+std::abs(b[i]-d[j]);
      if(dist<dist_min){
        dist_min=dist;
        ret=j;
      }
    }
    std::cout<<ret+1<<'\n';
  }
  return 0;
}