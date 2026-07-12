#include <iostream>
#include <string>
#include <vector>
int main(){
  std::vector<std::string> s(2);
  for(int i=0;i<2;i++){
    std::cin>>s[i];
  }
  int cnt=0;
  for(int i=0;i<2;i++){
    for(int j=0;j<2;j++){
      if(s[i][j]=='#'){
        cnt++;
      }
    }
  }
  if(cnt==1){
    std::cout<<"No"<<'\n';
  }else if(cnt==2){
    if(s[0][0]=='#'&&s[1][1]=='#'||s[0][1]=='#'&&s[1][0]=='#'){
      std::cout<<"No"<<'\n';
    }else{
      std::cout<<"Yes"<<'\n';
    }
  }else{
    std::cout<<"Yes"<<'\n';
  }
  return 0;
}