#include <iostream>
int main(){
  int n,s,d;
  std::cin>>n>>s>>d;
  for(int i=0;i<n;i++){
    int x,y;
    std::cin>>x>>y;
    if(x<s&&y>d){
      std::cout<<"Yes"<<'\n';
      return 0;
    }
  }
  std::cout<<"No"<<'\n';
  return 0;
}