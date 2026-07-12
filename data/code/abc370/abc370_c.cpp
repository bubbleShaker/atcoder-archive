#include <iostream>
#include <string>
#include <vector>

int to_num(char c){
  return c-'a';
}

int main(){
  std::string s,t;
  std::cin>>s>>t;
  std::vector<std::string> x;
  int n=s.size();
  for(int i=0;i<n;i++){
    if(s[i]!=t[i]){
      if(to_num(s[i])-to_num(t[i])>0){
        s[i]=t[i];
        x.push_back(s);
      }
    }
  }
  for(int i=n-1;i>=0;i--){
    if(s[i]!=t[i]){
      s[i]=t[i];
      x.push_back(s);
    }
  }
  int m=x.size();
  std::cout<<m<<'\n';
  for(int i=0;i<m;i++){
    std::cout<<x[i]<<'\n';
  }
  return 0;
}