#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
#include <utility>
#include <queue>
#include <stack>
#include <string>
#include <cstring>
#include <cmath>
#include <map>
#include <unordered_map>
#include <vector>
#include <array>
#include <set>
#include <climits>
#include <sstream>
#include <iomanip>
#include <cassert>
#include <bitset>
#include <numeric>
using namespace std;
using namespace __gnu_pbds;
typedef tree< // find_by_order & order_of_key
        int ,
        null_type ,
        less<int> ,
        rb_tree_tag ,
        tree_order_statistics_node_update 
> new_set;
#define MOD 1000000007
vector<int>x = {-1, -1,-1, 0, 0, 1, 1, 1};
vector<int>y = {-1, 0 , 1,-1, 1,-1, 0, 1};
int main(void){
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
    freopen("error","w",stderr);
#endif 
    int m, n;
    int case_counter{1};
    while (cin >> n >> m && m != 0 && n != 0) {
        if (case_counter > 1) {
            cout << '\n'; 
        }
        vector<string>grid(n);
        for (int i = 0; i < n; ++i) {
            cin >> grid[i];
        }
        auto valid = [&m, &n](int x, int y) {
            if (x < 0 || y < 0 || x >= n || y >= m) {
                return false;
            }else{
                return true;
            }
        };
        vector<string>mines = grid;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == '*') {
                    mines[i][j] = '*';
                    continue;
                }
                int mine_counter{};
                for (int k = 0; k < 8; ++k) {
                    if(valid(i+x[k], j+y[k])){
                        mine_counter += (grid[i+x[k]][j+y[k]] == '*');
                    }
                }
                mines[i][j] = char(mine_counter+(int)'0');
            }
        }
        printf("Field #%d:\n",case_counter++);
        for (int i = 0; i < n; ++i) {
            cout << mines[i] << '\n';
        }
    }
    return 0;
}
