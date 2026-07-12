#include <iostream>
#include <string>
int main(){
  int n;
  std::cin>>n;
  std::string s;
  std::cin>>s;
  int l=0,r=n-1;
  auto is_correct=[&](int l,int r,int num){
    if(num==0){
      if(s[l]=='b'&&s[r]=='b'){
        return true;
      }
    }else if(num==1){
      if(s[l]=='a'&&s[r]=='c'){
        return true;
      }
    }else if(num==2){
      if(s[l]=='c'&&s[r]=='a'){
        return true;
      }
    }
    return false;
  };
  int num;
  if(is_correct(l,r,0)){
    num=0;
  }else if(is_correct(l,r,1)){
    num=1;
  }else if(is_correct(l,r,2)){
    num=2;
  }else{
    std::cout<<-1<<'\n';
    return 0;
  }
  int cnt=0;
  bool isOk=true;
  while(l!=r){
    l++;
    r--;
    num=(num-1+3)%3;
    if(!is_correct(l,r,num)){
      isOk=false;
      break;
    }
    cnt++;
  }
  if(isOk){
    std::cout<<cnt<<'\n';
  }else{
    std::cout<<-1<<'\n';
  }
  return 0;
}