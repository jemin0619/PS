//O(M^2) 브루트포스로 풀 수 있다.
//for loop에서 1000으로 한건 그냥 대충 잡았다.

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)

int N, M;
vector<int> A, B, stPoints;
int mn=0x7f7f7f7f, mx=-1;

//x+1칸 건너뛸때 A를 만족하는 구간이 있는가?
bool check(int x){
    for(int stidx : stPoints){
        int idx=0;
        while(idx<N && stidx<M && A[idx]==B[stidx]){
            idx++; stidx+=(x+1);
        }
        if(idx==N) return true;
    }
    return false;
}

int main(){
    fastio;
    cin>>N; A.resize(N);
    for(int i=0; i<N; i++) cin>>A[i];
    cin>>M; B.resize(M);
    for(int i=0; i<M; i++){
        cin>>B[i];
        if(B[i]==A[0]) stPoints.push_back(i);
    }
    for(int i=0; i<=1000; i++){
        if(check(i)){
            mn = min(mn, i);
            mx = max(mx, i);
        }
    }
    if(mn==0x7f7f7f7f && mx==-1) cout<<-1;
    else cout<<mn<<' '<<mx;
    return 0;
}
