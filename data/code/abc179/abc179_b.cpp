#include <iostream>
int main(){
  int n;
  std::cin>>n;
  int cnt=0;
  bool isOk=false;
  for(int i=0;i<n;i++){
    int d1,d2;
    std::cin>>d1>>d2;
    if(d1==d2){
      cnt++;
    }else{
      cnt=0;
    }
    if(cnt>=3){
      isOk=true;
    }
  }
  if(isOk){
    std::cout<<"Yes"<<'\n';
  }else{
    std::cout<<"No"<<'\n';
  }
  return 0;
}