class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        count = {}
        parent = {}
        count[(0, 0)] = 1
        count[(0, -1)] = 1
        count[(0, 1)] = 1
        for i in range(1, target + 1):
            count[(i, -1)] = 0
            count[(0, i)] = 1
            parent[i] = []
        for k in range(len(candidates)):
            for x in range(1, target + 1):
                if x - candidates[k] >= 0:
                    count[(x, k)] = count[(x - candidates[k], k)] + count[(x, k - 1)]
                    if count[(x - candidates[k], k)] != 0:
                        if x - candidates[k] == 0:
                            parent[x] += [[candidates[k]]]
                        else:
                            for i in parent[x - candidates[k]]:
                                parent[x] += [[candidates[k]] + i]
                else:
                    count[(x, k)] = count[(x, k - 1)]
        return parent[target]