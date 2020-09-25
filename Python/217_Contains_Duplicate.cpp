class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> a;
        for(int x : nums){
            if(a.count(x) == 1) return true;
            a.insert(x);
        }
        return false;
    }
};