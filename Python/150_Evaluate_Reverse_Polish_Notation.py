class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        s = [];
        for i in tokens:
            if i == "+" or i == "-" or i == "*" or i == "/":
                x = s.pop()
                y = s.pop()
                if i == "+":
                    s.append(y + x)
                elif i == "-":
                    s.append(y - x)
                elif i == "*":
                    s.append(y * x)
                else: 
                    if(y/x < 0):
                        s.append(-(abs(y)//abs(x)))
                    else:
                        s.append(y // x)
            else:
                s.append(int(i))
        return s.pop()
            