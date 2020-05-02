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
vector<string>grid;
bitset<30>diagonal1 , diagonal2 , column;
bool check(int row ,int col ,int n){

    return (diagonal2[row+col]==false && diagonal1[row-col+n-1]==false && column[col]==false && grid[row][col]!='*');

    // code written below will give TLE and current code will be accepted.
    // time : 3.430 seconds. 

/*
    // left column
    int i = row ; int j = col;
    while(i>=0 && j<n){
        if(grid[i][j]=='Q'){
            return false;
        }
        i--;
        j++;
    }
    i = row ;  j = col;
    while(i>=0 && j>=0){
        if(grid[i][j]=='Q'){
            return false;
        }
        i--;
        j--;
    }
    for(i=0;i<row;++i){
        if(grid[i][col]=='Q'){
            return false;
        }
    }
    return grid[row][col]!='*';
    */
}
int count(int total_queen , int current_queen , int current_row){
    if(current_queen == total_queen){
        return 1;
    }
    int counter{};
    for(int i=0; i < total_queen; ++i){
        if(grid[current_row][i]!='*' && check(current_row , i , total_queen)){
            grid[current_row][i] = 'Q';
            diagonal1[current_row-i+total_queen-1] = diagonal2[i+current_row] = column[i] = true;
            counter+=count(total_queen , current_queen+1 ,current_row+1);
            grid[current_row][i] = '.';
            diagonal1[current_row-i+total_queen-1] = diagonal2[i+current_row] = column[i] = false;
        }
    }
    return counter;
}
int main(void){
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
    freopen("error","w",stderr);
#endif 
    int n;
    int case_counter=1;
    while(cin>>n && n!=0){
        diagonal1.reset();
        diagonal2.reset();
        column.reset();
        grid.resize(n);
        for(int i=0;i<n;++i){
            cin>>grid[i];
        }
        printf("Case %d: ",case_counter++);
        cout<<count(n , 0 , 0)<<'\n';
    }
    return 0;
}
