#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
int main(){
  std::string s;
  std::cin>>s;
  std::stack<char> stk;
  for(int i=0;i<s.size();i++){
    if(s[i]=='B'){
      if(!stk.empty()){
        stk.pop();
      }
    }else{
      stk.push(s[i]);
    }
  }
  std::string ans;
  while(!stk.empty()){
    ans+=stk.top();
    stk.pop();
  }
  std::reverse(ans.begin(),ans.end());
  std::cout<<ans<<'\n';
  return 0;
}