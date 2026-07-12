#include <iostream>
#include <string>
#include <algorithm>
#include <set>
int main(){
  int n;
  std::string s;
  std::cin>>n>>s;
  int max=0;
  for(int i=0;i<n;i++){
    std::string s1=s.substr(0,i);
    std::string s2=s.substr(i);
    std::set<char> set1,set2;
    for(int j=0;j<s1.size();j++){
      set1.insert(s1[j]);
    }
    for(int j=0;j<s2.size();j++){
      set2.insert(s2[j]);
    }
    int ret=0;
    for(auto val:set1){
      if(set2.count(val)){
        ret++;
      }
    }
    max=std::max(max,ret);
  }
  std::cout<<max<<'\n';
  return 0;
}