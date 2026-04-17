# words
## Program
* [words.c](words.c): C program to break input into a series of words
## Testing
* [testing.sh](testing.sh): bash script to execute a sequence of commands using the words program
* [testing.out](testing.out): output from testing script
* [test.txt](test.txt): file containing test cases including different combinations of non-letter and letter characters
* [empty.txt](empty.txt): file containing only non-letter characters

Note: tested multiple special filename `-` outside of bash script:
```bash
$ ./words - "test.txt" - "empty.txt"
[this is the first (1st) use of stdin
this
is
the
first
st
use
of
stdin
Test
file
Tests
multiple
non
letters
in
a
row
Tests
numbers
between
words
like
t
h
i
s
Tests
multiple
blank
lines
between
words
Tests
symbols
near
text
[this is the second (2nd) use of stdin
this
is
the
second
nd
use
of
stdin
```
`[` indicates stdin text (ended by <ENTER> then <CTRL> d).
