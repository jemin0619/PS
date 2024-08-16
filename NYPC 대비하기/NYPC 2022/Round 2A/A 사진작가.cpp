//슬라이딩 윈도우로 해결
//map으로 원소 관리 (N이 작아 배열도 가능)

#include <bits/stdc++.h>
using namespace std;

int main() {
  int N; cin>>N;
  vector<int> V(N);
  for(int i=0;i<N;i++) cin>>V[i];
  int Ans = 0;
  map<int,int> Mp;
  int st=0;
  for(int i=0;i<N;i++){
    if(Mp[V[i]]==0) Mp[V[i]]=1;
    else{
        while(Mp[V[i]]!=0){
            Mp[V[st]]=0;
            st++;
        }
        Mp[V[i]]=1;
    }
    Ans = max(Ans, i-st+1);
  }
  cout<<Ans;
  return 0;
}
