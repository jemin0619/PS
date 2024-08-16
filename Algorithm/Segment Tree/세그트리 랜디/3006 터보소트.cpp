//세그먼트 트리로 원소의 삭제를 처리하고, 갱신된 위치를 구간합으로 구해오면 된다.

#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)

vector<int> Seg;

int update(int idx, int val, int node, int leftNode, int rightNode){
    if(idx<leftNode || rightNode<idx) return Seg[node];
    if(leftNode==rightNode) return Seg[node]=val;
    int mid = (leftNode+rightNode)/2;
    int leftVal = update(idx, val, node*2, leftNode, mid);
    int rightVal = update(idx, val, node*2+1, mid+1, rightNode);
    return Seg[node] = leftVal + rightVal;
}

int query(int left, int right, int node, int leftNode, int rightNode){
    if(rightNode<left || right<leftNode) return 0;
    if(left<=leftNode && rightNode<=right) return Seg[node];
    int mid = (leftNode+rightNode)/2;
    int leftVal = query(left, right, node*2, leftNode, mid);
    int rightVal = query(left, right, node*2+1, mid+1, rightNode);
    return leftVal + rightVal;
}

int main(){
    fastio;
    int N; cin>>N;
    deque<pair<int,int>> V(N);
    vector<int> Ans(N);
    Seg.resize(N*4);
    for(int i=0; i<N; i++){
        int X; cin>>X;
        update(i, 1, 1, 0, N-1);
        V[i] = {X, i};
    }
    sort(V.begin(), V.end());
    bool flag = false;
    while(!V.empty()){
        if(!flag){
            int idx = V.front().second;
            V.pop_front();
            cout<<query(0, idx-1, 1, 0, N-1)<<'\n';
            update(idx, 0, 1, 0, N-1);
            flag=true;
        }
        else{
            int idx = V.back().second;
            V.pop_back();
            cout<<query(idx+1, N-1, 1, 0, N-1)<<'\n';
            update(idx, 0, 1, 0, N-1);
            flag=false;
        }
    }
    return 0;
}
