class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> a;
        unordered_map<int, int> b;
        vector<int> ans;
        for(int &x : nums1){
            a[x]++;
        }
        for(int &y : nums2){
            b[y]++;
        }
        for(auto x : a){
            if(b.count(x.first) == 1){
                int k = min(a[x.first], b[x.first]);
                for(int i = 0; i < k; i++){
                    ans.push_back(x.first);
                }
            }
        }
        return ans;
    }
};