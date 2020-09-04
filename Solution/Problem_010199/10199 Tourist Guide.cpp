#include <bits/stdc++.h>
using namespace std;
#define int int64_t
vector<vector<int>>graph;
unordered_map<string , int> f; 
unordered_map<int , string> rf;
vector<pair<int,int>>Time;
vector<bool>visited;
int timer = 0;
set<string>arPoint;
void dfs(int node , int parent = -1){
    Time.at(node).first = timer; 
    Time.at(node).second = timer;
    visited.at(node) = true;
    int childCounter = 0;
    timer++; 
    bool isArPoint = false;
    for(auto&itr:graph[node]){
        if(itr == parent){
            continue;
        }
        if(!visited.at(itr)){
            ++childCounter;
            dfs(itr, node); 
            if(Time.at(node).first <= Time.at(itr).second){
                isArPoint = true;
            }
            Time.at(node).second = min(Time.at(node).second , Time.at(itr).second);
        }else{
            Time.at(node).second = min(Time.at(node).second , Time.at(itr).first);
        }
    }
    if((parent==-1 && childCounter>=2) || (isArPoint && parent!=-1)){
        arPoint.insert(rf[node]);
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
    int n,counter=1; 
    bool more = false;
    while(cin >> n  && n ){
        if(more){
            puts("");
        }
        more = true;
        timer = 0;
        Time.clear();
        visited.clear();
        graph.clear();
        f.clear();
        rf.clear();
        graph.resize(n);
        visited.assign(n,false);
        arPoint.clear();
        Time.resize(n);
        string s;
        for(int i=0; i<n; ++i){
            cin >> s;
            f[s] =i; 
            rf[i] = s;
        }
        int m; cin >> m; 
        string v;
        for(int i=0; i < m; ++i){
            cin >> s >> v; 
            int u = f[s] , V = f[v];
            graph.at(u).push_back(V);
            graph.at(V).push_back(u);
        }
        for(int i=0; i<n;++i){
            if(!visited.at(i)){
                dfs(i , -1);
            }
        }
        printf("City map #%ld: %ld camera(s) found\n" ,counter++,arPoint.size());
        for(auto&itr:arPoint){
            printf("%s\n",itr.c_str());
        }
    }
    return 0;
}
