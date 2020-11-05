def sum_to_zero(n: int):
    out = []
    for i in range(-(n//2), (n//2+1)):
        if n % 2 == 0 and i == 0:
            continue
        out.append(i)

    return out


arr = sum_to_zero(3)
print(arr)
