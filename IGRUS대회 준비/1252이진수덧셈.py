import sys
a,b = map(str,sys.stdin.readline().split())
result_a = 0
result_b = 0
for i in range(len(a)):
    result_a += int(a[len(a) - i -1]) * (2**i)
for j in range(len(b)):
    result_b += int(b[len(b)- j -1]) * (2**j)
sum = result_a + result_b
print(str(bin(sum)[2:]))
