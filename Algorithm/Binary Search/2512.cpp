//Check(x) 지방당 최대예산이 x일때 총 예산이 M을 넘는가?
//파라미터가 FFTT로 존재하는 결정문제
//lo를 출력.

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false);
#define ll long long

int N,M;
vector<int> V;

bool Check(int x){ //지방당 최대예산이 x일때 총 예산이 M을 넘는가?
    int sum = 0;
    for(int val : V){
        sum += min(val, x);
    }
    return sum > M;
}

int main(){
    fastio;
    cin>>N;
    for(int i=0;i<N;i++){
        int x; cin>>x;
        V.push_back(x);
    } cin>>M;

    int lo=-1, hi=*max_element(V.begin(),V.end())+1;
    while(lo+1<hi){
        int mid = (lo+hi)/2;
        if(Check(mid)) hi = mid;
        else lo = mid;
    }
    cout<<lo;
    return 0;
}
