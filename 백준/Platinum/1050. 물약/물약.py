import heapq

N, M = map(int, input().split())

costs = {}
q = []
for _ in range(N):
    food, c = input().split()
    costs[food]=int(c)
    heapq.heappush(q, (int(c), food))

indegree = [set() for _ in range(M)]
recipes = []
adj = {}
for i in range(M):
    food, recipe = input().split('=')
    tmp = []
    for rec in recipe.split('+'):
        n = int(rec[0])
        ing = rec[1:]
        tmp.append((n, ing))
        indegree[i].add(ing)
        if ing in adj:
            adj[ing].add(i)
        else :
            adj[ing]= {i}
    recipes.append((food, tmp))

ans = 1000000002
while q:
    cost, food = heapq.heappop(q)
    if cost>costs[food]: continue
    if food=='LOVE':
        ans = min(ans, cost)
    if food not in adj: continue
    for recipe in adj[food]:
        if food in indegree[recipe]:
            indegree[recipe].remove(food)
        if len(indegree[recipe])==0:
            newfood = recipes[recipe][0]
            newrecipe = recipes[recipe][1]
            newcost = 0
            for n, ing in newrecipe:
                newcost+=n*costs[ing]
            newcost = min(newcost, 1000000001)
            if newfood not in costs:
                costs[newfood]=newcost
                heapq.heappush(q, (newcost, newfood))
            elif newcost<costs[newfood]:
                costs[newfood]=newcost
                heapq.heappush(q, (newcost, newfood))
if ans==1000000002: print(-1)
else : print(ans)
