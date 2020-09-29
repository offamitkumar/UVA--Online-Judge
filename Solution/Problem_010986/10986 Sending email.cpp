#include <bits/stdc++.h>
using namespace std;
#define int int64_t
class Comparator{
    public:
        bool operator()(const pair<int,int>&a ,const pair<int,int>&b) {
            return a.first > b.first;
        }
};
vector<vector<pair<int,int>>>graph;
vector<int>dist;
void dij(int start_p , int end_p) {
    priority_queue<pair<int,int> , vector<pair<int,int>> , Comparator>pq; 
    dist.at(start_p) = 0;
    pq.push(make_pair(dist.at(start_p), start_p));
    while (!pq.empty()) {
        auto node = pq.top(); pq.pop(); 
        if (node.second == end_p) {
            return ;
        }
        for (auto &itr: graph.at(node.second)) {
            if (dist.at(itr.first) > dist.at(node.second) + itr.second) {
                dist.at(itr.first) = dist.at(node.second) + itr.second; 
                pq.push(make_pair(dist.at(itr.first) , itr.first));
            }
        }
    }
}
signed main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    cout.tie(nullptr);
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
#endif
    int N;  cin >> N; 
    int cas=1;
    while (N--) {
        cout << "Case #" << cas++ << ": ";
        graph.clear(); 
        dist.clear();
        int n, m , S, T; cin >> n >> m >> S >> T;
        graph.resize(n); 
        for (int i=0,u,v,w; i < m; ++i) {
            cin >> u >> v >> w; 
            graph.at(u).push_back(make_pair(v,w));
            graph.at(v).push_back(make_pair(u,w));
        }
        dist.resize(n,INT_MAX);
        dij(S,T);
        if (dist.at(T)!= INT_MAX) {
            cout << dist.at(T) << '\n';
        } else {
            cout << "unreachable" << '\n'; 
        }
    }
    return 0;
}
