#!/bin/sh

for f in `find . -type f -depth 1 -name '*.md' | grep -vE 'Chair|Template|index|Cook|Operator|Instructor|Committee|Mechanic|Driver|Nashie|Historian|Fossil|Permanent'`;
do
  ROOT_NAME=${f//.md}
  echo "$ROOT_NAME"
  # mkdir "$ROOT_NAME"
  # git mv "$ROOT_NAME.md" "$ROOT_NAME/index.md"
done