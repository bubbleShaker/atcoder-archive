#include <iostream>
#include <string>
#include <vector>
int main(){
  int n;
  std::cin>>n;
  std::vector<long long> cnt(5);
  for(int i=0;i<n;i++){
    std::string s;
    std::cin>>s;
    if(s[0]=='M'){
      cnt[0]++;
    }else if(s[0]=='A'){
      cnt[1]++;
    }else if(s[0]=='R'){
      cnt[2]++;
    }else if(s[0]=='C'){
      cnt[3]++;
    }else if(s[0]=='H'){
      cnt[4]++;
    }
  }
  long long ans=0;
  for(int i=0;i<5;i++){
    for(int j=i+1;j<5;j++){
      for(int k=j+1;k<5;k++){
        ans+=cnt[i]*cnt[j]*cnt[k];
      }
    }
  }
  std::cout<<ans<<'\n';
  return 0;
}