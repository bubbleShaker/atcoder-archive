#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
int main(){
  int n;
  std::cin>>n;
  std::deque<int> deque;
  bool is_rev=false;
  for(int i=0;i<n;i++){
    int a;
    std::cin>>a;
    if(is_rev){
      deque.push_front(a);
    }else{
      deque.push_back(a);
    }
    is_rev=!is_rev;
  }
  std::vector<int> ans(deque.begin(),deque.end());
  if(is_rev){
    std::reverse(ans.begin(),ans.end());
  }
  for(int i=0;i<n;i++){
    std::cout<<ans[i]<<((i!=n-1)?' ':'\n');
  }
  return 0;
}