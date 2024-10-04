from time import sleep

import sys
from tqdm import tqdm
def f(range: range):
    nn = -1
    for i in range:
        total = range.stop - range.start - 1
        n = int(66 * (i + 1)/total)
        if n != nn:
            s = '{:>3}'.format(int(100 * (i + 1)/total))
            s += "%|"
            s += "█"*n
            s +=  " " * (66 - n)
            s += "|"
            s += '{:>4}'.format(int(i + 1))
            s += '/{:>4}'.format(int(total + 1))
            print(s, end="\r\033[?25l")
            n = nn

        yield
    print()
    return


print(len("██████████████████████████████████████████████████████████████████"))

for i in f(range(1000)):
    sleep(0.01)

for elem in tqdm(range(1000)):
    sleep(0.01)