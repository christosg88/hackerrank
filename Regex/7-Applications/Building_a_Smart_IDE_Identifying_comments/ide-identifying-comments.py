import re
import sys

single_line_comment = re.compile(r'//.+$')
multi_line_comment_start = re.compile(r'/\*')
multi_line_comment_end = re.compile(r'\*/')

multi_line = False

for line in sys.stdin:
    if multi_line:
        print(line.strip())
        comment = multi_line_comment_end.search(line)
        if comment:
            multi_line = False

    comment = multi_line_comment_start.search(line)
    if comment:
        print(line.strip())
        multi_line = True
        comment = multi_line_comment_end.search(line)
        if comment:
            multi_line = False

    comment = single_line_comment.search(line)
    if comment:
        print(comment.group())
