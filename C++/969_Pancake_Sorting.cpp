class Solution {
public:
    int findIndex(vector<int>& v, int largest){
        for(int i = 0; i < v.size(); i++){
            if(v[i] == largest) return i;
        }
        return 0;
    }
    void flip(vector<int>& v, int idx){
        int i = 0;
        int j = idx;
        while(i < j){
            int temp = v[i];
            v[i] = v[j];
            v[j] = temp;
            i++;
            j--;
        }
    }
    vector<int> pancakeSort(vector<int>& A) {
        vector<int> ans;
        int N = A.size();
        int largest = N;
        int idxLargest;
        for(int i = 0; i < N; i++){
            idxLargest = findIndex(A, largest);
            flip(A, idxLargest);
            ans.push_back(idxLargest + 1);
            flip(A, largest - 1);
            ans.push_back(largest);
            largest -= 1;
        }
        return ans;
    }
};