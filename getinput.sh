#!/bin/bash

if [ $# -ne 3 ]; then
    echo "Usage: $0 <cookie_session> <url> <output_file>"
    exit 1
fi
cookie_session=$1
url=$2
output_file=$3
curl --cookie "session=$cookie_session" "$url" -o "$output_file"
