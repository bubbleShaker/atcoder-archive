#include <iostream>
#include <algorithm>
#include <cmath>
int main(){
  const int INF=2e9;
  int n;
  std::cin>>n;
  int min=INF;
  for(int yoko=1;yoko*yoko<=n;yoko++){
    int tate=n/yoko;
    int amari=n%(yoko*tate);
    int cost=std::abs(yoko-tate)+amari;
    min=std::min(min,cost);
  }
  std::cout<<min<<'\n';
  return 0;
}