from sys import stdin

input()
for line in stdin:

    if line == "":
        break

    word1, word2 = "", ""
    flag = True

    for ch in line.rstrip():
        if flag:
            word1 = "".join((word1, ch))
        else:
            word2 = "".join((word2, ch))
        flag = not flag

    print(f"{word1} {word2}")
