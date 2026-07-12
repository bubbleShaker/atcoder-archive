#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
  ll n;
  cin>>n;
  string ans;
  while(n!=0){
    if(n%2==0){
      ans.push_back('B');
      n/=2;
    }else{
      ans.push_back('A');
      n--;
    }
  }
  reverse(ans.begin(),ans.end());
  cout<<ans<<endl;
  return 0;
}