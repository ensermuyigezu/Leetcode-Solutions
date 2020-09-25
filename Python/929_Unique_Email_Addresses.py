class Solution:
    def numUniqueEmails(self, emails: List[str]) -> int:
        d = {}
        for e in emails:
            x = ''
            k = True
            for i in range(len(e)):
                if e[i] == '@':
                    x += e[i:]
                    break
                elif e[i] == '.' and k:
                    continue
                elif e[i] == '+':
                    k = False
                elif k:
                    x += e[i]
            if x not in d:
                d[x] = 1
        return len(d)
