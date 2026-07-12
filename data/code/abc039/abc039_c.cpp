#include <iostream>
#include <string>
int main(){
  std::string s;
  std::cin>>s;
  std::string base="WBWBWWBWBWBWWBWBWWBWBWBWWBWBWWBWBWBWWBWBWWBWBWBWWBWBWWBWBWBW";
  int w_cnt=0;
  for(int i=0;;i++){
    if(base[i]=='B'){
      continue;
    }
    if(s==base.substr(i,20)){
      if(w_cnt%7==0){
        std::cout<<"Do"<<'\n';
      }else if(w_cnt%7==1){
        std::cout<<"Re"<<'\n';
      }else if(w_cnt%7==2){
        std::cout<<"Mi"<<'\n';
      }else if(w_cnt%7==3){
        std::cout<<"Fa"<<'\n';
      }else if(w_cnt%7==4){
        std::cout<<"So"<<'\n';
      }else if(w_cnt%7==5){
        std::cout<<"La"<<'\n';
      }else if(w_cnt%7==6){
        std::cout<<"Si"<<'\n';
      }
      return 0;
    }
    w_cnt++;
  }
  return 0;
}