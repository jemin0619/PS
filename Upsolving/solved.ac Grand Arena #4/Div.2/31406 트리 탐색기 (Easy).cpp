//전위순회로 돌면 될 것 같다는 생각이 들었다.
//N, Q가 작아서 매 쿼리마다 순서를 새로 구해도 시간 내에 돌아간다.
//k가 0 이상인 경우에 식을 min(N, cord+k)로 잘못 적어서 틀렸었다. 
//(번호가 매겨진 최대 인덱스를 최댓값으로 잡았어야 했는데 N으로 잡음)

#include <bits/stdc++.h>
using namespace std;

int N, Q;
vector<int> tree[2003];
bool isToggle[2003];
int order_1[2003]; //order_1[node] : node의 번호
int order_2[2003]; //order_2[번호] : 그 번호의 node
int idx = 0;

void preorder(int node){
    order_1[node] = idx;
    order_2[idx] = node; 
    idx++;
    if(!isToggle[node]) return;
    for(int nxt : tree[node]){
        preorder(nxt);
    }
}

int main(){
    cin.tie(NULL)->sync_with_stdio(false);
    memset(isToggle, false, sizeof(isToggle));
    cin>>N>>Q;
    for(int i=1; i<=N; i++){
        int tmp; cin>>tmp;
        while(tmp--){
            int x; cin>>x;
            tree[i].push_back(x);
        }
    }
    int cur = tree[1].front();

    isToggle[1] = true;

    while(Q--){
        string S; cin>>S;
        if(S=="toggle") isToggle[cur] = !isToggle[cur];
        if(S=="move"){
            int k; cin>>k;
            memset(order_1, 0, sizeof(order_1));
            memset(order_2, 0, sizeof(order_2));
            idx = 0;
            preorder(1);

            int cord = order_1[cur]; //cur의 현재 순서

            if(k<0) cur = order_2[max(1, cord+k)];
            else cur = order_2[min(idx-1, cord+k)];

            cout<<cur<<'\n';
        }
    }
    return 0;
}
