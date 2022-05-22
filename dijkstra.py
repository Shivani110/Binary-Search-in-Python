class GRAPH():
    def __init__(self, A):
        self.v = A
        self.g = [[0 for column in range(A)]
                      for row in range(A)]

    def solution(self, D):
        print("vertex \t Distance_from_Source")
        for x in range(self.v):
            print(x, "\t\t", D[x])

    def min_dis(self, D, p):
        low = 100000
        for u in range(self.v):
            if D[u] < low and p[u] == False:
                low = D[u]
                low_index = u
        return low_index

    def Dijk(self, S):
        D = [100000] * self.v
        D[S] = 0
        p = [False] * self.v
        for cout in range(self.v):
            z = self.min_dis(D, p)
            p[z] = True
            for u in range(self.v):
                if (self.GRAPH[z][u] > 0 and
                        p[u] == False and
                        D[u] > D[z] + self.GRAPH[z][u]):
                        D[u] = D[z] + self.GRAPH[z][u]
        self.solution(D)


G = GRAPH(6)
G.GRAPH = [[0, 2, 0, 0, 0, 0],
           [2, 0, 5, 0, 0, 0],
           [0, 5, 0, 4, 0, 2],
           [0, 0, 4, 0, 6, 0],
           [0, 0, 0, 6, 0, 8],
           [0, 0, 2, 12, 0, 0]
           ]
G.Dijk(0)
