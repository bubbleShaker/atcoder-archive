#include <bits/stdc++.h>
using namespace std;
int main(){
  string s,t;
  cin>>s>>t;
  int n=s.size();
  int m=t.size();
  vector<string> ans;
  for(int i=0;i<=n-m;i++){
    bool isOk=true;
    string ret=s;
    for(int j=0;j<m;j++){
      if(s[i+j]!=t[j]){
        if(s[i+j]!='?'){
          isOk=false;
          break;
        }else{
          ret[i+j]=t[j];
        }
      }
    }
    if(!isOk){
      continue;
    }
    replace(ret.begin(),ret.end(),'?','a');
    ans.push_back(ret);
  }
  sort(ans.begin(),ans.end());
  cout<<((ans.size()>=1)?ans[0]:"UNRESTORABLE")<<'\n';
  return 0;
}