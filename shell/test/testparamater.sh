#!/bin/bash

echo "默认第一位置的参数：$1， 共有$#个参数"
shift 2
echo "使用shift将参数列表向左移动两位后第一位置参数：$1，共有$#个参数"
shift
echo "shift默认将参数列表向左移动一位：$1， 共有$#个参数"
echo "shift移动参数是不可逆的"
