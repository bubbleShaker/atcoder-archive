#include <bits/stdc++.h>
using namespace std;

int main(){
  int Q;
  cin>>Q;
  vector<int> a;
  while(Q--){
    int t;
    cin>>t;
    if(t==1){
      int x;
      cin>>x;
      a.push_back(x);
    }else{
      int k;
      cin>>k;
      cout<<a[a.size()-k]<<endl;
    }
  }
}