import re
import sys

C = re.compile(r'#include')
Java = re.compile(r'import .+;$')

lang = 'Python'

for line in sys.stdin:
    language = C.search(line)
    if language:
        lang = 'C'
        break
    language = Java.search(line)
    if language:
        lang = 'Java'
        break

print(lang)
