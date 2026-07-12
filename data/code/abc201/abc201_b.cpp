#include <iostream>
#include <string>
#include <utility>
#include <set>
int main(){
  int n;
  std::cin>>n;
  std::set<std::pair<int,std::string>> st;
  for(int i=0;i<n;i++){
    std::string s;
    int t;
    std::cin>>s>>t;
    st.insert({t,s});
  }
  std::cout<<(*++st.rbegin()).second<<'\n';
  return 0;
}