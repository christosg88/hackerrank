Regex_Pattern = r"\d\d\D\d\d\D\d\d\d\d" # Do not delete 'r'.

import re

print(str(bool(re.search(Regex_Pattern, raw_input()))).lower())
