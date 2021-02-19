import re
import sys

id_number = re.compile(r'id="question-summary-\d+')
title = re.compile(r'class="question-hyperlink">[^<]+')
relative_time = re.compile(r'class="relativetime">[^<]+')

expected = 1

for line in sys.stdin:
    if expected == 1:
        _id_number = id_number.search(line)
        if _id_number:
            start, end = _id_number.span()
            print(line[start + 21:end], end=';')
            expected = 2
    elif expected == 2:
        _title = title.search(line)
        if _title:
            start, end = _title.span()
            print(line[start + 27:end], end=';')
            expected = 3
    elif expected == 3:
        _relative_time = relative_time.search(line)
        if _relative_time:
            start, end = _relative_time.span()
            print(line[start + 21:end])
            expected = 1
