#include <iostream>
#include <vector>
#include <cmath>
int main(){
  int n;
  std::cin>>n;
  std::vector<int> x(n),y(n);
  for(int i=0;i<n;i++){
    std::cin>>x[i]>>y[i];
  }
  int ans=0;
  for(int i=0;i<n;i++){
    for(int j=i+1;j<n;j++){
      int dy=y[j]-y[i];
      int dx=x[j]-x[i];
      if(abs(dy)<=abs(dx)){
        ans++;
      }
    }
  }
  std::cout<<ans<<'\n';
  return 0;
}