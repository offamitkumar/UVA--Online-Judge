#include <bits/stdc++.h>
using namespace std;
#define int int64_t
map<string, string>parent;
map<string, int>chainSize;
string find_parent(string node) {
    if (parent[node] == node) {
        return node;
    }
    return parent[node] = find_parent(parent[node]);
}
signed main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    cout.tie(nullptr);
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
#endif
    int n, k;
    while (cin >> n >> k , n+k) {
        parent.clear(); 
        chainSize.clear(); 
        string s;
        for (int i=0; i<n; ++i) {
            cin >> s; 
            chainSize[s]= 1; 
            parent[s] = s;
        }
        string b;
        int max_chain{1};
        for (int i=0; i<k; ++i) {
            cin >> s >> b; 
            s = find_parent(s); 
            b = find_parent(b); 
            if (s != b) {
                parent[b] = s; 
                chainSize[s]+=chainSize[b];
                max_chain = max(chainSize[s], max_chain);
            }
        }
        cout << max_chain << '\n'; 
    }
    return 0;
}
