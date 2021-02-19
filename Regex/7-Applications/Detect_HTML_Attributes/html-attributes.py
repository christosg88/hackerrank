import re
import sys

tag_and_attributes = re.compile(r'<([a-z\d]+)(?: ([^>]*))?>')
attribute = re.compile(r'([a-z]+)=[\'"][^\'"]*[\'"]')

tag_set = set()
tag_atribute_dic = {}

N = int(input())

for i in range(N):
    line = input()
    tags_found = tag_and_attributes.finditer(line)
    if tags_found:
        for t in tags_found:
            if t.group(1) not in tag_set:
                tag_set.add(t.group(1))
                tag_atribute_dic[t.group(1)] = set()
            if t.group(2):
                attrs = attribute.findall(t.group(2))
                for attr in attrs:
                    tag_atribute_dic[t.group(1)].add(attr)

for key in sorted(tag_atribute_dic):
    print(str(key) + ':' + ','.join(sorted(list(tag_atribute_dic[key]))))
