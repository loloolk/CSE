
def search(a, b):
    for i in range(len(a)):
        if a[i] == b:
            return i

def sort(a):
    for i in range(len(a)):
        for j in range(i + 1, len(a)):
            if a[i] > a[j]:
                a[i], a[j] = a[j], a[i]
    return a

def merge(a, b):
    return a + b

a = [6, 7, 8, 9, 10]
b = [1, 2, 3, 4, 5]

c = merge(a, b)
print(c)
print(sort(c))
print(search(c, 5))