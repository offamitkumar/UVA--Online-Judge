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
unordered_map<char , pair<int,int>>ump;
int main(void){
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
    freopen("error","w",stderr);
#endif 
    int nMatrix; cin>>nMatrix;
    for(int i=0;i<nMatrix;++i){
        char matrix ;int row , col; cin>>matrix>>row>>col; 
        ump[matrix] = make_pair (row , col);
    }
    cin.ignore();
    string s;
    bool more = false;
    while(getline(cin , s)&& !s.empty()){
        more = true;
        unordered_map<char , pair<int,int>>temp;
        char new_matrix_name = 'a';
        long long total_cost{};
        stack<char>st;
        bool error = false;
        for(size_t index=0;index < s.size(); ++index){
            if(s[index]!=')'){
                st.push(s[index]);
            }else if(s[index] == ')'){
                int row_f , col_f , row_s , col_s; // row_f -> row_first & row_s -> row_second
                char ch = st.top();
                if(temp.find(ch)!=temp.end()){ // pointed matrix belong here  , as it stored in stack so upper matrix is second
                    tie(row_s , col_s) = temp[ch];
                }else{
                    tie(row_s , col_s) = ump[ch];
                }
                st.pop(); ch = st.top(); st.pop(); st.pop(); // bracket 
                if(temp.find(ch)!=temp.end()){ // pointed matrix belong here 
                    tie(row_f , col_f) = temp[ch];
                }else{
                    tie(row_f , col_f) = ump[ch];
                }
                if(col_f != row_s){
                    error = true;
                    break;
                }
                int new_row = row_f;
                int new_col = col_s;
                total_cost += (row_f * col_f * col_s);
                temp[new_matrix_name] = make_pair(new_row , new_col);
                st.push(new_matrix_name); // push the new matrix to stack 
                new_matrix_name++;
            }
        }
        if(error){
            printf("error\n");
        }else{
            printf("%lld\n",total_cost);
        }
    }
    return 0;
}
