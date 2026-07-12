#include <iostream>
#include <vector>
int main(){
  int n,w;
  std::cin>>n>>w;
  std::vector<int> a(n);
  std::vector<bool> dp(w+1);
  for(int i=0;i<n;i++){
    std::cin>>a[i];
    dp[a[i]]=true;//1個だけの時
  }
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){//2個だけの時
      if(i==j){
        continue;
      }
      if(a[i]+a[j]>w){
        continue;
      }
      dp[a[i]+a[j]]=true;
    }
  }
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){//3個だけの時
      if(i==j){
        continue;
      }
      for(int k=0;k<n;k++){
        if(i==k||j==k){
          continue;
        }
        if(a[i]+a[j]+a[k]>w){
          continue;
        }
        dp[a[i]+a[j]+a[k]]=true;
      }
    }
  }
  int ans=0;
  for(int i=0;i<=w;i++){
    if(dp[i]){
      ans++;
    }
  }
  std::cout<<ans<<'\n';
  return 0;
}