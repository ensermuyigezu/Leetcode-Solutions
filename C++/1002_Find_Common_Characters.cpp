class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        vector<int> hash1(26, 0);
        vector<int> hash2(26, 0);
        for(auto ch : A[0]) {
            hash1[ch - 'a']++;
        }
        for(int i = 1; i < A.size(); i++) {
            for(auto ch : A[i]) {
                hash2[ch - 'a']++;
            }
            for(int k = 0; k < 26; k++) {
                hash1[k] = min(hash1[k], hash2[k]);
                hash2[k] = 0;
            }
        }
        vector<string> commonCharacters; 
        for(int i = 0; i < 26; i++)
            if(hash1[i] > 0) {
                int count = hash1[i];
                while(count--) {
                    char x = i + 'a';
                    string ans;
                    ans = x;
                    commonCharacters.push_back(ans);
                }     
            }
        return commonCharacters; 
    }
};