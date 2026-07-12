#include <bits/stdc++.h>
using namespace std;

int main(){
  string a,b;
  cin>>a>>b;
  reverse(a.begin(),a.end());
  reverse(b.begin(),b.end());
  for(int i=0;i<min(a.size(),b.size());i++){
    if((a[i]-'0')+(b[i]-'0')>=10){
      cout<<"Hard"<<endl;
      return 0;
    }
  }
  cout<<"Easy"<<endl;
  return 0;
}