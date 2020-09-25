class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        max_char ="" 
        max_val = 0  
        if len(s) == 0:
            return 0
        left = 0
        K = k
        counter = collections.defaultdict(int)
        for right in range(len(s)):
            counter[s[right]] += 1
            if counter[s[right]] > max_val: 
                max_val = counter[s[right]]
                max_char = s[right]
            k = K - (right-left + 1 - max_val)
			
            if k < 0:
                counter[s[left]] -= 1
                if s[left] == max_char:
                    max_val -= 1
                left += 1
        return right-left + 1