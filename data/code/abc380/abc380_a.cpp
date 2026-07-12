#include <bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin>>s;
  vector<int> cnt(10);
  for(int i=0;i<s.size();i++){
    cnt[s[i]-'0']++;
  }
  for(int i=1;i<=3;i++){
    if(cnt[i]!=i){
      cout<<"No"<<endl;
      return 0;
    }
  }
  cout<<"Yes"<<endl;
  return 0;
}