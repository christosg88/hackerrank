import re

Regex_Pattern = r'^[a-zA-Z]*e?s$'   # Do not delete 'r'.

print(str(bool(re.search(Regex_Pattern, raw_input()))).lower())
