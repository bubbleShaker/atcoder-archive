#include <iostream>
#include <string>
#include <map>
int main(){
  std::map<char,std::string> s;
  std::cin>>s['a']>>s['b']>>s['c'];
  char now_player='a';
  std::map<char,int> idx;
  while(1){
    if(idx[now_player]==s[now_player].size()){
      std::cout<<(char)std::toupper(now_player)<<'\n';
      return 0;
    }
    char next_player=s[now_player][idx[now_player]++];
    now_player=next_player;
  }
  return 0;
}