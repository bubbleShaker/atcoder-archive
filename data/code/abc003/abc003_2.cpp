#include <iostream>
#include <string>
#include <set>
int main(){
  std::string s,t;
  std::cin>>s>>t;
  std::set<char> set;
  set.insert('a');
  set.insert('t');
  set.insert('c');
  set.insert('o');
  set.insert('d');
  set.insert('e');
  set.insert('r');
  set.insert('@');
  bool isOk=true;
  for(int i=0;i<s.size();i++){
    if(s[i]=='@'&&t[i]=='@'){
      continue;
    }else if(s[i]=='@'){
      if(set.count(t[i])==false){
        isOk=false;
      }
    }else if(t[i]=='@'){
      if(set.count(s[i])==false){
        isOk=false;
      }
    }else{
      if(s[i]!=t[i]){
        isOk=false;
      }
    }
  }
  if(isOk){
    std::cout<<"You can win"<<'\n';
  }else{
    std::cout<<"You will lose"<<'\n';
  }
  return 0;
}