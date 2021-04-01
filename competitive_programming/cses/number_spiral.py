t = int(input())

def f(y, x):
    if(x > y):
        if(x % 2 == 1):
            return f(x, x) + x - y
        if(x % 2 == 0):
            return f(x, x) + y - x
    if(y > x):
        if(y % 2 == 1):
            return f(y, y) + x - y
        if(y % 2 == 0):
            return f(y, y) + y - x
    return 1 + x * (x - 1)

for i in range(t):
    y, x = input().split(' ')
    y = int(y)
    x = int(x)
    print(f(y, x))