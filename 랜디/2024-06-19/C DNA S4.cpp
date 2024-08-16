//그냥 각 자리마다 제일 많이 나온 단어 고르면 됨.
//고를 수 있는 답이 두 개 이상 있으면 사전순으로 제일 앞서는 답을 고름

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false);

int N,M;
vector<string> V;
pair<string,int> ans={"",0};

int main(){
    fastio;
    cin>>N>>M;
    for(int i=0;i<N;i++){
        string X; cin>>X;
        V.push_back(X);
    }
    for(int i=0;i<M;i++){ //자리별로 탐색
        int a[4]={0,}; //A C G T 순
        for(int j=0;j<N;j++){
            if(V[j][i]=='A') a[0]++;
            if(V[j][i]=='C') a[1]++;
            if(V[j][i]=='G') a[2]++;
            if(V[j][i]=='T') a[3]++;
        }
        int mxidx=0;
        for(int i=1;i<4;i++){
            if(a[i] > a[mxidx]){
                mxidx = i;
            } 
        }
        if(mxidx==0) ans.first += 'A';
        if(mxidx==1) ans.first += 'C';
        if(mxidx==2) ans.first += 'G';
        if(mxidx==3) ans.first += 'T';
        ans.second += (N-a[mxidx]);
    }
    cout<<ans.first<<'\n'<<ans.second;
    return 0;
}
