#include <bits/stdc++.h>
using namespace std;
#define int int64_t
bool compare(pair<char,int>&a , pair<char,int>&b){
    if(a.second == b.second){
        return a.first < b.first;
    }else{
        return a.second > b.second;
    }
}
vector<string>graph;
const int DSIZE = 4;
array<int,4>X{-1,1,0,0};
array<int,4>Y{0,0,-1,1};
bool check(int x , int y , char must){
    if(x<0 || y <0 || x >= graph.size() || y >= graph.at(0).size() || graph.at(x).at(y) != must){
        return false;
    }
    return true;
}
void dfs(int x , int y , char must){
    graph.at(x).at(y) = '$';
    for(int i=0; i<4; ++i){
        int tx = x + X.at(i); 
        int ty = y + Y.at(i); 
        if(check(tx , ty , must)){
            dfs(tx,ty,must);
        }
    }
    return ;
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
    int country = 1;
    while(t--){
        graph.clear();
        int l , b; cin >> l >> b; 
        graph.resize(l);
        for(int i =0; i<l; ++i){
            cin >> graph.at(i);
        }
        vector<pair<char,int>>v(26);
        for(int i=0; i<26; ++i){
            v.at(i).first = char(i+'a');
        }
        for(int i=0; i<l;++i){
            for(int j=0; j<b; ++j){
                if(graph.at(i).at(j) != '$'){
                    v.at(graph.at(i).at(j) - 'a').second+=1;
                    dfs(i,j,graph.at(i).at(j));
                }
            }
        }
        sort(v.begin() , v.end(),compare);
        cout <<"World #" << country++ << '\n';
        for(auto&itr:v){
            if(itr.second == 0){continue;}
            cout << itr.first << ": " << itr.second << '\n'; 
        }
    }
    return 0;
}
