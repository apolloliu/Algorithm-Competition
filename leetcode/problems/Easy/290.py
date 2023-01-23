class Solution(object):
    def wordPattern(self, pattern, s):
        """
        :type pattern: str
        :type s: str
        :rtype: bool
        """
        s = s.split();
        if len(pattern) != len(s):
            return False;
        for i in range(0, len(pattern)):
            for j in range(0, len(pattern)):
                if pattern[i] == pattern[j]:
                    if s[i] != s[j]:
                        return False;
                else:
                    if s[i] == s[j]:
                        return False;

        return True;
