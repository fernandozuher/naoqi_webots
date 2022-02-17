#!/bin/python3

if __name__ == "__main__":
    n = int(input().strip())

    arr = list(map(int, input().rstrip().split()))

    for item in reversed(arr):
        print(f"{item} ", end="")
