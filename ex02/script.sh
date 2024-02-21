#!/bin/bash

# Check if an input file was provided
if [ "$#" -ne 1 ]; then
    echo "Usage: $0 <filename>"
    exit 1
fi

# Input file
FILE="$1"

# Determine the operating system
OS="$(uname -s)"

# Use sed to replace the date-time string within brackets
# Adjust the sed command based on the operating system
case "$OS" in
    Linux*)     sed -i 's/\[[^]]*\]/[19920104_091532]/g' "$FILE" ;;
    Darwin*)    sed -i '' 's/\[[^]]*\]/[19920104_091532]/g' "$FILE" ;;
    *)          echo "Unsupported OS: $OS" >&2; exit 1 ;;
esac
