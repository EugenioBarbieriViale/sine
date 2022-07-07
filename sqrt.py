import random

m = int(input())
result = random.randint(1,m)

def sqrt(x,m):
    return (x/2)+(m/(2*x))

for i in range(10):
    result = sqrt(result, m)

print(round(result,20))
