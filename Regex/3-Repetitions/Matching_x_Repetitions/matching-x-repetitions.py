import re

Regex_Pattern = r'^[a-zA-Z02468]{40}[\s13579]{5}$'   # Do not delete 'r'.

print(str(bool(re.search(Regex_Pattern, raw_input()))).lower())
