#include <iostream>
#include <cmath>
int main(){
  int n;
  double d;
  std::cin>>n>>d;
  int ans=0;
  for(int i=0;i<n;i++){
    double x,y;
    std::cin>>x>>y;
    if(x*x+y*y<=d*d){
      ans++;
    }
  }
  std::cout<<ans<<'\n';
  return 0;
}