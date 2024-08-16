//숫자 하나만으로도 구간을 구성할 수 있으므로 M만 충분하다면 모든 문제의 답은 0이 될 수 있다.
//문제와 해설을 이해하는데 상당한 시간이 걸렸던 문제이다...

#include <bits/stdc++.h>
using namespace std;

int N,M;
vector<int> V;

//배열을 M개 이하의 구간으로 나누어, [가장 큰 구간 점수의 최댓값-최소값] 이 mid보다 작거나 같게 되도록 만들 수 있는가?
bool check(int mid){ 
    int cnt = 1;
    int Mx = 0, Mn = 10001;
    for(int i=0;i<N;i++){
        Mx = max(Mx, V[i]);
        Mn = min(Mn, V[i]);

        //V[i]가 포함됨으로 인해 [가장 큰 구간 점수의 최댓값-최소값]이 mid를 넘어섰다면 V[i]를 포함시키기 전으로 돌아가서 배열을 자른다.
        //그래야 [가장 큰 구간 점수의 최댓값-최솟값]이 mid를 넘지 않게 유지할 수 있다.
        if(Mx - Mn > mid){
            cnt++; 
            Mx=V[i], Mn=V[i];
        }
    }
    return cnt<=M;
}

int main(){
    cin>>N>>M;
    for(int i=0;i<N;i++){
        int x; cin>>x;
        V.push_back(x);
    }
    
    //Check(-1)은 항상 False이고, Check(1e9)는 아마 항상 True일 것이다.
    //그러므로 -1 ~ 1e9-1 을 돌게 구성했다.

    int lo=-2, hi=1e9;
    while(lo+1<hi){
        int mid = (lo+hi)/2;
        if(check(mid)) hi=mid;
        else lo=mid;
    }
    cout<<hi;
    return 0;
}
