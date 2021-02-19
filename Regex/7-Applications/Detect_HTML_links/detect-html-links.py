import re

link = re.compile(r'<a href="[^"]+"')
text_name = re.compile(r'>[^<]+<')

N = int(input())

for i in range(N):
    S = input()

    # find the URL
    l = link.finditer(S)

    if l:
        for match in l:
            link_start, link_end = match.span()
            link_start += 9
            link_end -= 1

            # find the text name
            t = text_name.search(S[link_end:])

            if t:
                text_name_start, text_name_end = t.span()
                text_name_start += link_end + 1
                text_name_end += link_end - 1

                print(S[link_start:link_end].strip() + ',' + S[text_name_start:text_name_end].strip())
            else:
                print(S[link_start:link_end].strip() + ',')
