class Solution {
public:
    int findNthDigit(int n) {
        if(n < 10) return n;
        long start = 1;
        long end = INT_MAX;
        long a = 0;
        long count = 0;
        while(start < end){
            count = 0;
            long mid = (start + end) / 2;
            long x = log10(mid);
            for(long i = 0; i < x; i++){
                count = count + (i + 1)*9*pow(10,i);
            }
            count = count + (mid - pow(10,x))*(x+1);
            if(n >= count && n <= count + x + 1){
                a = mid;
                break;
            } else if(n < count){
                end = mid;
            } else {
                start = mid;
            }
        }
        if(count == n){
            a--;
            string b = to_string(a);
            return b[b.length()-1] - '0';
        }
        string b = to_string(a);
        int v = 0;
        while(n-count > 0){
            v++;
            count++;
        }
        v--;
        return b[v] - '0';
    }
};