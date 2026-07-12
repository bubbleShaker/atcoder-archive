#include <iostream>
#include <set>
int main(){
  int n;
  std::cin>>n;
  std::set<char> set;
  for(int i=0;i<n;i++){
    char s;
    std::cin>>s;
    set.insert(s);
  }
  if(set.size()==3){
    std::cout<<"Three"<<'\n';
  }else{
    std::cout<<"Four"<<'\n';
  }
  return 0;
}