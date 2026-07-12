#include <iostream>
#include <vector>
int main(){
  const int MAX=1e2;
  int n;
  std::cin>>n;
  std::vector<int> f(n+1);
  auto calc=[&](int x,int y,int z){
    return x*x+y*y+z*z+x*y+y*z+z*x;
  };
  for(int x=1;x<=MAX;x++){
    for(int y=1;y<=MAX;y++){
      for(int z=1;z<=MAX;z++){
        if(calc(x,y,z)<=n){
          f[calc(x,y,z)]++;
        }
      }
    }
  }
  for(int i=1;i<=n;i++){
    std::cout<<f[i]<<'\n';
  }
  return 0;
}