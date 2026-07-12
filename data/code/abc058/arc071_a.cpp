#include <iostream>
#include <string>
#include <algorithm>
#include <map>
int main(){
  const int INF=2e9;
  int n;
  std::cin>>n;
  std::map<char,int> min_map;
  for(int i=0;i<26;i++){
    min_map[char('a'+i)]=INF;
  }
  for(int i=0;i<n;i++){
    std::string s;
    std::cin>>s;
    std::map<char,int> cnt_map;
    for(int j=0;j<s.size();j++){
      cnt_map[s[j]]++;
    }
    for(int j=0;j<26;j++){
      min_map[char('a'+j)]=std::min(min_map[char('a'+j)],cnt_map[char('a'+j)]);
    }
  }
  std::string ans;
  for(int i=0;i<26;i++){
    if(min_map[char('a'+i)]!=INF){
      for(int j=0;j<min_map[char('a'+i)];j++){
        ans+=char('a'+i);
      }
    }
  }
  std::cout<<ans<<'\n';
  return 0;
}