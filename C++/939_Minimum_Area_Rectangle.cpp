class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        unordered_set<int> pointSet;
        for(vector<int> &point : points){
            pointSet.insert(40001*point[0] + point[1]);
        }
        int ans = INT_MAX;
        for(int i = 0; i < points.size(); ++i){
            for(int j = i+1; j < points.size(); ++j){
                if(points[i][0] != points[j][0] && points[i][1] != points[j][1]) {
                    if(pointSet.count(40001 * points[i][0] + points[j][1]) &&
                            pointSet.count(40001 * points[j][0] + points[i][1])) {
                        ans = min(ans, abs(points[j][0] - points[i][0]) *
                                            abs(points[j][1] - points[i][1]));
                    }
                }
            }
        }
        return ans < INT_MAX ? ans : 0;
    }
};