class Solution:
    def isPalindrome(self, s: str) -> bool:
        if s == '':
            return True
        else:
            s = s.lower()
            i = 0
            j = len(s)-1
            while True:
                if i > j:
                    return True
                if (ord(s[i]) < 97 or ord(s[i]) > 122) and (ord(s[i]) < 48 or ord(s[i]) > 57):
                    i += 1
                elif (ord(s[j]) < 97 or ord(s[j]) > 122) and (ord(s[j]) < 48 or ord(s[j]) > 57):
                    j -= 1
                elif s[i] != s[j]:
                    return False
                else:
                    i += 1
                    j -= 1
            return True