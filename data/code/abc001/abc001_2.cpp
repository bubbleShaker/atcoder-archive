#include <iostream>
#include <string>
int main(){
  int m;
  std::cin>>m;
  std::string ans;
  if(m<100){
    ans="0";
  }else if(100<=m&&m<=5000){
    m/=100;
    ans=std::to_string(m);
  }else if(6000<=m&&m<=30000){
    m/=1000;
    m+=50;
    ans=std::to_string(m);
  }else if(35000<=m&&m<=70000){
    m/=1000;
    m-=30;
    m/=5;
    m+=80;
    ans=std::to_string(m);
  }else if(m>=70000){
    ans="89";
  }
  if(ans.size()==1){
    ans='0'+ans;
  }
  std::cout<<ans<<'\n';
  return 0;
}