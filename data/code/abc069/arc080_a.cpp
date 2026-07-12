#include <iostream>
int main(){
  int n;
  std::cin>>n;
  int zero=0,one=0,more_than_two=0;
  for(int i=0;i<n;i++){
    int a;
    std::cin>>a;
    int cnt=0;
    while(a%2==0){
      a/=2;
      cnt++;
    }
    if(cnt>=2){
      more_than_two++;
    }else if(cnt==1){
      one++;
    }else if(cnt==0){
      zero++;
    }
  }
  if(one>=1){
    zero++;
  }
  if(more_than_two+1>=zero){
    std::cout<<"Yes"<<'\n';
  }else{
    std::cout<<"No"<<'\n';
  }
  return 0;
}