#include <iostream>
#include <string>
int main(){
  std::string s;
  std::cin>>s;
  int r_idx,m_idx;
  for(int i=0;i<3;i++){
    if(s[i]=='R'){
      r_idx=i;
    }else if(s[i]=='M'){
      m_idx=i;
    }
  }
  std::cout<<((r_idx<m_idx)?"Yes":"No")<<'\n';
  return 0;
}