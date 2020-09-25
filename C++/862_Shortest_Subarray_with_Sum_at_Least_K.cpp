class Solution {
public:
    int shortestSubarray(vector<int>& A, int K) {
        int N = A.size();
        vector<long> P(N+1,0);
        for(int i = 0; i < N; ++i){
            P[i+1] = P[i] + (long) A[i];
        }
        int ans = N+1;
        deque<int> monoq;
        for(int y = 0; y < P.size(); ++y){
            while(!monoq.empty() && P[y] <= P[monoq.back()]){
                monoq.pop_back();
            }
            while(!monoq.empty() && P[y] >= P[monoq.front()] + K){
                ans = min(ans, y - monoq.front());
                monoq.pop_front();
            }
            monoq.push_back(y);
        }
        return ans < N+1 ? ans : -1;
    }
};