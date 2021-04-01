import sys, math

def dsum(n):
    digit_sum = int(0)
    for i in range(1, 21):
        digit_sum += n % 10
        n /= 10
    return digit_sum

def solve():
    t = int(input())
    for i in range(t):
        n = int(input())
        while(True):
            if(math.gcd(int(n), int(dsum(n))) > 1):
                print(n)
                break
            n+=1
    
solve()