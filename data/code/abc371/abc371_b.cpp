#include <iostream>
#include <vector>
int main(){
  int n,m;
  std::cin>>n>>m;
  std::vector<bool> is_checked(n+1);
  std::vector<bool> ans(m); 
  for(int i=0;i<m;i++){
    int a;
    char b;
    std::cin>>a>>b;
    if(b=='M'){
      if(!is_checked[a]){
        ans[i]=true;
      }
      is_checked[a]=true;
    }
  }
  for(int i=0;i<m;i++){
    if(ans[i]){
      std::cout<<"Yes"<<'\n';
    }else{
      std::cout<<"No"<<'\n';
    }
  }
  return 0;
}