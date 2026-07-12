#include <iostream>
#include <string>
#include <vector>
#include <map>
int main(){
  const int INF=1e9;
  std::string t;
  int n;
  std::cin>>t>>n;
  std::vector<std::vector<std::string>> s(n);
  for(int i=0;i<n;i++){
    int a;
    std::cin>>a;
    for(int j=0;j<a;j++){
      std::string ss;
      std::cin>>ss;
      s[i].push_back(ss);
    }
  }
  std::map<std::string,int> map;
  map[""]=0;
  for(int i=1;i<=t.size();i++){
    map[t.substr(0,i)]=INF;
  }
  for(int i=0;i<n;i++){
    for(int len=t.size();len>=0;len--){
      std::string str=t.substr(0,len);
      for(int j=0;j<s[i].size();j++){
        if(map.count(str+s[i][j])){ //tの0文字目からの部分文字列として存在する文字列ならば
          map[str+s[i][j]]=std::min(map[str+s[i][j]],map[str]+1);
        }
      }
    }
  }
  if(map[t]==INF){
    std::cout<<-1<<'\n';
  }else{
    std::cout<<map[t]<<'\n';
  }
  return 0;
}