#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
int main(){
  const int INF=2e9;
  int n,k;
  std::cin>>n>>k;
  std::vector<int> a(n);
  for(int i=0;i<n;i++){
    std::cin>>a[i];
  }
  std::sort(a.begin(),a.end());
  // for(int i=0;i<n;i++){
  //   std::cout<<a[i]<<((i!=n-1)?' ':'\n');
  // }
  std::multiset<int> set;
  for(int i=0;i<n-k;i++){
    set.insert(a[i]);
  }
  int ans=INF;
  ans=std::min(ans,*set.rbegin()-*set.begin());
  // std::cout<<ans<<'\n';
  for(int i=n-k;i<n;i++){
    set.erase(set.begin());//一番小さい要素を削除
    set.insert(a[i]);
    ans=std::min(ans,*set.rbegin()-*set.begin());
    // std::cout<<ans<<'\n';
  }
  std::cout<<ans<<'\n';
  return 0;
}