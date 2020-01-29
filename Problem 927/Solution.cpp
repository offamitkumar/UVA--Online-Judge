/*
 * As the given constraints are very tight 
 * so even a single mistake in the input and output will certainly 
 * lead you to the wrong answer. 
 */
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
#include <cassert>
#include <bitset>
#include <numeric>
using namespace std;
#define mod 1000000007
array<long long,1000000>sq;
void utility(void){
    long long sum = 0ll;
    // sequence 1 , 2 , 2 , 3 , 3 , 3 , 4 , 4 , .......
    sq[0] = sum;
    for(int i=0;;++i){
        sum+=i;
        if(sum>=1000000)
            break;
        sq[sum]=i+1ll;
    }
}
// simple function implementation 
unsigned long long sol(long long t , long long n,vector<long long>&coff , long long i){
    if(i==t){
        return 0ll;
    }
    return coff[i] * pow(n , i) + sol(t,n,coff,i+1);
}
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
    freopen("error","w",stderr);
#endif 
    utility();
    int c; cin>>c;
    while(c--){
        long long n;cin>>n;n++;
        vector<long long>coff(n);
        for(auto &itr:coff){
            cin>>itr;
        }
        long long d,k; cin>>d>>k;
        long long index = (k-1ll)/d;
        //finding the correct position as generated string is not perfect  
        while(index>0ll and sq[index]==0ll)
            index--;
        cout<<sol(n,sq[index],coff,0ll)<<endl;
    }

    return 0;
}
