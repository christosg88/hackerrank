import re

Regex_Pattern = r'^\D[^aeiou][^bcDF]\S[^AEIOU][^.,]$'   # Do not delete 'r'.

print(str(bool(re.search(Regex_Pattern, raw_input()))).lower())
