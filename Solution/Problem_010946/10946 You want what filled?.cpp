#include <bits/stdc++.h>
using namespace std;
#define int int64_t
int n , m;
const int DSIZE = 4;
vector<string>graph;
array<int,4>X{-1,1,0,0};
array<int,4>Y{0,0,-1,1};
bool check(int x, int y, char ch){
    if(x < 0 || y <0 || x>=n || y>=m || graph[x][y]!=ch){
        return false;
    }
    return true;
}
int dfs(int x , int y , char ch){
    graph[x][y] = '$';
    int counter =1;
    for(int i=0; i<DSIZE; ++i){
        int tx = x + X[i]; 
        int ty = y + Y[i]; 
        if(check(tx , ty, ch)){
            counter+=dfs(tx , ty, ch); 
        }
    }
    return counter;
}
bool compare(pair<int , char>&a , pair<int ,char>&b){
    if(a.first == b.first){
        return a.second < b.second;
    }else{
        return a.first > b.first;
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
    int problem = 1;
    while(cin >> n >> m , n + m ){
        cout <<"Problem " << problem++ << ":\n";
        graph.resize(n);
        for(auto&itr:graph){
            cin >> itr;
        }
        vector<pair<int,char>>s;
        for(int i=0; i<n;++i){
            for(int j=0;j<m;++j){
                if(graph[i][j]!='.' && graph[i][j]!='$'){
                    char ch = graph[i][j];
                    int x= dfs(i,j , graph[i][j]); 
                    s.push_back(make_pair(x ,ch));
                }
            }
        }
        sort(s.begin(), s.end(), compare);
        for(auto&itr:s){
            cout << itr.second << ' ' << itr.first << '\n'; 
        }
    }
    return 0;
}
