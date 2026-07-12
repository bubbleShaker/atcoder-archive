#include <iostream>
#include <vector>
#include <string>
int main(){
  int n;
  std::cin>>n;
  std::vector<std::string> a(n);
  for(int i=0;i<n;i++){
    std::cin>>a[i];
  }
  for(int i=0;i<n;i++){
    for(int j=i+1;j<n;j++){
      if(a[i][j]=='W'&&a[j][i]!='L'||a[i][j]=='L'&&a[j][i]!='W'||a[i][j]=='D'&&a[j][i]!='D'){
        std::cout<<"incorrect"<<'\n';
        return 0;
      }
    }
  }
  std::cout<<"correct"<<'\n';
  return 0;
}