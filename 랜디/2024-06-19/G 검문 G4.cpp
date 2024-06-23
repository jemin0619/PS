//A = aM + r
//B = bM + r
//C = cM + r

//B-A = (b-a)M
//C-B = (c-b)M

//두 식 B-A 와 C-B에 공통으로 M이 들어 있고, 우리는 모든 M값을 구해야 한다.
//즉, M은 B-A와 C-B의 최대공약수이다.
//그렇게 M을 구하고 1이 아닌 M의 모든 약수를 출력하면 된다.

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL) -> sync_with_stdio(false);

int N;
vector<int> V;
vector<int> ans;

int main(){
    fastio;
    cin>>N;
    for(int i=0;i<N;i++){
        int x; cin>>x;
        V.push_back(x);
    }
    sort(V.begin(),V.end());

    int M = V[1]-V[0];
    
    for(int i=2;i<N;i++)
        M = __gcd(M,V[i]-V[i-1]);

    for(int i=1;i*i<=M;i++){ //M의 모든 약수를 구함
        if(M%i==0){
            ans.push_back(i);
            if(i != M/i) ans.push_back(M/i);
        }
    }
    sort(ans.begin(),ans.end());
    for(int val : ans){ //M은 1보다 커야 하므로 1을 제외하고 출력한다.
        if(val==1) continue;
        cout<<val<<' ';
    }
    return 0;
}
