class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int ans = 0;
        for(int i = 0; i <= n; i++){
            if(isValid(citations, i)){
                ans = max(ans, i);
            }
        }
        return ans;
    }
    bool isValid(vector<int>& citations, int h){
        int n = citations.size();
        int i = 0;
        int j = 0;
        for(int &x : citations){
            if(x >= h) i++;
            if(x <= h) j++;
        }
        return (i >= h && j >= n - h);
    }
};