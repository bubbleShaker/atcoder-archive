#include <bits/stdc++.h>
using namespace std;

int main(){
  int n,s;
  cin>>n>>s;
  vector<int> t(n);
  int last=0;
  for(int i=0;i<n;i++){
    cin>>t[i];
  }
  for(int i=0;i<n;i++){
    if(last+s>=t[i]){
      last=t[i];
    }else{
      cout<<"No"<<endl;
      return 0;
    }
  }
  cout<<"Yes"<<endl;
  return 0;
}