class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        d = {}
        for i in range(len(strs)):
            word = ''.join(sorted(strs[i]))
            if word not in d:
                d.setdefault(word, [])
            d[word].append(strs[i])
        l = []
        for i in d.values():
            l.append(i)
        return l