#include <iostream>
#include <stack>
#include <string>
int main(){
  int q;
  std::cin>>q;
  std::stack<std::string> stack;
  while(q--){
    int t;
    std::cin>>t;
    if(t==1){
      std::string s;
      std::cin>>s;
      stack.push(s);
    }else if(t==2){
      std::cout<<stack.top()<<'\n';
    }else if(t==3){
      stack.pop();
    }
  }
  return 0;
}