#include <iostream>
#include <algorithm>
#include <vector>
int main(){
  int n,t,p;
  std::cin>>n>>t>>p;
  std::vector<int> l(n);
  for(int i=0;i<n;i++){
    std::cin>>l[i];
  }
  std::sort(l.rbegin(),l.rend());
  if(l[p-1]>=t){
    std::cout<<0<<'\n';
  }else{
    std::cout<<t-l[p-1]<<'\n';
  }
  return 0;
}