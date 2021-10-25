import random

def ch():
    l = [i for i in range(32, 127)]
    r = []
    for i in range(3):
        r.append(random.choice(l))
        l.remove(r[-1])
    return r
def gen():
    size = random.randint(1, 10)
    
    return str(size) + ''.join(map(lambda x: chr(x), ch()))

if __name__ == '__main__':
    print(gen(), end='')