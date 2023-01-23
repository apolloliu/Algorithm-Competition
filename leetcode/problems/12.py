class Solution(object):
    def intToRoman(self, n):
        """
        :type num: int
        :rtype: str
        """
        s = "";
        while n:
            if n >= 1000: s += (n/1000)*'M'; n -= (n/1000)*1000;
            elif n >= 900: s += "CM"; n -= 900;
            elif n >= 500: s += (n/500)*'D'; n -= (n/500)*500;
            elif n >= 400: s += "CD"; n -= 400;
            elif n >= 100: s += (n/100)*'C'; n -= (n/100)*100;
            elif n >= 90: s += "XC"; n -= 90;
            elif n >= 50: s += (n/50)*'L'; n -= (n/50)*50;
            elif n >= 40: s += "XL"; n -= 40;
            elif n >= 10: s += (n/10)*'X'; n -= (n/10)*10;
            elif n >= 9: s += "IX"; n -= 9;
            elif n >= 5: s += (n/5)*'V'; n -= (n/5)*5;
            elif n == 4: s += "IV"; n -= 4;
            else: s += n*'I'; n -= n;
        return s;
