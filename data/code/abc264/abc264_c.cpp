#include <bits/stdc++.h>
using namespace std;
int main(){
    int h1,w1;
    cin>>h1>>w1;
    vector a(h1,vector<long long>(w1));
    for(int i=0;i<h1;i++)for(int j=0;j<w1;j++){
        cin>>a[i][j];
    }
    int h2,w2;
    cin>>h2>>w2;
    vector b(h2,vector<long long>(w2));
    for(int i=0;i<h2;i++)for(int j=0;j<w2;j++){
        cin>>b[i][j];
    }
    vector<int> rowPermutation(h1),colPermutation(w1);
    int dh=h1-h2,dw=w1-w2;
    for(int i=0;i<dh;i++)rowPermutation[i]=1;
    for(int i=0;i<dw;i++)colPermutation[i]=1;
    sort(rowPermutation.begin(),rowPermutation.end());
    sort(colPermutation.begin(),colPermutation.end());
    do{
        do{
            vector newA(h2,vector<long long>(w2));
            int rowInd=0,colInd=0;
            for(int i=0;i<h1;i++){
                if(rowPermutation[i]==1)continue;
                for(int j=0;j<w1;j++){
                    if(colPermutation[j]==1)continue;
                    newA[rowInd][colInd]=a[i][j];
                    colInd++;
                }
                rowInd++;
                colInd=0;
            }
            if(newA==b){
                cout<<"Yes"<<endl;
                return 0;
            }
        }while(next_permutation(colPermutation.begin(),colPermutation.end()));
    }while(next_permutation(rowPermutation.begin(),rowPermutation.end()));
    cout<<"No"<<endl;
    return 0;
}