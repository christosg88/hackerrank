import re
import sys

Regex_Pattern = r"...\....\....\...."    # Do not delete 'r'.

Test_String = sys.stdin.read()

match = re.findall(Regex_Pattern, Test_String)

print "Number of matches :", len(match)
