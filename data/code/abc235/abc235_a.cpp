#include <iostream>
#include <algorithm>
#include <string>
int main(){
  std::string s;
  std::cin>>s;
  int sum=std::stoi(s);
  std::rotate(s.begin(),s.begin()+1,s.end());
  sum+=std::stoi(s);
  std::rotate(s.begin(),s.begin()+1,s.end());
  sum+=std::stoi(s);
  std::cout<<sum<<'\n';
  return 0;
}