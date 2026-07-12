#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
int main(){
  int n;
  long long t;
  std::string s;
  std::cin>>n>>t>>s;
  std::vector<long long> zero_vec,one_vec;
  for(int i=0;i<n;i++){
    long long x;
    std::cin>>x;
    if(s[i]=='0'){
      zero_vec.push_back(x);
    }else{
      one_vec.push_back(x);
    }
  }
  std::sort(zero_vec.begin(),zero_vec.end());
  long long ans=0;
  for(int i=0;i<one_vec.size();i++){
    long long left_idx=std::lower_bound(zero_vec.begin(),zero_vec.end(),one_vec[i])-zero_vec.begin();
    long long right_idx=std::lower_bound(zero_vec.begin(),zero_vec.end(),one_vec[i]+2*t)-zero_vec.begin();
    if(right_idx==zero_vec.size()||zero_vec[right_idx]!=one_vec[i]+2*t){
      right_idx--;
    }
    ans+=right_idx-left_idx+1;
  }
  std::cout<<ans<<'\n';
  return 0;
}