#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)

/*
N과 M이 주어진다.
2 ~ M까지의 수가 있을 때, N과 약수의 개수가 같은 수 중, 가장 작은 약수가 M보다 같거나 큰 수의 개수를 구하시오.
(약수의 개수에서 자기 자신은 제외한다.)

에라토스테네스의 채를 응용해야 한다.
*/

vector<int> cnt(1000003,0);
vector<int> mn(1000003,-1);
map<int,vector<int>> Mp;

void sieve(){ //에라토스테네스의 채로 전처리
    for(int i=2;i<=1000000/2;i++){
        for(int j=i+i;j<=1000000;j+=i){
            cnt[j]++; //i로 나누어 떨어지게 됨
            if(mn[j]==-1) mn[j]=i;
        }
    }

    //Key를 약수의 개수로 가지는 Map에 약수의 개수가 같은 수들을 묶어서 저장함
    for(int i=1;i<=1000000;i++){
        Mp[cnt[i]].push_back(i);
    }
}

int solve(int N, int M){
    int ret = 0;
    for(auto i : Mp[cnt[N]]){ //약수의 개수가 같은 수들만 돌면서 탐색
        if(i>=N) break;
        if(mn[i]>=M) ret++;
    }   
    return ret;
}

int main(){
    fastio;
    sieve();
    int t; cin>>t;
    for(int tc=1;tc<=t;tc++){
        int N,M; cin>>N>>M;
        cout<<"Case #"<<tc<<": "<<solve(N,M)<<'\n';
    }
    return 0;
}
