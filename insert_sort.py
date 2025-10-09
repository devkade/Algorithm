L = [4,2,1,0,5,3,6]

def insert_sort(L):
    nlen = len(L)
    for i in range(1, nlen):
        for j in range(i, 0, -1):
            if L[j] < L[j-1]:
                L[j], L[j-1] = L[j-1], L[j]
    
    return L;

print(insert_sort(L))