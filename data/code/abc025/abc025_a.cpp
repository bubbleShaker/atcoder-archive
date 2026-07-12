#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
int main(){
  std::string s;
  int n;
  std::cin>>s>>n;
  std::vector<std::string> vec;
  for(int i=0;i<5;i++){
    for(int j=0;j<5;j++){
      std::string ret;
      ret+=s[i];
      ret+=s[j];
      vec.push_back(ret);
    }
  }
  sort(vec.begin(),vec.end());
  std::cout<<vec[n-1]<<'\n';
  return 0;
}