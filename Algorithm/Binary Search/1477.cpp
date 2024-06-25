#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false);
#define ll long long

int N,M,L;
vector<int> V;

//FFTT로 존재, hi를 출력

bool Check(ll x){ //휴게소가 없는 구간 최댓값이 x가 되도록 M개의 휴게소를 지을 수 있는가?
    int cnt = 0;
    for(int i=1;i<V.size();i++){
        //알고리즘을 이렇게 짜면 0과 L에는 자연스럽게 휴게소 설치가 되지 않는다.
        cnt += (V[i]-V[i-1]-1)/x;
    }
    return cnt <= M; //필요한 휴게소 개수가 M보다 작거나 같으면 성립합. M보다 많으면 지을 수 없음
}

int main(){
    fastio;
    cin>>N>>M>>L;
    for(int i=0;i<N;i++){
        int x; cin>>x;
        V.push_back(x);
    }
    V.push_back(0); 
    V.push_back(L);
    sort(V.begin(),V.end());

    int lo=0, hi=L;
    while(lo+1<hi){
        int mid = (lo+hi)/2;
        if(Check(mid)) hi = mid;
        else lo = mid;
    }
    cout<<hi;
    return 0;
}
