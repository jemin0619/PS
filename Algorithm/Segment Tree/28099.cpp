#include <bits/stdc++.h>
using namespace std;

vector<int> V;
vector<int> Segtree;
map<int, vector<int>> Mp;

int merge(int left, int right){
    return max(left, right);
}

int init(int node, int leftNode, int rightNode){
    if(leftNode == rightNode) return Segtree[node] = V[leftNode];
    int mid = leftNode + (rightNode-leftNode)/2;
    int leftVal = init(node*2, leftNode, mid);
    int rightVal = init(node*2 +1, mid+1, rightNode);
    return Segtree[node] = merge(leftVal, rightVal);
}

int query(int left, int right, int node, int leftNode, int rightNode){
    if(rightNode<left || right<leftNode) return -1;
    if(left<=leftNode && rightNode<=right) return Segtree[node];
    int mid = leftNode + (rightNode-leftNode)/2;
    int leftVal = query(left, right, node*2, leftNode, mid);
    int rightVal = query(left, right, node*2 +1, mid+1, rightNode);
    return merge(leftVal, rightVal);
}

int main(){
    cin.tie(NULL)->sync_with_stdio(false);
    int T; cin>>T;
    while(T--){
        V.clear(); Segtree.clear();
        Mp.clear();
        bool fin = false;
        int N; cin>>N; 
        V.resize(N+1); Segtree.resize(4*N);
        for(int i=1;i<=N;i++){
            cin>>V[i];
            Mp[V[i]].push_back(i);
        } 
        init(1,1,N);
        for(auto [key,val] : Mp){
            if(val.size()<2) continue;
            int st = val[0];
            int en = val[val.size()-1];
            int mxVal = query(st, en, 1, 1, N);
            if(mxVal > key){
                cout<<"No\n";
                fin = true;
                break;
            }
        }
        if(!fin) cout<<"Yes\n";
    }
    return 0;
}
