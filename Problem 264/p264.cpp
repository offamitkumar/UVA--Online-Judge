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
#define MAXN 10000000+10

struct Node{
    int numerator;
    int denominator;
};

Node arr[MAXN];

int main(void){
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
    freopen("error","w",stderr);
#endif 
    arr[0].numerator = arr[0].denominator = 1;
    int i=1;
    int increase = 0; // 0 -> increment the denominator in condition ( numerator == denominator )
                      // 1 -> increment the numerator in condition ( numerator == denominator )
    while(i<MAXN){
        if(arr[i-1].numerator == 1 ||  arr[i-1].denominator == 1){
                if(arr[i-1].numerator == 1){
                    arr[i].denominator = arr[i-1].denominator + 1;
                    arr[i].numerator = arr[i-1].numerator;
                }else{
                    arr[i].numerator = arr[i-1].numerator + 1;
                    arr[i].denominator = arr[i-1].denominator;
                }
            increase^=1;
            i++;
        }
        if(increase){
            arr[i].numerator =arr[i-1].numerator+ 1;
            arr[i].denominator = arr[i-1].denominator-1;
        }else{
            arr[i].numerator =arr[i-1].numerator- 1;
            arr[i].denominator = arr[i-1].denominator+1;
        }
        i++;
    }
    while(cin >> i){
        printf("TERM %d IS %d/%d\n",i,arr[i-1].numerator , arr[i-1].denominator);
    }
    return 0;
}
