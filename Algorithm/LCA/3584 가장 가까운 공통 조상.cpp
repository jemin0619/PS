//naive하게 풀어도 되는 문제인데, O(log N)으로 풀었다

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)

int main(){
    fastio;
    int tc; cin>>tc;
    while(tc--){
        int N; cin>>N;
        vector<vector<int>> H(15, vector<int>(N+3, 0));
        vector<int> adj[10003];
        vector<int> depth(10003);

        for(int i=0; i<N-1; i++){
            int A, B; cin>>A>>B;
            adj[A].push_back(B); //부모 -> 자식 Graph
            H[0][B] = A; //자식 -> 부모 Sparse Table
        }
        int A, B; cin>>A>>B;

        //루트 찾기
        int root = -1;
        for(int i=1; i<=N; i++){
            if(H[0][i]==0) {root = i; break;}
        }

        //정점마다 depth 기록하기
        queue<pair<int,int>> Q;
        Q.push({root, 0});
        while(!Q.empty()){
            auto[cur, D] = Q.front(); Q.pop();
            depth[cur] = D;
            for(int nxt : adj[cur]){
                Q.push({nxt, D+1});
            }
        }

        //Sparse Table 채우기
        for(int bit=1; bit<=14; bit++)
            for(int i=1; i<=N; i++)
                H[bit][i] = H[bit-1][H[bit-1][i]];
        
        //depth 맞추기
        if(depth[A] < depth[B]) swap(A, B);
        int diff = depth[A] - depth[B];
        for(int bit=14; bit>=0; bit--){
            if(diff&(1<<bit)) A = H[bit][A];
        }

        
        if(A != B){
            for(int bit=14; bit>=0; bit--){
                if(H[bit][A]!=0 && H[bit][A]!=H[bit][B]){
                    A = H[bit][A];
                    B = H[bit][B];
                }
            }
            A = H[0][A];
        }

        cout<<A<<'\n';
    }
    return 0;
}
