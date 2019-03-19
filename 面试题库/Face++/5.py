```leetcode 71. Simplify Path```
class Solution(object):
    def simplifyPath(self, path):
        """
        :type path: str
        :rtype: str
        """
        path_arr = path.split('/')
        fin_path = list()
        # print(path_arr)
        for s in path_arr:
            # print(s)
            # print(len(s))
            if s == "." or len(s) == 0:
                continue
            elif s == "..":
                if len(fin_path) :
                    fin_path = fin_path[:-1]
            else:
                fin_path.append(s)

        result = ""
        # print("size of fin_path is: %d" % len(fin_path))
        for s in fin_path:  
            result += '/' + s
        if len(result) == 0: result = '/'
        return result
