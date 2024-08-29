//a[i]-a[j] = -1 (i<j) 를 만족하는 가장 긴 수열을 구하면 된다.
//처음에 슬라이딩윈도우, dp 등의 생각났는데 풀이는 바로 떠오르지 않았다.
//정해는 100만짜리 배열을 만들어두고, 수를 입력받을때마다 dp[i] = max(1, dp[i-1]+1)로 잡는 것이다.
//근데 항상 dp[x-1] >= 1이므로 1을 빼줘도 된다.

#include <bits/stdc++.h>
using namespace std;

vector<int> dp(100'0003);

int main(){
    cin.tie(NULL)->sync_with_stdio(false);
    int N; cin>>N;
    vector<int> V(N);
    for(int i=0; i<N; i++){
        int x; cin>>x;
        dp[x] = max(dp[x-1]+1, 1);
    }
    cout<<*max_element(dp.begin(), dp.end());
    return 0;
}
