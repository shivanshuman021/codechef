# cook your dish here
t = int(input())

for te in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    d = {}

    for e in a:
        if e in d:
            d[e] += 1
        else:
            d[e] = 1

    #keymax = max(d,key = d.get())
    freq = {}
    #val = d[keymax]

    for k, v in d.items():
        if v in freq:
            freq[v] += 1
        else:
            freq[v] = 1

    keymax = max(freq, key=freq.get)
    val = freq[keymax]

    ls = []
    for k, v in freq.items():
        if(v == val):
            ls.append(k)

    if (len(ls) == 1):
        print(ls[0])
    else:
        print(min(ls))
