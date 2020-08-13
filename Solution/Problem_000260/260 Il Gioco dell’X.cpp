#include <bits/stdc++.h>
using namespace std;
#define int int64_t

const int DSIZE = 6;
array<int,8>X{-1,-1,0,0 ,1,1}; // only 6 dimensions are possible
array<int,8>Y{-1, 0,1,-1,1,0};
int max_row{} , max_col{};
vector<string>graph;

bool ok(int u , int v, char last){
    if(u < 0 || v < 0 || u>=(int)graph.size() || v>=(int)graph.size() || graph[u][v] != last){
        return false;
    }
    return true;
}
void dfs(int i , int j , char last){
    if(last == 'w'){
        max_col = max(j , max_col);
    }else{
        max_row = max(i , max_row);
    }
    graph[i][j]='$';
    for(int I=0; I<DSIZE; ++I){
        int u = i + X[I];
        int v = j + Y[I];
        if(ok(u,v,last)){
            dfs(u,v,last);
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
    int n; 
    int case_counter{1};
    while(cin >> n,n){
        graph.resize(n);
        max_col =0; 
        max_row =0;
        for(auto&itr:graph){
            cin >> itr;
        }
        for(int i=0;i<n;++i){
            if(graph[0][i]=='b'){
                dfs(0,i,graph[0][i]);
            }
        }
        cout.flush();
        if(max_row == n-1){
            printf("%d B\n",case_counter++);
        }else{
            printf("%d W\n",case_counter++);
        }
//         for(int i=0;i<n;++i){
//             if(graph[0][i]=='b'){
//                 dfs(0,i,graph[0][i]);
//             }
//         }
    }
    return 0;
}
