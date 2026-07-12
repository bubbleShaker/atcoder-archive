#include <bits/stdc++.h>
using namespace std;

int main(){
  int l,r;
  cin>>l>>r;
  if(l+r==2||l+r==0){
    cout<<"Invalid"<<endl;
  }else if(l==1){
    cout<<"Yes"<<endl;
  }else if(r==1){
    cout<<"No"<<endl;
  }
  return 0;
}