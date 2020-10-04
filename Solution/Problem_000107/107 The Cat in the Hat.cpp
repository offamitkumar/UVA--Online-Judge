#include <bits/stdc++.h>
using namespace std;
#define int int64_t
#define EPS 1e-9

signed main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); 
    cout.tie(nullptr);
#ifdef HELL_JUDGE
    freopen("input","r",stdin);
    freopen("output","w",stdout);
#endif
    int H , W; 
    while (cin >> H >> W , H+W) {
        /*
             H + N * (H / (N+1)) + N^2 * (H / (N+1)^2) + N^3 * (H / (N+1)^3) + ... + N^k (H / (N+1)^k) 
             here 
             N^k * (H / (N+1)^k = W (given in the question, these are the cats of height one)
             N^k / (N+1)^k = W / H 

             N^k = W 
             (N+1)^k = H 

             Taking log both side 
             k * log(N) = log(W)
             k * log(N+1) = log(H)
        */ 
        double num = log(H) / log(W);
        int low =1 , high = 1000; 
        int mid;
        while (low < high) {
            mid = (low + high) / 2;
            if (log(mid+1) / log(mid) - num > EPS) {
                low = mid + 1;
            } else if(log(mid+1) / log(mid) - num < -EPS){
                high = mid;
            } else {
                break;
            }
        }
        int N = mid; 
        int k = round(log(H) / log(N+1));
        int notWorking{}; 
        int totalHeight{}; 
        W = 1; 
        for (int i=0; i<k; ++i) {
            notWorking += W; 
            totalHeight += (W*H);
            W *= N; 
            H /= (N+1l);
        }
        cout << notWorking <<" " << totalHeight + (H*W) << '\n'; 
    }
    return 0;
}
