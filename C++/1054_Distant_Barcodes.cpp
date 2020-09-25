class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        int m[10001] = {0};
        vector<pair<int, int>> s;
        for (auto n : barcodes) ++m[n];
        for (int i = 0; i < 10001; i++){
            if(m[i] > 0){
                s.push_back({m[i],  i});
            }
        } 
        sort(s.begin(),s.end());
        int pos = 0;
        for (auto it = s.rbegin(); it != s.rend(); ++it) {
            for(int i = 0; i < it->first; i++, pos+=2){
                if(pos >= barcodes.size()) pos = 1;
                barcodes[pos] = it->second;
            }
        }
        return barcodes;
    }
};