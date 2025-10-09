L = [8,2,5,3,9,4,7,6,1]

def partition_list(L, start, end):
    pivot = L[end]
    i = start -1

    for j in range(start, end):
        if L[j]<pivot:
            i=i+1
            L[j], L[i]=L[i], L[j]
    i=i+1
    L[i], L[end] = L[end], L[i]
    return i

def quick_sort(L, start, end):
    if start >= end:
        return L;
    pivot = partition_list(L, start, end)
    quick_sort(L, start, pivot-1)
    quick_sort(L, pivot+1, end)
    return L

print(quick_sort(L, 0, len(L)-1))