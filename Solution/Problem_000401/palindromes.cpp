//  Author : Amit Kumar 

//  #include <ext/pb_ds/assoc_container.hpp>
//  #include <ext/pb_ds/tree_policy.hpp>

  #include <iostream>
//  #include <algorithm>
  #include <string>
//  #include <sstream>
//  #include <fstream>
//  #include <iomanip>
//  #include <chrono>
//  #include <numeric>
//  #include <utility>

//  #include <bitset>
//  #include <tuple>
//  #include <queue>
//  #include <stack>
//  #include <vector>
//  #include <array>
//  #include <unordered_map>
//  #include <unordered_set>
//  #include <set>
  #include <map>
//  #include <deque>

//  #include <climits>
  #include <cstring>
//  #include <cmath>
//  #include <cassert>
#include <cstdio>
using namespace std;
//  using namespace std::chrono;
//  using namespace placeholders;
//  using namespace __gnu_pbds;
//  template<typename TypeInfo>
//  using new_set = tree< // find_by_order & order_of_key
//          TypeInfo ,
//          null_type ,
//          less<TypeInfo> ,
//          rb_tree_tag ,
//          tree_order_statistics_node_update 
//  > ;
const int MAXM = (int)1e5+100;
const int MAXN = (int)1e5+100;
const int MOD = (int)1e5+100;

int main(void){
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
    freopen("error","w",stderr);
#endif 
//    auto initial_time = high_resolution_clock::now();
    map<char,char>rev = {
        {'A','A'},
        {'E','3'},
        {'H','H'},
        {'I','I'},
        {'J','L'},
        {'M','M'},
        {'Y','Y'},
        {'Z','5'},
        {'O','O'},
        {'1','1'},
        {'2','S'},
        {'E','3'},
        {'3','E'},
        {'S','2'},
        {'5','Z'},
        {'H','H'},
        {'T','T'},
        {'I','I'},
        {'U','U'},
        {'L','J'},
        {'V','V'},
        {'8','8'},
        {'W','W'},
        {'L','J'},
        {'X','X'}
    };
    string s; 
    while(cin >> s){
        bool isP{true} , isM{true};
        int n = s.size();
        if(n==1){
            if(s[0] != rev[s[0]]){
                isM = false;
            }
        }
        --n;
        int i = 0;
        while(i<=n && (isP || isM)){
            if(s[i] != s[n]){
                isP = false;
            }
            if(s[i] != rev[s[n]]){
                isM = false;
            }
            ++i;
            --n;
        }
        cout << s <<" --" ;
        if(isP){
            if(isM){
                printf(" is a mirrored palindrome.");
            }else{
                printf(" is a regular palindrome.");
            }
        }else{
            if(isM){
                printf(" is a mirrored string.");
            }else{
                printf(" is not a palindrome.");
            }
        }
        puts("");
        puts("");
    }
//    auto final_time = high_resolution_clock::now();
//    cout << duration_cast<milliseconds>(final_time-initial_time).count() << " ms" << '\n'; 
    return 0;
}
