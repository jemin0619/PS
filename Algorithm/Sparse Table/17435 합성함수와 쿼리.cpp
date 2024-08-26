//Sparse Table 기초 문제
//쿼리에서 비트를 보는 순서는 크게 상관이 없는 것 같다. (0번 비트부터 보나 18번 비트부터 보나 유의미한 시간차이가 안보임)

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)
#define ll long long

ll M, Q;

//H[i][j]: i에서 2^j만큼 이동한 결과
//n이 최대 50만이므로 2^19 >= 50만, 즉 19로 잡아준다.
ll H[200'003][19];

int main(){
    fastio;
    
    cin>>M;
    for(int i=1; i<=M; i++) cin>>H[i][0];

    for(int j=1; j<19; j++)
        for(int i=1; i<=M; i++)
            H[i][j] = H[H[i][j-1]][j-1];

    cin>>Q;
    while(Q--){
        ll N, X; cin>>N>>X;
        for(int i=0; i<19; i++){
            if(N&(1<<i)){ //해당 비트가 켜져있다면
                X = H[X][i];
            }   
        }
        cout<<X<<'\n';
    }
    return 0;
}
