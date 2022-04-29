import sys

def decrypt(string):
    newString = ""
    for i in range(len(string) - 1):
        newString += chr(ord(string[i]) - i)
    return newString

def main():
    f = open(sys.argv[1], 'r')
    print(decrypt(f.readline()))
    f.close()
    return 0

if __name__ == '__main__':
    sys.exit(main())