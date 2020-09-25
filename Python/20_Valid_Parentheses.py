class Solution:
    def isValid(self, s: str) -> bool:
        if len(s) % 2 != 0:
            return False
        if s == '':
            return True
        if s[0] == ')' or s[0] == ']' or s[0] == '}':
            return False
        l = []
        for i in s:
            if i == '(' or i == '[' or i == '{':
                if i == '(':
                    l.append(')')
                if i == '[':
                    l.append(']')
                if i == '{':
                    l.append('}')
            else:
                u = l.pop()
                if i != u:
                    return False
        if l != []:
            return False
        return True