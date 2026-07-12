#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
int main(){
  int n;
  std::cin>>n;
  std::vector<std::string> s(n);
  int m=0;
  for(int i=0;i<n;i++){
    std::cin>>s[i];
    m=std::max(m,(int)s[i].size());
  }
  std::vector<std::string> t(m);
  for(int i=n-1;i>=0;i--){
    for(int j=0;j<m;j++){
      if(j<s[i].size()){
        t[j]+=s[i][j];
      }else{
        t[j]+="*";
      }
    }
  }
  for(int i=0;i<m;i++){
    int idx=t[i].size()-1;
    while(t[i][idx]=='*'){
      t[i].pop_back();
      idx--;
    }
    std::cout<<t[i]<<'\n';
  }
  return 0;
}