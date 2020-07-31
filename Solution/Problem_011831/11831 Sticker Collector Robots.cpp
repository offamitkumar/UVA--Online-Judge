#include <bits/stdc++.h>
using namespace std;
#define int int64_t
vector<string>graph;
int ticket;
struct Pos{
    int n,m,x,y; 
    char d; // direction;
    bool setPos(int i , int j , char dir){
        if(dir == '.' || dir == '#' || dir =='*'){
            return false;
        }
        x = i; 
        y = j; 
        d = dir; 
        return true;
    }
    void Move(char c){
        if(c == 'D'){
            if(d=='N'){
                d = 'L';
            }else if(d == 'S'){
                d = 'O';
            }else if(d == 'L'){
                d = 'S';
            }else{
                d = 'N';
            }
        }else if(c== 'E'){
            if(d=='N'){
                d = 'O';
            }else if(d == 'S'){
                d = 'L';
            }else if(d == 'L'){
                d = 'N';
            }else{
                d = 'S';
            }
        }else if(c== 'F'){
            if(d=='N'){
                if(x - 1 >=0 && graph[x-1][y]!='#'){
                    x-=1; 
                    ticket+=(graph[x][y]=='*');
                    graph[x][y] = '$';
                }
            }else if(d == 'S'){
                if( x+1<n && graph[x+1][y]!='#'){
                    x+=1; 
                    ticket+=(graph[x][y]=='*');
                    graph[x][y] = '$';
                }
            }else if(d == 'O'){
                if(y - 1 >=0 && graph[x][y-1]!='#'){
                    y-=1; 
                    ticket+=(graph[x][y]=='*');
                    graph[x][y] = '$';
                }
            }else{
                if(y + 1 <m && graph[x][y+1]!='#'){
                    y+=1; 
                    ticket+=(graph[x][y]=='*');
                    graph[x][y] = '$';
                }
            }

        }
    }
};
signed main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    cout.tie(nullptr);
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
#endif

    int n , m , s;
    while( cin >> n >> m >> s , n+m+s) {
        ticket = 0;
        graph.clear();
        Pos p;
        p.n = n; 
        p.m = m; 
        graph.resize(n+10); 
        bool not_set = true;
        for(int i=0;i<n;++i){
            cin >> graph[i];
            for(int j=0;j<m && not_set;++j){
                not_set = (!p.setPos(i,j,graph[i][j]));
            }
        }
        string S; cin >> S;
        for(auto&itr:S){
            p.Move(itr);
        }
        cout << ticket << '\n';
    }

    return 0;
}
