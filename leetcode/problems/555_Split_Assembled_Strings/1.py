class Solution(object):
    def splitLoopedString(self, strs):
        """
        :type strs: List[str]
        :rtype: str
        """
        for i in xrange(len(strs)):
            strs[i] = max(strs[i][::-1], strs[i])
        n = len(strs)
        res = ""
        for i in xrange(n):
            for s in (strs[i], strs[i][::-1]):
                for k in xrange(len(s)):
                    t = s[k:] + "".join(strs[i+1:] + strs[:i]) + s[0:k]
                    res = max(res, t)
        return res

