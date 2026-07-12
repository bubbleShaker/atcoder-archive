#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  map<int,int> a, b;
  
  cin>>n;
  
  for(int i=1;i<=n;i++){
    cin>>a[i];
  }
  for(int i=1;i<=n;i++){
    cin>>b[i];
  }
  
  for(int i=1;i<=n;i++){
    if(i!=b[a[i]]){
      cout<<"No"<<endl;
      return 0;
    }
  }
  
  cout<<"Yes"<<endl;
}
