N = int(input())
MAX = int(1e12+3)
for i in range(1, MAX):
    if int(str(i) * 2) > N:
        print(i-1)
        exit()