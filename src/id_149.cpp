# Definition for a point
# class Point:
#     def __init__(self, a=0, b=0):
#         self.x = a
#         self.y = b

class Solution:
    # @param points, a list of Points
    # @return an integer
    def maxPoints(self, points):
        length = len(points)
        max = 0
        if length <= 2:
            return length
        for i in range(length):
            p1 = points[i]
            same_num = 0
            keys = dict()
            for j in range(i+1, length):
                p2 = points[j]
                if p1.x == p2.x and p1.y == p2.y:
                    same_num += 1
                    continue
                if p1.x == p2.x:
                    k = 'max'
                    b = p1.x
                else:
                    k = float(p1.y - p2.y) / float(p1.x - p2.x)
                    b = float(p1.x*p2.y - p2.x*p1.y) / float(p1.x - p2.x)
                if keys.has_key((k, b)):
                    keys[(k, b)] += 1;
                else:
                    keys[(k, b)] = 2
            if len(keys) == 0:
                if max < same_num + 1:
                    max = same_num + 1
                continue
            for v in keys.values():
                if max < v + same_num:
                    max = v + same_num
        return max