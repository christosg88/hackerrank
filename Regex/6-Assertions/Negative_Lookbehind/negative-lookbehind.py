import re

Regex_Pattern = r"(?<![aeiuoAEIUO])."    # Do not delete 'r'.

Test_String = input()

match = re.findall(Regex_Pattern, Test_String)

print("Number of matches :", len(match))
