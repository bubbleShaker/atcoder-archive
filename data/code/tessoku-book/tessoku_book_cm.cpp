#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    cin>>n>>k;
    int fSize=n/2;
    int sSize=n-fSize;
    vector<long long> fA(fSize),sA(sSize);
    for(int i=0;i<fSize;i++){
        cin>>fA[i];
    }
    for(int i=0;i<sSize;i++){
        cin>>sA[i];
    }
    vector<long long> fVec,sVec;
    for(int i=0;i<(1<<(fSize));i++){
        int bit=i;
        int nowInd=0;
        long long sum=0;
        while(bit>0){
            if(bit%2==1){
                sum+=(long long)fA[nowInd];
            }
            nowInd++;
            bit/=2;
        }
        fVec.push_back(sum);
    }
    for(int i=0;i<(1<<(sSize));i++){
        int bit=i;
        int nowInd=0;
        long long sum=0;
        while(bit>0){
            if(bit%2==1){
                sum+=(long long)sA[nowInd];
            }
            nowInd++;
            bit/=2;
        }
        sVec.push_back(sum);
    }
    sort(sVec.begin(),sVec.end());
    for(int i=0;i<fVec.size();i++){
        int ind=lower_bound(sVec.begin(),sVec.end(),k-fVec[i])-sVec.begin();
        if(fVec[i]+sVec[ind]==k){
            cout<<"Yes"<<endl;
            return 0;
        }
    }
    cout<<"No"<<endl;
    return 0;
}