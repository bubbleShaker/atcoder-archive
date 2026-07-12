#include <bits/stdc++.h>
using namespace std;
int main(){
    string s1,s2,s3;cin>>s1>>s2>>s3;
    vector<char> ans(3);
    ans[0]=toupper(s1[0]);
    ans[1]=toupper(s2[0]);
    ans[2]=toupper(s3[0]);
    for(int i=0;i<3;i++)cout<<ans[i];
    cout<<endl;
    return 0;
}