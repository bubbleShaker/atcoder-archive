#include <iostream>
#include <vector>
int main(){
  std::vector<std::vector<int>> a(3,std::vector<int>(3));
  for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
      std::cin>>a[i][j];
    }
  }
  int n;
  std::cin>>n;
  for(int _=0;_<n;_++){
    int b;
    std::cin>>b;
    for(int i=0;i<3;i++){
      for(int j=0;j<3;j++){
        if(a[i][j]==b){
          a[i][j]=-1;
        }
      }
    }
  }
  for(int i=0;i<3;i++){
    bool isOK=true;
    for(int j=0;j<3;j++){
      if(a[i][j]!=-1){
        isOK=false;
      }
    }
    if(isOK){
      std::cout<<"Yes"<<'\n';
      return 0;
    }
  }
  for(int j=0;j<3;j++){
    bool isOK=true;
    for(int i=0;i<3;i++){
      if(a[i][j]!=-1){
        isOK=false;
      }
    }
    if(isOK){
      std::cout<<"Yes"<<'\n';
      return 0;
    }
  }
  if(a[0][0]==-1&&a[1][1]==-1&&a[2][2]==-1||a[0][2]==-1&&a[1][1]==-1&&a[2][0]==-1){
    std::cout<<"Yes"<<'\n';
    return 0;
  }
  std::cout<<"No"<<'\n';
  return 0;
}