class Solution(object):
    def findDuplicate(self, paths):
        """
        :type paths: List[str]
        :rtype: List[List[str]]
        """
        res = dict()
        for path in paths:
            name = path.split()
            root = name[0]
            for fn in name[1:]:
                tmp = fn.split('(')
                f = root+'/'+tmp[0]
                c = tmp[1].split(')')[0]
                if c in res:
                    res[c].append(f)
                else:
                    res.setdefault(c, [])
                    res[c].append(f)
        # print(res)
        fin = list()
        for key, value in res.items():
            if len(value) > 1:
                fin.append(value)
        return fin

