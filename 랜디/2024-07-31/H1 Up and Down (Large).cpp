//좌표압축은 디버깅때문에 했습니다
//최소 swap으로 바이토닉 수열을 구성하라는 문제입니다.

//left[i]: V[i] 기준 왼쪽에서 V[i]보다 큰 수의 개수
//right[i]: V[i] 기준 오른쪽에서 V[i]보다 큰 수의 개수

//V[i]를 기준으로 왼쪽, 오른쪽을 보면서 V[i]보다 큰 수의 개수를 저장합니다.
//'V[i]보다 큰 수'가 갖는 의미는 수열을 유지하며 V[i]를 제자리에 위치시키기까지 필요한 swap의 개수입니다.
//그러므로 left[i]와 right[i]중 작은 값을 선택해서 V[i]를 왼쪽으로 보낼지 오른쪽으로 보낼지를 결정합니다.

//이 알고리즘은 실제로 수들을 이동시키는 것이 아니기에 뭔가 문제가 생길 수도 있을 것 같았습니다.
//하지만 테스트케이스들을 여러 개 보면서 깨달았습니다.
//1. left[i] 혹은 right[i]가 0이라는 의미는 알맞은 자리에 있다는 것이다.
//2. left 혹은 right로 이동하더라도 다음 번 연산에 문제가 되지 않는다.

//어떤 수가 left로 이동했고, 다음 번 left 연산에 반영되어야 한다.
//  - 오른쪽으로 스위핑하며 이동하기에 반영되게 되어있다.

//어떤 수가 right로 이동했고, 다음 번 V[i]의 left 연산에 반영되지 말아야 한다.
//  - V[i] 뒤로 이동했다는 의미는 어떤 수가 V[i]보다 작았다는 의미이므로 반영되지 않는다.

//어떤 수가 right로 이동했고, 다음 번 V[i]의 right 연산에 반영되어야 한다.
//  - V[i] 뒤로 이동했다는 의미는 어떤 수가 V[i]보다 작았다는 의미이므로 right 연산에 카운트되지 않는다. (반영됨)

//제대로 증명한 것도 아니고 사실 잘 모르겠다...
//바이토닉 부분 수열 문제를 풀고 다시 오는게 좋을 것 같다.
//파이썬에서 BIT(펜윅 트리) range sum으로 해결한 코드도 있었는데 이것처럼 V[i]보다 큰 수의 개수를 센게 아닐가 싶다.

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)

void compress(vector<int>&V){
    vector<int> tmp(V);
    sort(tmp.begin(), tmp.end());
    tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());
    for(int&val : V) val = lower_bound(tmp.begin(), tmp.end(), val) - tmp.begin(); 
}

int solve(int N, vector<int>&V){
    compress(V);
    for(int val : V) cout<<val<<' ';
    cout<<'\n';
    vector<int> left(N+3,0);
    vector<int> right(N+3,0);
    int ret = 0;
    for(int i=0;i<N;i++){
        for(int j=i-1;j>=0;j--){
            if(V[j]>V[i]) left[i]++;
        }
        for(int j=i+1;j<N;j++){
            if(V[j]>V[i]) right[i]++;
        }
        ret += min(left[i], right[i]);
        if(left[i]>right[i]) cout<<"\nright"<<' ';
        else if(left[i]<right[i]) cout<<"\nleft"<<' ';
        else cout<<"\nsame"<<' ';
    }
    return ret;
}

int main(){
    fastio;
    int T; cin>>T;
    for(int tc=1; tc<=T; tc++){
        int N; cin>>N;
        vector<int> V(N);
        for(int i=0;i<N;i++) cin>>V[i];
        cout<<"Case #"<<tc<<": "<<solve(N, V)<<'\n';
    }
    return 0;
}
