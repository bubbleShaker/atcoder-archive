#include <iostream>
int main(){
  int a,b,c,k,s,t;
  std::cin>>a>>b>>c>>k>>s>>t;
  std::cout<<s*a+t*b-((s+t>=k)?(s+t)*c:0)<<'\n';
  return 0;
}