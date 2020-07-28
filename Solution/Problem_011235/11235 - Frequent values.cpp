// {{{ 
// Header Files {{{

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <chrono>
#include <numeric>
#include <utility>

#include <bitset>
#include <tuple>
#include <queue>
#include <stack>
#include <vector>
#include <array>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <map>
#include <deque>

#include <climits>
#include <cstring>
#include <cmath>
#include <cassert>
#include <cstdio>

using namespace std;
using namespace std::chrono;

using namespace __gnu_pbds;

template<typename TypeInfo>
using new_set = tree< // find_by_order & order_of_key
TypeInfo ,
         null_type ,
         less<TypeInfo> ,
         rb_tree_tag ,
         tree_order_statistics_node_update 
         > ;

/* }}} */ 
/*Debug Section{{{*/

void Log_Gen() { cerr << endl; }
template <typename HEAD, typename... TAIL>
void Log_Gen(HEAD H, TAIL... T) {
  cerr << " " << (H);
  Log_Gen(T...);
}
#ifdef HELL_JUDGE
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", Log_Gen(__VA_ARGS__)
#else
#define debug(...) 0
#endif

/* }}} */
// defines & constants /*{{{*/

#define int int64_t
const int MAXM = (int)1e5+100;
const int MAXN = (int)1e5+100;
const int MOD = (int)1e9+7;

/*}}}*/
// range & VPi /*{{{*/

template<typename A, typename B>
ostream& operator<<(ostream&out, const pair<A, B>&p){
    out << p.first << ' ' << p.second ;
    return out;
}

template<typename A, typename B>
istream& operator>>(istream&in, pair<A, B>&p){
    in >> p.first >> p.second ;
    return in;
}

template<typename A> 
istream& operator>>(istream&in, vector<A>&vec){
    for(auto&itr:vec){
        in >> itr;
    }
    return in;
}

template<typename A>
ostream& operator<<(ostream&out,const vector<A>&vec){
    for(auto&itr:vec){
        out << itr <<' '; // VVV 
    }
    return out;
}

class NumberIterator : iterator<forward_iterator_tag, int> {
    public:
        int v;

        NumberIterator(int x) : v(x) {}

        operator int &() { return v; }

        int operator*() { return v; }
};
class range : pair<int,int> {
    public:
        range(int begin, int end) : pair<int,int>(begin, max(begin, end)) {}
        range(int n) : pair<int,int>((int)0, max((int)0, n)) {}

        NumberIterator begin() {
            return first;
        }

        NumberIterator end() {
            return second;
        }
};

/*}}}*/
// /*}}}*/
map<int,int>counter , stt;
// Segment Tree {{{
// default size is considered MAXN {{{
vector<int64_t>arr(MAXN);
vector<int64_t>seg_tree(4*MAXN);
// }}}
// FILL THIS FUNCTION  {{{
inline int64_t funct(const int64_t &value_one , const int64_t &value_two){
    return max(value_one , value_two); // ERROR POINT 1
}
//  }}}
// BUILD THE SEGMENT TREE  {{{
void build(int current_node , int left_, int right_){
    if(left_ == right_) {
        seg_tree[current_node] = counter[arr[left_]];
        return ;
    }
    int mid_point = left_ + (right_ - left_) / 2;
    build(2*current_node, left_ , mid_point);
    build(2*current_node+1, mid_point+1 , right_);
    seg_tree[current_node] = funct(seg_tree[2*current_node], seg_tree[2*current_node+1]);
    return ;
}
//   }}}
// RANGE QUERIES  {{{
int64_t query(int current_node , int start_, int end_, int q_start, int q_end){
    if(q_start > end_ || q_end < start_ || start_ > end_ || q_start > q_end){
        return 0; // ERROR POINT 2 , CHANGE WITH MIN OR MAX QUERY 
    }
    if(start_ == end_){
        return seg_tree[current_node];
    }
    if(q_start <= start_ && end_ <=q_end){
        return seg_tree[current_node];
    }
    int mid_point = start_ + (end_ - start_) / 2;
    int64_t left_ans = query(current_node*2,start_,mid_point,q_start, q_end);
    int64_t right_ans= query(current_node*2+1,mid_point+1,end_,q_start, q_end);
    return funct(left_ans, right_ans);
}
//     }}}
// FOR POINT UPDATE    {{{
void update(int current_node , int start , int end , int pos , int value){
    if(start > end || pos > end || pos < start ){
        return ;
    }
    if(start == pos && end == pos){
        seg_tree[current_node] = value;
        return ;
    }
    int mid = (start + end) /2;
    update(current_node*2 , start , mid , pos , value);
    update(current_node*2+1, mid+1 , end , pos , value);
    seg_tree[current_node] = funct(seg_tree[2*current_node] , seg_tree[2*current_node+1]);
}
//  }}}
// 0 BASED INDEXING , BE CAREFUL WITH QUESTION QUERY TYPE
// BUILD (CURRENT_NODE, ARRAY_START_POINT , ARRAY_END_POINT);
// QUERY(CURRENT_NODE, ARRAY_START_POINT , ARRAY_END_POINT, Q_START, Q_END);
// UPDATE(CURRENT_NODE, ARRAY_START_POINT, ARRAY_END_POINT, POSITION, VALUE);
// }}}
void solve(void){
    int n, q; 
    while(cin >> n, n){
       /* cleaning global containers {{{*/
        counter.clear(); 
        stt.clear();
/*}}}*/
        cin >> q; 
        for (int i = 0; i < n; ++i ) {
            cin >> arr[i];
            if(stt.find(arr[i])==stt.end()){
                stt[arr[i]] = i;
            }
            counter[arr[i]]++;
        }
        build(1 , 0 , n-1);
/* Query Section {{{*/
        while (q--) {
            int l, r; cin >> l >> r; 
            --l , --r; 
            if(arr[l] == arr[r]){
                cout << r - l + 1  << '\n'; 
            }else{
                int left_ptr = stt[arr[l]] + counter[arr[l]];
                int counter1 = left_ptr - l; 
                int counter2 = r - stt[arr[r]] + 1;
                int counter3 = query(1 , 0 , n-1 , left_ptr , stt[arr[r]]-1); 
                cout << max({counter3, counter2, counter1}) << '\n'; 
            }
        }
/*}}}*/
    }
}
// Main Function {{{

signed main(void){

#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
    freopen("error","w",stderr);
#endif 

    ios::sync_with_stdio(false); // FLUSH THE STREAM IF USING puts / printf / scanf/
    cin.tie(nullptr);            // DISABLE FOR INTERACTIVE PROBLEMS
    cout.tie(nullptr);           //

#ifdef HELL_JUDGE
    auto INITIAL_TIME = high_resolution_clock::now();
#endif 

    solve();

#ifdef HELL_JUDGE
    auto FINAL_TIME = high_resolution_clock::now();
    cout << "Time : "
         << duration_cast<milliseconds>(FINAL_TIME-INITIAL_TIME).count() 
         << " ms" << '\n'; 
#endif 
    return 0;
}

/*}}}*/
