#include <iostream>
#include <set>
int main(){
  int n;
  std::cin>>n;
  std::set<int> st;
  for(int i=0;i<n;i++){
    int a;
    std::cin>>a;
    st.insert(a);
  }
  std::cout<<st.size()<<'\n';
  return 0;
}