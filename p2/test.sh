#/bin/bash
# You thought I was gonna spend forever entering paths into the stdin?
# Think again, I'm a student. Ain't nobody got that kind of time.

make

bin/p2 <<EOF
input.txt
test.txt
EOF

if diff --brief output.txt test.txt | grep -q 'differ'; then
  echo "FAILED - Printing diff"
  diff output.txt test.txt
  echo "FAILED"
fi
