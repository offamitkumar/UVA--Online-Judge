#include <bits/stdc++.h>
using namespace std;
//#define int int64_t
vector<vector<char>>graph;
vector<int>visited(30);
int dfs(int node) {
    int counter{}; 
    visited[node] = 1;
    ++counter;
    for(auto&itr:graph[node]) {
        if(!visited[itr]) {
            counter+= dfs(itr);
        }
    }
    return counter;
}
signed main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    cout.tie(nullptr);
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
#endif
    int t; cin >> t; 
    while (t--) {
        graph.clear(); 
        graph.resize(27);
        fill(visited.begin(), visited.end() , 0);
        string s; 
        while (cin >> s) {
            if (s[0]=='*')
                break;
            graph[s[1]-'A'].push_back(s[3]-'A');
            graph[s[3]-'A'].push_back(s[1]-'A');
        }
        cin >> s;
        stringstream st(s); 
        int tree{} , acorn{};
        while (getline(st , s , ',')) {
            if (!visited[s[0]-'A']){
                int visits = dfs(s[0]-'A');
                if (visits == 1) {
                    acorn++;
                } else {
                    tree++;
                }
            }
        }
        printf("There are %d tree(s) and %d acorn(s).\n" , tree , acorn);
    }
    return 0;
}
