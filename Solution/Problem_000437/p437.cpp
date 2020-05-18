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
int main(void){
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
    freopen("error","w",stderr);
#endif 
    int totalBoxPresent; 
    int testCaseCounter=1;
    while(cin>>totalBoxPresent,totalBoxPresent){
        vector<array<int,3>>boxes;
        array<int , 3>box; 
        for(int i=0; i < totalBoxPresent; ++i){
            cin>>box[0]>>box[1]>>box[2];
            sort(box.begin() , box.end());
            do{
                boxes.push_back(box);
            }while(next_permutation(box.begin() , box.end()));
        }
        sort(boxes.begin() , boxes.end() , [](const array<int,3>&boxOne , const array<int,3>&boxTwo){
                int areaOne = boxOne[0]*boxOne[1];
                int areaTwo = boxTwo[0]*boxTwo[1];
                return areaOne > areaTwo;  // let the bigger box be first 
                });
        for(auto&itr:boxes){
            cerr<<itr[0]<<'\t'<<itr[1]<<'\t'<<itr[2]<<'\n';
        }
        cerr<<'\n';
        const size_t totalBoxes = boxes.size();
        vector<int>maxHeightReached(totalBoxes , 0);
        for(int box=0;box < static_cast<int>(totalBoxes); ++box){
            maxHeightReached[ box ] = boxes[box][2];
        }
        for(int i=0; i <  static_cast<int>(totalBoxes); ++i){
            auto&upperBoxLength = boxes[i][0];
            auto&upperBoxBreadth = boxes[i][1];
            auto&upperBoxHeight = boxes[i][2];
            for(int j = 0; j < i; ++j){ // can we place ith box on top of jth box 
                auto&lowerBoxLength = boxes[j][0];
                auto&lowerBoxBreadth= boxes[j][1];
                auto&lowerBoxHeight = boxes[j][2];
                if(upperBoxLength < lowerBoxLength and upperBoxBreadth < lowerBoxBreadth){
                    maxHeightReached[i] = max(maxHeightReached[i] , upperBoxHeight+maxHeightReached[j]);
                }
            }
        }
        const int& maxHeight = *max_element(maxHeightReached.begin() , maxHeightReached.end());
        printf("Case %d: maximum height = %d\n",testCaseCounter++ , maxHeight);
    }
    return 0;
}
