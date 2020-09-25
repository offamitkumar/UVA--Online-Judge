#include <bits/stdc++.h>
using namespace std;
#define int int64_t
vector<vector<int>>grid;
struct Robot{
    int x, y; 
    char dir;
    bool lost;
    bool safe(int X , int Y, int Xfrom , int Yfrom) {
        if (X < 0 || Y < 0 || X >= (int)grid.size() || Y >= (int)grid[0].size()) {
            if(grid[Xfrom][Yfrom]){ // if previously none of the robot lost from this cell
                // then this robot will be lost 
                lost =  true;
            }
            return false;
        }
        return true;
    }
    Robot(int X, int Y, char dire) {
        lost = false;
        this -> x = X; 
        this -> y = Y; 
        this -> dir = dire;
    }
    ~Robot() {
        cout << x << ' ' << y << ' ' << dir; 
        if(lost) {
            grid[x][y] = 0;
            cout << " LOST" ;
        }
        cout << '\n'; 
    }
    void change_direction(char ch) {
        if (dir == 'N') {
            if (ch == 'L') {
                dir = 'W';
            } else {
                dir = 'E';
            }
        } else if (dir == 'S') {
            if (ch == 'L') {
                dir = 'E';
            } else {
                dir = 'W';
            }
        } else if (dir == 'W') {
            if (ch == 'L') {
                dir = 'S';
            } else {
                dir = 'N';
            }
        } else {
            if (ch == 'L') {
                dir = 'N';
            } else {
                dir = 'S';
            }
        }
    }
    void move_forward(char ch) { 
        if (dir == 'N') {
            if (safe(x , y+1 , x, y)){
                y+=1;
            }
        } else if (dir == 'S') {
            if (safe(x , y-1 , x, y)){
                y-=1;
            }
        } else if (dir == 'W') {
            if (safe(x-1 , y , x, y)){
                x-=1;
            }
        } else {
            if (safe(x+1 , y , x, y)){
                x+=1;
            }
        }
    }
    void move(const string &s) {
        for(auto &itr: s) {
            if (itr != 'F') {
                change_direction(itr);
            }else{
                move_forward(itr);
            }
            if (lost) {
                break;
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
    int a, b;  cin >> a >> b; 
    grid.resize(a+1 , vector<int>(b+1, 1));
    char ch; 
    while(cin >> a >> b >> ch) {
        Robot r(a,b,ch); 
        string s; cin >> s; 
        r.move(s); 
    }
    return 0;
}
