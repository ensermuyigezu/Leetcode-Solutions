class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> a;
        unordered_set<int> b;
        vector<int> ans;
        for(int &x : nums1){
            if(a.count(x) == 0) a.insert(x);
        }
        for(int &y : nums2){
            if(a.count(y) == 1 && b.count(y) == 0){
                b.insert(y);
                ans.push_back(y);
            }
        }
        return ans;
    }
};