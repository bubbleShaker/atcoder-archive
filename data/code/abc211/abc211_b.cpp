#include <iostream>
#include <string>
#include <set>
int main(){
  std::string s1,s2,s3,s4;
  std::cin>>s1>>s2>>s3>>s4;
  std::set<std::string> st;
  st.insert(s1);
  st.insert(s2);
  st.insert(s3);
  st.insert(s4);
  std::cout<<((st.size()==4)?"Yes":"No")<<'\n';
  return 0;
}