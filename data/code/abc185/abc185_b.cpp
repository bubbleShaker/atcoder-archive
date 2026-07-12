#include <iostream>
#include <algorithm>
int main(){
  int n,m,t;
  std::cin>>n>>m>>t;
  int now_n=n;
  int prev_b;
  for(int i=0;i<m;i++){
    int a,b;
    std::cin>>a>>b;
    if(i==0){
      now_n-=a;
    }else{
      now_n-=a-prev_b;
    }
    if(now_n<=0){
      std::cout<<"No"<<'\n';
      return 0;
    }else{
      prev_b=b;
      now_n=std::min(n,now_n+(b-a));
    }
  }
  std::cout<<((now_n-(t-prev_b)>0)?"Yes":"No")<<'\n';
  return 0;
}