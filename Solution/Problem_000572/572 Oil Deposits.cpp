#include <bits/stdc++.h>
using namespace std;
#define int int64_t
vector<string>graph;
const int DSIZE = 8;
array<int,8>X{-1,-1,-1,0,0 ,1,1,1};
array<int,8>Y{-1, 0, 1,1,-1,1,-1,0};
bool check(int i , int j){
    if(i < 0 || j<0 || i>=graph.size() || j>= graph.at(i).size() || graph[i][j]=='*' || graph[i][j]=='$'){
        return false;
    }
    return true;
}
void dfs(int i , int j){
    graph[i][j]='$';
    for(int I=0;I<DSIZE;++I){
        if(check(i+X[I], j+Y[I])){
            dfs(i+X[I] , j+Y[I]);
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
    int n,m;
    int case_number{1};
    while(cin >> n>>m , n+m){
        graph.resize(n); 
        for(auto&itr:graph){
            cin>>itr;
        }
        int counter{};
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(graph[i][j]=='@'){
                    ++counter;
                    dfs(i,j);
                }
            }
        }
        cout << counter << '\n'; 
    }
    return 0;
}
