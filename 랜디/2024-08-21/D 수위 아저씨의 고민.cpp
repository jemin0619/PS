//생각할게 좀 있던 브루트포스

#include <bits/stdc++.h>
using namespace std;

#define fastio cin.tie(NULL)->sync_with_stdio(false)

int main() {
    fastio;
    int tc; 
    cin >> tc;
    
    while(tc--) {
        int F, R, N; 
        cin >> F >> R >> N;
        
        vector<vector<int>> Floor(F + 1);
        
        for(int i = 0; i < N; i++) {
            int a, b; 
            cin >> a >> b;
            Floor[a].push_back(b);
        }

        //엘리베이터로 올라갔다가 내려오는 시간 2*(F+1) - 1
        //옥상을 건너서 내려가는 엘리베이터로 가는 시간 R
        int ans = 2 * (F + 1) + R - 1;
        
        for(int i = 1; i <= F; i++) {
            sort(Floor[i].begin(), Floor[i].end());

            //그 층에 불이 다 꺼져있으면 continue
            if(Floor[i].empty()) continue;

            //끌 방이 하나면 그 하나만 고려한다.
            if(Floor[i].size() == 1) {
                ans += min(Floor[i][0]*2, (R-Floor[i][0]+1)*2);
                continue;
            }
            
            int tmp = INT_MAX;

            //내려가는 길, 올라가는 길에 한 번씩 나눠서 끄는 경우
            //둘로 나눌 때 최적의 값을 찾기 위해 Bruteforce를 쓴다.
            for(int j = 1; j < Floor[i].size(); j++) {
                tmp = min(Floor[i][j-1]*2 + (R-Floor[i][j]+1)*2, tmp);
            }
            
            tmp = min((R-Floor[i][0]+1)*2, tmp); //내려오는 길에 전부 끄는 경우
            tmp = min(Floor[i][Floor[i].size()-1]*2, tmp); //올라가는 길에 전부 끄는 경우

            ans += tmp;
        }

        cout << ans << '\n';
    }
    
    return 0;
}
