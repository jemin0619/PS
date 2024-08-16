#include <bits/stdc++.h>
using namespace std;
#define fastio cin.tie(NULL)->sync_with_stdio(false)
const int MX = 200'0000;

vector<int> SegTree((MX+1)*4);

int merge(int left, int right){
    return left + right;
}

int update(int idx, int node, int leftNode, int rightNode){ //newValue 필요없음
    if(idx<leftNode || rightNode<idx) return SegTree[node];
    if(leftNode == rightNode) return ++SegTree[node];
    int mid = leftNode + (rightNode-leftNode)/2;
    int leftVal = update(idx, node*2, leftNode, mid);
    int rightVal = update(idx, node*2 +1, mid+1, rightNode);
    return SegTree[node] = merge(leftVal, rightVal);
}

//K <= Seg[node*2] -> left 이동
//Seg[node*2] < K  -> right 이동, K -= Seg[node*2]
int Kth(int K, int node, int leftNode, int rightNode){
    SegTree[node]--;
    if(leftNode == rightNode) return leftNode;
    int mid = leftNode + (rightNode-leftNode)/2; 
    if(K <= SegTree[node*2]) return Kth(K, node*2, leftNode, mid);
    else return Kth(K - SegTree[node*2], node*2+1, mid+1, rightNode); 
}

int main(){
    fastio;
    int N; cin>>N;
    while(N--){
        int T,X; cin>>T>>X;
        if(T==1) update(X,1,1,MX);
        else cout<<Kth(X,1,1,MX)<<'\n';
    }
    return 0;
}
