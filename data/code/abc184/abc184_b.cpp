#include <iostream>
#include <string>
int main(){
  int n,x;
  std::string s;
  std::cin>>n>>x>>s;
  for(int i=0;i<n;i++){
    if(s[i]=='o'){
      x++;
    }else if(s[i]=='x'&&x>0){
      x--;
    }
  }
  std::cout<<x<<'\n';
  return 0;
}