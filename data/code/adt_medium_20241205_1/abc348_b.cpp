#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin>>n;
  vector<int> x(n),y(n);
  for(int i=0;i<n;i++) cin>>x[i]>>y[i];
  for(int i=0;i<n;i++){
    int ma=0;
    int ret=0;
    for(int j=0;j<n;j++){
      if(i==j)continue;
      int di_2=(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
      if(di_2>ma){
        ma=di_2;
        ret=j;
      }
    }
    cout<<ret+1<<endl;
  }
  return 0;
}