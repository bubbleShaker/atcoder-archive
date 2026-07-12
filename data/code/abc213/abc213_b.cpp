#include <iostream>
#include <utility>
#include <set>
int main(){
  int n;
  std::cin>>n;
  std::set<std::pair<int,int>> st;
  for(int i=0;i<n;i++){
    int a;
    std::cin>>a;
    st.insert({a,i+1});
  }
  std::cout<<(*(++st.rbegin())).second<<'\n';
  return 0;
}