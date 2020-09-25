class Solution {
public:
    int numComponents = 0;
    
    int find(int x, vector<int> &parent){
        int root = x;
	    while(root != parent[root]){
	    	root = parent[root];
	    }
	    while(x != root){
	        int next = parent[x];
	        parent[x] = root;
	        x = next;
	    }
	    return root;
    }
    
    void unify(int p, int q, vector<int> &parent, vector<int> &sz){
        int root1 = find(p, parent);
        int root2 = find(q, parent);
        if(root1 == root2) return;
        if (sz[root1] < sz[root2]){
	        sz[root2] += sz[root1];
	        parent[root1] = root2;
        } else {
	        sz[root1] += sz[root2];
	        parent[root2] = root1;
    	}
	    numComponents--;
	}
    
    int findCircleNum(vector<vector<int>>& M) {
        if(M.size() == 0)return 0;
        int n = M.size();
        vector<int> id(n, 0);
        vector<int> sz(n, 0);
        numComponents = n;
        for(int i = 0; i < n; i++){
            id[i] = i;
            sz[i] = 1;
        }
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                if(M[i][j]){
                    int group1 = find(i, id);
                    int group2 = find(j, id);
                    if(group1 != group2){
                        unify(group1, group2, id, sz);
                    }
                }
            }
        }
        return numComponents;
    }
};