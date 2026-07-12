#include <iostream>
#include <string>
#include <set>
int main(){
  std::string s;
  std::cin>>s;
  std::set<std::string> st;
  int n=s.size();
  for(int i=0;i<n;i++){//左シフト
    std::string ss=s;
    ss=s.substr(i,n-i)+s.substr(0,i);
    st.insert(ss);
  }
  for(int i=0;i<n;i++){//右シフト
    std::string ss=s;
    ss=s.substr(n-i,i)+s.substr(0,n-i);
    st.insert(ss);
  }
  std::cout<<*st.begin()<<'\n';
  std::cout<<*st.rbegin()<<'\n';
  return 0;
}