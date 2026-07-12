#include <iostream>
#include <vector>
#include <string>
int main(){
  int n;
  std::cin>>n;
  std::vector<std::string> s(n);
  std::vector<int> p(n);
  int sum=0;
  for(int i=0;i<n;i++){
    std::cin>>s[i]>>p[i];
    sum+=p[i];
  }
  for(int i=0;i<n;i++){
    if(p[i]>=sum/2+1){
      std::cout<<s[i]<<'\n';
      return 0;
    }
  }
  std::cout<<"atcoder"<<'\n';
  return 0;
}