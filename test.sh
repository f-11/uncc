#!/bin/sh

check () {
  input="$1"
  expected="$2"

  echo "$input => $expected"
  echo "$input" | ./uncc -

}

check "1+2;" 3
check "31 - 2;" 29
echo "OK"
