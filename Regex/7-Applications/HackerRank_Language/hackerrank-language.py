import re

lang = re.compile(r'^\d+ (C|CPP|JAVA|PYTHON|PERL|PHP|RUBY|CSHARP|HASKELL|CLOJURE|BASH|SCALA|ERLANG|CLISP|LUA|BRAINFUCK|JAVASCRIPT|GO|D|OCAML|R|PASCAL|SBCL|DART|GROOVY|OBJECTIVEC)$')

N = int(input())

for i in range(N):
    S = input()
    if lang.match(S):
        print('VALID')
    else:
        print('INVALID')
