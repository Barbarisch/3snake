import base64

with open('test.txt', 'r') as f:
	lines = f.readlines()
	f.close()
	
for line in lines:
	decoded = base64.b64decode(line.strip())
	xored = bytes([b ^ ord(b'a') for b in decoded])
	print(xored.strip().decode("utf-8"))