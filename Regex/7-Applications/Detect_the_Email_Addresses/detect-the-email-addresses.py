import re

mail_address = re.compile(r'(?:^|\s)([a-zA-Z_0-9.]+@[a-z]+[.][a-z.]+[a-z])')

set_of_emails = set()

N = int(raw_input())

for i in xrange(N):
    line = raw_input()
    matches = mail_address.finditer(line)
    for m in matches:
        set_of_emails.add(m.group(1))

print ';'.join(sorted(list(set_of_emails)))
