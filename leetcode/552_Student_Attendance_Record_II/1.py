class Solution(object):
   def checkRecord(self, n):
        mod = 10 ** 9 + 7
        P = 1
        A = AL = ALL = L = LL = 0
        for i in range(n):
            A, P, AL, ALL, L, LL = sum((A, P, AL, LL, L, ALL)) % mod, sum((P, L, LL)) % mod, A, AL, P, L
        return sum((A, P, AL, LL, L, ALL)) % mod
