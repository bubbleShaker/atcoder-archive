#include <iostream>
#include <string>
#include <vector>
int main(){
  const long long MOD=(long long)1e9+7;
  int n;
  std::string s;
  std::cin>>n>>s;
  char prev_c;
  long long len;
  std::vector<long long> len_vec;
  for(int i=0;i<s.size();i++){
    if(i==0){
      prev_c=s[i];
      len=1;
    }else{
      if(s[i]!=prev_c){
        len++;
        prev_c=s[i];
      }else{
        if(len==1){
          continue;
        }else{
          len_vec.push_back(len);
          len=1;
        }
      }
    }
  }
  if(len!=1){
    len_vec.push_back(len);
  }
  long long ans=1;
  for(int i=0;i<len_vec.size();i++){
    // std::cout<<len_vec[i]<<'\n';
    long long val=((len_vec[i]%2==0)?(len_vec[i]-2)/2:(len_vec[i]-1)/2);
    ans*=(val+1);
    ans%=MOD;
  }
  std::cout<<ans<<'\n';
  return 0;
}