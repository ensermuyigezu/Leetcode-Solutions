class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        sort(points, 0, points.size() - 1, K);
        return vector(points.begin(), points.begin() + K);
    }
    void sort(vector<vector<int>>& points, int i, int j, int K){
        if(i >= j) return;
        int k = i; // random index
        swap(points, i, k);
        int mid = partition(points, i, j);
        int leftLength = mid - i + 1;
        if(K < leftLength){
            sort(points, i, mid - 1, K);
        } else if(K > leftLength){
            sort(points, mid + 1, j, K - leftLength);
        }
    }
    int partition(vector<vector<int>>& points, int i, int j){
        int oi = i;
        int pivot = dist(points, i);
        i++;
        while(true){
            while(i < j && dist(points, i) <= pivot){
                i++;
            }
            while(i <= j && dist(points, j) >= pivot){
                j--;
            }
            if(i >= j) break;
            swap(points, i, j);
        }
        swap(points, oi, j);
        return j;
    }
    int dist(vector<vector<int>>& points, int i){
        return points[i][0] * points[i][0] + points[i][1] * points[i][1];
    }
    void swap(vector<vector<int>>& points, int i, int j){
        int t0 = points[i][0];
        int t1 = points[i][1];
        points[i][0] = points[j][0];
        points[i][1] = points[j][1];
        points[j][0] = t0;
        points[j][1] = t1;
    }
};