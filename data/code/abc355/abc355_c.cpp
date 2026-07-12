#include <bits/stdc++.h>
using namespace std;
int main() {
  int n,t;
  cin>>n>>t;
  map<int,vector<int>> mpSyo;
  vector<int> columnAmari(n);
  set<int> setMigisita,setHidarisita;
  int cntM=0,cntH=0;
  for(int i=0;i<n;i++){
    setMigisita.insert(1+(n+1)*i);
    setHidarisita.insert(n+(n-1)*i);
  }
  for(int i=0;i<t;i++){
    int a;
    cin>>a;
    if((a%n)==0){
      mpSyo[(a/n)-1].push_back(a%n);
      if(mpSyo[(a/n)-1].size()==n){
        cout<<i+1<<endl;
        // cerr<<1<<endl;
        return 0;
      }
    }else{
      mpSyo[a/n].push_back(a%n);
      if(mpSyo[a/n].size()==n){
        cout<<i+1<<endl;
        // cerr<<1<<endl;
        return 0;
      }
    }
    columnAmari[a%n]++;
    if(columnAmari[a%n]==n){
      cout<<i+1<<endl;
      // cerr<<2<<endl;
      return 0;
    }
    if(setMigisita.count(a)){
      cntM++;
      if(cntM==n){
        cout<<i+1<<endl;
        return 0;
      }
    }
    if(setHidarisita.count(a)){
      cntH++;
      if(cntH==n){
        cout<<i+1<<endl;
        return 0;
      }
    }
    // if((a-1)%(n+1)==0){
    //   if(((a-1)/(n+1))<n){
    //     setMigisita.insert(a);
    //     if(setMigisita.size()==n){
    //       cout<<i+1<<endl;
    //       // cerr<<3<<endl;
    //       return 0;
    //     }
    //   }
    // }
    // if((a-n)%(n-1)==0){
    //   if(((a-n)/(n-1))<n){
    //     setHidarisita.insert(a);
    //     if(setHidarisita.size()==n){
    //       cout<<i+1<<endl;
    //       // cerr<<4<<endl;
    //       return 0;
    //     }
    //   }
    // }
  }
  cout<<-1<<endl;
  return 0;
}