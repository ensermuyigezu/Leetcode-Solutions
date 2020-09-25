class Solution {
public:
    int subarraysWithKDistinct(vector<int>& A, int K) {
        return lengthOfLongestSubstringKDistinct(A, K) - lengthOfLongestSubstringKDistinct(A, K-1);
    }
    
    int lengthOfLongestSubstringKDistinct(vector<int>& s, int k){
        int result = 0;
        int begin = 0;
        int end = 0;
        int n = s.size();
        unordered_map<int, int> unique;
        while(end < n){
            unique[s[end]]++;
            while(unique.size() > k){
                unique[s[begin]]--;
                if(unique[s[begin]] == 0){
                    unique.erase(s[begin]);
                }
                begin++;
            }
            result += end - begin + 1;
            end++;
        }
        return result;
    }
};