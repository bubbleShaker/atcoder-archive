#include <bits/stdc++.h>
using namespace std;
int main(){
  int h,w;
  cin>>h>>w;
  vector<string> a(2*h),b(h);
  for(int i=0;i<h;i++){
    cin>>a[i];
    a[i]+=a[i];
  }
  for(int i=h;i<2*h;i++){
    a[i]=a[i-h];
  }
  for(int i=0;i<h;i++){
    cin>>b[i];
  }
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){//始点(i,j)
      bool isOk=true;
      for(int k=0;k<h;k++){
        for(int l=0;l<w;l++){
          if(a[i+k][j+l]!=b[k][l]){
            isOk=false;
          }
          if(!isOk){
            break;
          }
        }
        if(!isOk){
          break;
        }
      }
      if(isOk){
        cout<<"Yes"<<endl;
        return 0;
      }
    }
  }
  cout<<"No"<<endl;
  return 0;
}