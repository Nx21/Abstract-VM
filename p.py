import hashlib
m = hashlib.sha256()
m.update(input().encode('ascii'))
m.digest()
print(m.hexdigest()[4:20] + "N@")