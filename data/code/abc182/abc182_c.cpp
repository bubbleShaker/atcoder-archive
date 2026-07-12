#include <iostream>
#include <string>
int main(){
  std::string s;
  std::cin>>s;
  int one_cnt=0;
  int two_cnt=0;
  int zero_cnt=0;
  int sum=0;
  for(int i=0;i<s.size();i++){
    sum+=s[i]-'0';
    if((s[i]-'0')%3==1){
      one_cnt++;
    }else if((s[i]-'0')%3==2){
      two_cnt++;
    }else{
      zero_cnt++;
    }
  }
  sum%=3;
  if(sum==1){
    if(one_cnt>=1){
      if(zero_cnt==0&&one_cnt==1&&two_cnt==0){
        std::cout<<-1<<'\n';
        return 0;
      }
      std::cout<<1<<'\n';
    }else if(two_cnt>=2){
      if(zero_cnt==0&&one_cnt==0&&two_cnt==2){
        std::cout<<-1<<'\n';
        return 0;
      }
      std::cout<<2<<'\n';
    }else{
      std::cout<<-1<<'\n';
    }
  }else if(sum==2){
    if(two_cnt>=1){
      if(zero_cnt==0&&one_cnt==0&&two_cnt==1){
        std::cout<<-1<<'\n';
        return 0;
      }
      std::cout<<1<<'\n';
    }else if(one_cnt>=2){
      if(zero_cnt==0&&one_cnt==2&&two_cnt==0){
        std::cout<<-1<<'\n';
        return 0;
      }
      std::cout<<2<<'\n';
    }else{
      std::cout<<-1<<'\n';
    }
  }else{
    std::cout<<0<<'\n';
  }
  return 0;
}