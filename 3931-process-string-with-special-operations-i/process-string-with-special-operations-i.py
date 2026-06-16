class Solution:
    def processStr(self, s: str) -> str:
        st = ""

        for char in s:
            if 'a' <= char <= 'z':
                st += char
            elif char == '#':
                st += st
            elif char == '*':
                st = st[:-1]
            else:
                st = st[::-1]

        return st