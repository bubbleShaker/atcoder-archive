#include <bits/stdc++.h>
using namespace std;

int main(){
  vector<string> dir(8);
  dir[0]="N";
  dir[1]="NE";
  dir[2]="E";
  dir[3]="SE";
  dir[4]="S";
  dir[5]="SW";
  dir[6]="W";
  dir[7]="NW";
  map<string,int> dir_ind;
  for(int i=0;i<8;i++){
    dir_ind[dir[i]]=i;
  }
  string d;
  cin>>d;
  int ind=dir_ind[d];
  cout<<dir[(ind+4)%8]<<endl;
  return 0;
}