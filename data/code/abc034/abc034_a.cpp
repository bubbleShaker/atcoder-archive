#include <iostream>
int main(){
  int x,y;
  std::cin>>x>>y;
  std::cout<<((x<y)?"Better":"Worse")<<'\n';
  return 0;
}