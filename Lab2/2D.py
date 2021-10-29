fin = open("antiqs.in")
fout = open("antiqs.out", "w")
n = int(fin.readline())
a = [0] * n
for i in range(1, n + 1):
    a[i - 1] = i
for i in range(n - 1, 0, -1):
    a[n - i], a[(n - i) // 2] = a[(n - i) // 2], a[n - i]
print(*a, file = fout)
fout.close()