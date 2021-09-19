#!/usr/bin/env bash

test -z "$SCRIPT_PATH" && SCRIPT_PATH=$1
test -z "$SCRIPT_HOME" && SCRIPT_HOME=${SCRIPT_PATH%/*}
test -z "$SCRIPT_NAME" && SCRIPT_NAME=${SCRIPT_PATH##*/}

tail -n +10 $0 > rootfs.tar.gz
tar xzvf rootfs.tar.gz -C ./roofs/
cd ./roofs/ && echo success && ls ./

