#include <iostream>
#include <vector>
int main(){
  const int INF=2e9;
  int n;
  std::cin>>n;
  std::vector<int> x(n);
  for(int i=0;i<n;i++){
    std::cin>>x[i];
  }
  int min=INF;
  for(int p=1;p<=100;p++){
    int ret=0;
    for(int j=0;j<n;j++){
      ret+=(x[j]-p)*(x[j]-p);
    }
    min=std::min(min,ret);
  }
  std::cout<<min<<'\n';
  return 0;
}