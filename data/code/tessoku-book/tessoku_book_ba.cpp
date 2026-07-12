#include <bits/stdc++.h>
using namespace std;
template<typename T>
using heap_queue=priority_queue<T,vector<T>,greater<T>>;
int main(){
  int q;
  cin>>q;
  heap_queue<int> hque;
  while(q--){
    int type;
    cin>>type;
    if(type==1){
      int x;
      cin>>x;
      hque.push(x);
    }else if(type==2){
      cout<<hque.top()<<endl;
    }else if(type==3){
      hque.pop();
    }
  }
  return 0;
}