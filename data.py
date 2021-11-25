import random

n = random.randint(1, 5)
m = random.randint(0, 20)
print(n, m)
print(1, end=' ')
for i in range(n-1):
    print(random.randint(2, m), end=' ')
