class Solution {
    int sum(queue<int> q){
        int sum = 0;
        while(!q.empty()){
            sum += q.front();
            q.pop();
        }
        return sum;
    }
public:
    int tribonacci(int n) {
        if(n < 3){
            if(n == 0) return 0;
            else return 1;
        }
        queue<int> d;
        d.push(0);
        d.push(1);
        d.push(1);
        int ans = 0;
        for(int i = 3; i <= n; i++){
            ans = sum(d);
            d.push(ans);
            d.pop();
        }
        return ans;
    }
};