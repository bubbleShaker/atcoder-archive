#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
int main(){
  const int MAX=1e5;
  int n;
  std::cin>>n;
  std::vector<int> cnt(MAX+1);
  std::map<int,int> map;
  for(int i=0;i<n;i++){
    int a;
    std::cin>>a;
    if(a-1==-1){
      map[-1]++;
    }else{
      cnt[a-1]++;
    }
    cnt[a]++;
    cnt[a+1]++;
  }
  int max=map[-1];
  for(int i=0;i<=MAX;i++){
    max=std::max(max,cnt[i]);
  }
  std::cout<<max<<'\n';
  return 0;
}