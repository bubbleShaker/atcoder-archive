#include <iostream>
#include <stack>
#include <string>
int main(){
  int q;
  std::cin>>q;
  std::stack<std::string> stack;
  while(q--){
    std::string s;
    std::cin>>s;
    if(s=="READ"){
      std::cout<<stack.top()<<'\n';
      stack.pop();
    }else{
      stack.push(s);
    }
  }
  return 0;
}