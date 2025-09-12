#/bin/bash
# You thought I was gonna spend forever entering paths into the stdin?
# Think again, I'm a student. Ain't nobody got that kind of time.

make

bin/p3 <<EOF
input.txt
output.txt
EOF

if diff --brief qroots.output.test output.txt | grep -q 'differ'; then
  echo "FAILED - Printing diff"
  diff qroots.output.test output.txt
  echo "FAILED"
fi
