//binary_search로 해당 수가 존재하는지 찾아주었다.

#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(NULL)->sync_with_stdio(false);
    int tc; cin>>tc;
    while(tc--){
        int N; cin>>N;
        vector<int> V(N);
        for(int i=0; i<N; i++) cin>>V[i];
        sort(V.begin(), V.end());
        long long ans = 0;
        for(int i=0; i<N; i++){
            for(int j=i+1; j<N; j++){
                int gap = V[i]-V[j];
                if(binary_search(V.begin()+j+1, V.end(), V[j]-gap)) ans++;
            }   
        }
        cout<<ans<<'\n';
    }
    return 0;
}
