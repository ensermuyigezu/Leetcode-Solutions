class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> a(26);
        for(char c : tasks){
            a[c - 'A']++;
        }
        sort(a.begin(), a.end());
        int time = 0;
        while(a[25] > 0){
            int i = 0;
            while(i <= n){
                if(a[25] == 0) break;
                if(i < 26 && a[25 - i] > 0) a[25 - i]--;
                time++;
                i++;
            }
            sort(a.begin(), a.end());
        }
        return time;
    }
};