def move(a, b):
    print "Move {} to {}".format(a, b)

def hanoi(n, a, b, c):
    if n == 1:
        move(a, c)
    else:
        hanoi(n - 1, a, c, b)
        move(a, c)
        hanoi(n - 1, b, a, c) 
def main():
    n = 4
    hanoi(n, "a", "b", "c")

if __name__ == '__main__':
    main()
