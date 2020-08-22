#include <bits/stdc++.h>
using namespace std;
#define int int64_t
vector<string>graph; 
int n,m;

const int DSIZE = 8;
array<int,8>X{-1,-1,-1,0,0 ,1,1,1};
array<int,8>Y{-1, 0, 1,1,-1,1,-1,0};

bool check(int x, int y , string &s , int index){
    if(x < 0 || y < 0 || y >= m || x >= n || graph[x][y]!=s[index] ){
        return false;
    }
    return true;
}
bool dfs(int x , int y , string &s , int index){
    for(int i=0; i<DSIZE; ++i){
        bool ok = true;
        int tx = x; 
        int ty = y;
        for(int j=1;j<(int)s.size(); ++j){
            tx+=X[i];
            ty+=Y[i];
            if(!check(tx, ty , s , j)){
                ok = false;
                break;
            }
        }
        if(ok){
            return true;
        }
    }
    return false;
}
pair<int,int> find(string&s){
    pair<int,int> res{-1,-1};
    for(int i=0; i<n; ++i){
        for(int j = 0; j<m;++j){
            if(graph[i][j]==s[0] && dfs(i , j , s , 0)){
                return make_pair(i+1, j+1);
            }
        }
    }
    return res;
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
    while(t --){
        graph.clear();
        cin >> n >> m;
        graph.resize(n);
        for(auto&itr:graph){
            cin >> itr;
            for(auto&it:itr){
                it = tolower(it);
            }
        }
        int k; cin >> k; 
        for(int i=0; i<k; ++i){
            string s; cin >> s; 
            for(auto&itr:s){
                itr = tolower(itr);
            }
            auto itr = find(s);
            cout << itr.first << ' ' << itr.second << '\n'; 
        }
        if(t){
            cout << '\n'; 
        }
    }
    return 0;
}
