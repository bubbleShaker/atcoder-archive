#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
int main(){
  int n;
  std::cin>>n;
  std::vector<long long> x(n),y(n);
  for(int i=0;i<n;i++){
    std::cin>>x[i]>>y[i];
  }
  int ans=0;
  for(int i=0;i<n;i++){
    for(int j=i+1;j<n;j++){
      for(int k=j+1;k<n;k++){
        std::vector<std::pair<long long,long long>> xy;
        xy.push_back({x[i],y[i]});
        xy.push_back({x[j],y[j]});
        xy.push_back({x[k],y[k]});
        std::sort(xy.begin(),xy.end());
        long long dx1=xy[1].first-xy[0].first;
        long long dy1=xy[1].second-xy[0].second;
        long long dx2=xy[2].first-xy[1].first;
        long long dy2=xy[2].second-xy[1].second;
        if(dy1*dx2==dy2*dx1){
          continue;
        }else{
          ans++;
        }
      }
    }
  }
  std::cout<<ans<<'\n';
  return 0;
}