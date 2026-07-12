#include <iostream>
#include <string>
int main(){
  std::string s,t,ss;
  std::cin>>s>>t;
  ss=s;
  std::string base="abcdefghijklmnopqrstuvwxyz";
  for(int k=0;k<26;k++){
    for(int i=0;i<s.size();i++){
      int val=s[i]-'a'; 
      val+=k;
      val%=26;
      ss[i]=base[val];
    }
    if(t==ss){
      std::cout<<"Yes"<<'\n';
      return 0;
    }
  }
  std::cout<<"No"<<'\n';
  return 0;
}