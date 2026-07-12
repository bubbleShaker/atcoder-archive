#include <iostream>
#include <vector>
#include <set>
int main(){
  int n;
  std::cin>>n;
  std::set<std::vector<int>> st;
  for(int i=0;i<n;i++){
    int l;
    std::cin>>l;
    std::vector<int> a(l);
    for(int j=0;j<l;j++){
      std::cin>>a[j];
    }
    st.insert(a);
  }
  std::cout<<st.size()<<'\n';
  return 0;
}