#include <iostream>
#include <string>
int main(){
  std::string s;
  std::cin>>s;
  int lcnt=0,ucnt=0;
  for(int i=0;i<s.size();i++){
    if(std::islower(s[i])){
      lcnt++;
    }else{
      ucnt++;
    }
  }
  for(int i=0;i<s.size();i++){
    s[i]=((ucnt>lcnt)?std::toupper(s[i]):std::tolower(s[i]));
  }
  std::cout<<s<<'\n';
  return 0;
}