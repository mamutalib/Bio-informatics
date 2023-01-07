## Finding motif 
def subs(string1, string2):
    loc = []
    for i in range(len(string1)):
        if string2 == string1[i: i+len(string2)]:
            loc.append(i+1)
    return loc

if __name__ == "__main__":
    
    string1 = input()
    string2 = input()
    loc = subs(string1, string2)
    for i in loc:
        print(i, end=" ")