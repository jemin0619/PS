//그리디, 정렬로 가장 가장 강한 폭탄부터 터뜨리면 된다.
//간만에 세그를 쓸 수 있는 문제라 연습할 겸 사용했다. 비효율적이다.

//range max Segment Tree

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio cin.tie(NULL)->sync_with_stdio(false)
#define pii pair<ll,ll>

int N;
vector<pii> Seg;
vector<ll> V;

pii merge(pii left, pii right){
    return max(left, right);
}

pii update(int idx, ll val, int node, int leftNode, int rightNode){
    if(idx<leftNode || rightNode<idx) return Seg[node];
    if(leftNode==rightNode) return Seg[node]={val, leftNode};
    ll mid = leftNode+rightNode; mid/=2;
    pii leftVal = update(idx, val, node*2, leftNode, mid);
    pii rightVal = update(idx, val, node*2+1, mid+1, rightNode);
    return Seg[node] = merge(leftVal, rightVal);
}

pii rmq(int left, int right, int node, int leftNode, int rightNode){
    if(right<leftNode || rightNode<left) return {-1, 0};
    if(left<=leftNode && rightNode<=right) return Seg[node];
    ll mid = leftNode+rightNode; mid/=2;
    pii leftVal = rmq(left, right, node*2, leftNode, mid);
    pii rightVal = rmq(left, right, node*2+1, mid+1, rightNode);
    return merge(leftVal, rightVal);
}

int main(){
    fastio;
    cin>>N;
    Seg.resize(N*4);
    V.resize(N);
    for(int i=0; i<N; i++){
        cin>>V[i];
        update(i, V[i], 1, 0, N-1);
    }
    vector<ll> ans;
    while(Seg[1].first != 0){
        auto[val, idx] = Seg[1];
        V[idx] = 0;
        update(idx, 0, 1, 0, N-1);
        ans.push_back(idx+1);

        //cout<<idx+1<<"을 직접 터뜨리고, ";

        int leftP = val;
        for(int left=idx-1; left>=0; left--){
            if(V[left]>=leftP || V[left]==0) break;
            leftP = V[left];
            V[left] = 0;
            update(left, 0, 1, 0, N-1);

            //cout<<left+1<<" ";
        }

        int rightP = val;
        for(int right=idx+1; right<N; right++){
            if(V[right]>=rightP || V[right]==0) break;
            rightP = V[right];
            V[right] = 0;
            update(right, 0, 1, 0, N-1);

            //cout<<right+1<<" ";
        }

        //cout<<"들을 터뜨림\n";
    }
    

    sort(ans.begin(), ans.end());
    for(ll val : ans) cout<<val<<'\n';
    return 0;
}
