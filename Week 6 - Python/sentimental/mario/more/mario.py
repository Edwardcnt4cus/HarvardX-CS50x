def main():
    height = get_height()
    for i in range(1, height + 1):
        print(" " * (height - i), end="")
        print("#" * i, end="")
        print("  ", end="")
        print("#" * i)

def get_height():
    while True:
        try:
            height = int(input("Height: "))
            if 1 <= height <= 8:
                return height
        except ValueError:
            pass

main()

