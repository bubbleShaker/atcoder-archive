#include <iostream>
#include <map>
int main(){
  long long n;
  std::cin>>n;
  auto ceilll=[&](long long a,long long b){
    return (a+(b-1))/b;
  };
  std::map<long long,long long> dp;
  dp[1]=0;
  auto dfs=[&](auto dfs,long long x)->long long{
    long long left=x/2;
    long long right=ceilll(x,2);
    long long ans=x;
    if(!dp.count(left)){
      ans+=dfs(dfs,left);
    }else{
      ans+=dp[left];
    }
    if(!dp.count(right)){
      ans+=dfs(dfs,right);
    }else{
      ans+=dp[right];
    }
    return dp[x]=ans;
  };
  std::cout<<dfs(dfs,n)<<'\n';
  return 0;
}