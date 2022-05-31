#!/bin/sh

for f in `find . -type f -depth 1 -name '*.md'`;
do
  ROOT_NAME=${f//.md}
  echo "mkdir $ROOT_NAME"
  echo "git mv $ROOT_NAME.md $ROOT_NAME/index.md"
done