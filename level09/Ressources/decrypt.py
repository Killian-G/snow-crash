import sys


def decrypt(string):
    new_string = ""
    for i in range(len(string) - 1):
        new_string += chr(ord(string[i]) - i)
    return new_string


def main():
    f = open(sys.argv[1], 'r')
    print(decrypt(f.readline()))
    f.close()
    return 0


if __name__ == '__main__':
    sys.exit(main())
