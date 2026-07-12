#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  string s;
  cin>>n>>s;
  set<int> st;
  for(int i=0;i<n;i++){
    if(s[i]=='/'){
      st.insert(i);
    }
  }
  int ans=1;
  for(int ind:st){
    int len=1;
    int l_ind=ind-1;
    int r_ind=ind+1;
    while(l_ind>=0&&r_ind<n){
      if(s[l_ind]=='1'&&s[r_ind]=='2'){
        l_ind--;
        r_ind++;
        len+=2;
        ans=max(ans,len);
      }else{
        break;
      }
    }
  }
  cout<<ans<<endl;
  return 0;
}