#!/bin/bash

read VAL

echo -e "HTTP/1.1 200 OK\r"
echo -e "Content-Type: text/html; charset=utf-8\r"
echo -e "Content-Length: $(wc <<< $VAL | awk '{print $3}')\r"
echo -e "\r"
echo  $VAL
