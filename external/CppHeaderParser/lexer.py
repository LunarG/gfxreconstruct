from collections import deque
import ply.lex as lex
import re

_line_re = re.compile(r'^#line (\d+) "(.*)"')


class Lexer(object):

    tokens = [
        "NUMBER",
        "FLOAT_NUMBER",
        "NAME",
        "COMMENT_SINGLELINE",
        "COMMENT_MULTILINE",
        "PRECOMP_MACRO",
        "PRECOMP_MACRO_CONT",
        "DIVIDE",
        "CHAR_LITERAL",
        "STRING_LITERAL",
        "NEWLINE",
        "ELLIPSIS",
        "DBL_LBRACKET",
        "DBL_RBRACKET",
        "DBL_COLON",
        "SHIFT_LEFT",
    ]

    literals = [
        "<",
        ">",
        "(",
        ")",
        "{",
        "}",
        "[",
        "]",
        ";",
        ":",
        ",",
        "\\",
        "|",
        "%",
        "^",
        "!",
        "*",
        "-",
        "+",
        "&",
        "=",
        "'",
        ".",
    ]

    t_ignore = " \t\r?@\f"
    t_NUMBER = r"[0-9][0-9XxA-Fa-f]*"
    t_FLOAT_NUMBER = r"[-+]?[0-9]*\.[0-9]+([eE][-+]?[0-9]+)?"
    t_NAME = r"[A-Za-z_~][A-Za-z0-9_]*"

    def t_PRECOMP_MACRO(self, t):
        r"\#.*"
        m = _line_re.match(t.value)
        if m:
            filename = m.group(2)
            if filename not in self._filenames_set:
                self.filenames.append(filename)
                self._filenames_set.add(filename)
            self.filename = filename

            self.line_offset = 1 + self.lex.lineno - int(m.group(1))

        else:
            return t

    t_PRECOMP_MACRO_CONT = r".*\\\n"

    def t_COMMENT_SINGLELINE(self, t):
        r"\/\/.*\n?"
        if t.value.startswith("///") or t.value.startswith("//!"):
            self.comments.append(t.value.lstrip("\t ").rstrip("\n"))
        t.lexer.lineno += t.value.count("\n")
        return t

    t_DIVIDE = r"/(?!/)"
    t_CHAR_LITERAL = "'.'"
    t_ELLIPSIS = r"\.\.\."
    t_DBL_LBRACKET = r"\[\["
    t_DBL_RBRACKET = r"\]\]"
    t_DBL_COLON = r"::"
    t_SHIFT_LEFT = r"<<"
    # SHIFT_RIGHT introduces ambiguity

    # found at http://wordaligned.org/articles/string-literals-and-regular-expressions
    # TODO: This does not work with the string "bla \" bla"
    t_STRING_LITERAL = r'"([^"\\]|\\.)*"'

    # Found at http://ostermiller.org/findcomment.html
    def t_COMMENT_MULTILINE(self, t):
        r"/\*([^*]|[\r\n]|(\*+([^*/]|[\r\n])))*\*+/\n?"
        if t.value.startswith("/**") or t.value.startswith("/*!"):
            # not sure why, but get double new lines
            v = t.value.replace("\n\n", "\n")
            # strip prefixing whitespace
            v = re.sub("\n[\\s]+\\*", "\n*", v)
            self.comments = v.splitlines()
        t.lexer.lineno += t.value.count("\n")
        return t

    def t_NEWLINE(self, t):
        r"\n+"
        t.lexer.lineno += len(t.value)
        del self.comments[:]
        return t

    def t_error(self, v):
        print("Lex error: ", v)

    def __init__(self, filename):
        self.lex = lex.lex(module=self)
        self.input = self.lex.input

        # For tracking current file/line position
        self.filename = filename
        self.line_offset = 0

        self.filenames = []
        self._filenames_set = set()

        if self.filename:
            self.filenames.append(filename)
            self._filenames_set.add(filename)

        # Doxygen comments
        self.comments = []

        self.lookahead = deque()

    def current_location(self):
        if self.lookahead:
            return self.lookahead[0].location
        return self.filename, self.lex.lineno - self.line_offset

    def get_doxygen(self):
        """
        This should be called after the first element of something has
        been consumed.

        It will lookahead for comments that come after the item, if prior
        comments don't exist.
        """

        # Assumption: This function is either called at the beginning of a
        # statement or at the end of a statement

        if self.comments:
            comments = self.comments
        else:
            comments = []
            # only look for comments until a newline (including lookahead)
            for tok in self.lookahead:
                if tok.type == "NEWLINE":
                    return ""

            while True:
                tok = self.lex.token()
                comments.extend(self.comments)

                if tok is None:
                    break

                tok.location = (self.filename, tok.lineno - self.line_offset)
                ttype = tok.type
                if ttype == "NEWLINE":
                    self.lookahead.append(tok)
                    break

                if ttype not in self._discard_types:
                    self.lookahead.append(tok)

                if ttype == "NAME":
                    break

                del self.comments[:]

        comments = "\n".join(comments)
        del self.comments[:]
        return comments

    _discard_types = {"NEWLINE", "COMMENT_SINGLELINE", "COMMENT_MULTILINE"}

    def token(self, eof_ok=False):
        tok = None
        while self.lookahead:
            tok = self.lookahead.popleft()
            if tok.type not in self._discard_types:
                return tok

        while True:
            tok = self.lex.token()
            if tok is None:
                if not eof_ok:
                    raise EOFError("unexpected end of file")
                break

            if tok.type not in self._discard_types:
                tok.location = (self.filename, tok.lineno - self.line_offset)
                break

        return tok

    def token_if(self, *types):
        tok = self.token(eof_ok=True)
        if tok is None:
            return None
        if tok.type not in types:
            # put it back on the left in case it was retrieved
            # from the lookahead buffer
            self.lookahead.appendleft(tok)
            return None
        return tok

    def return_token(self, tok):
        self.lookahead.appendleft(tok)

    def return_tokens(self, toks):
        self.lookahead.extendleft(reversed(toks))


if __name__ == "__main__":
    try:
        lex.runmain(lexer=Lexer(None))
    except EOFError:
        pass
