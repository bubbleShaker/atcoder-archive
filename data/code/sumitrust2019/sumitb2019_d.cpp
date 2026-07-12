#include <iostream>
#include <vector>
#include <string>
int main(){
  int n;
  std::string s;
  std::cin>>n>>s;
  auto isOk=[&](int i,int j,int k){
    std::vector<int> vec;
    vec.push_back(i);
    vec.push_back(j);
    vec.push_back(k);
    int idx=0;
    for(int i=0;i<n;i++){
      if(vec[idx]==s[i]-'0'){
        idx++;
      }
      if(idx==3){
        break;
      }
    }
    return ((idx==3)?true:false);
  };
  int ans=0;
  for(int i=0;i<=9;i++){
    for(int j=0;j<=9;j++){
      for(int k=0;k<=9;k++){
        if(isOk(i,j,k)){
          ans++;
        }
      }
    }
  }
  std::cout<<ans<<'\n';
  return 0;
}