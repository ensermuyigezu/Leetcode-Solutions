class Solution:
    def myAtoi(self, str: str) -> int:
        if str == '':
            return 0
        a = ''
        d = {'0': 0, '1':1, '2':2, '3':3, '4':4, '5':5, '6':6, '7':7, '8':8, '9':9}
        k = False
        for i in str:
            if i in d or ((i == '-' or i == '+') and k == False):
                a += i
                k = True
            elif k == True and i not in d:
                if a == '-' or a == '+':
                    return 0
                break
            elif k == False and i not in d and i != ' ':
                return 0
        if a == '' or a == '+' or a == '-' :
            return 0
        if a[0] == '-' and int(a) > -2147483648:
            return int(a)
        elif (a[0] != '-' or a[0] == '+') and int(a) < 2147483648:
            return int(a)
        else:
            return -2147483648 if a[0] == '-' else 2147483647