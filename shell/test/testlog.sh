#!/bin/bash

#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#
SCRIPT_PATH=${0}
SCRIPT_NAME=${0##*/}
SCRIPT_HOME=$(cd ${0%/*} && pwd)

test -z "$__MAIN__" && export __MAIN__="${SCRIPT_PATH}"
#$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$#
DEFAULT_LOG_FILE="$(pwd)/action.log"

#=============================================================================#
params() {
    local index=0
    for param in "$@"; do
        if [ $index -eq $1 ]; then
            echo "$param" && break
        fi
        index=$(($index+1))
    done
    exit $index
}
#-----------------------------------------------------------------------------#
msger_help() {
cat << EOF
msger - This is a log tool without time imformation.

usage: msger <option>...
    -m, --message: recording the message.
    -f, --file: log file.
    -h, --help: print help information.
EOF
}
#=============================================================================#
msger() {
    local index=0
    local skip=0
    for param in "$@"; do
        index=$(($index+1))
        #echo "@ $index $param"
        if [ $skip -ne 0 ]; then
            skip=$(($skip-1)) && continue
        fi
        #echo "$index $param"
        case "$param" in
            "-m"|"--message")
                local message=$(params $(($index+1)) "$@") && skip=1       
            ;;
            "-f"|"--file")
                local file=$(params $(($index+1)) "$@") && skip=1
            ;;
            "-h"|"--help")
                msger_help && exit
            ;;
            *)
                echo "Unknow $param paramater." && msger_help
            ;;
        esac 
    done
    if [ -n "$message" -a -n "$file" ]; then
        echo "$message" >> "$file"
    else
        while read line; do
            if [ "$line" = "@cmd:quit" ]; then
                break
            else
                echo "$line" >> "$file"
            fi
        done
    fi
}


#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#
cat << EOF
-------------------------------------------------------------------------------
This is a loger test script, here has some informations about this script.
script name: ${SCRIPT_NAME}
script home: ${SCRIPT_HOME}
script path: ${SCRIPT_PATH}

Others information:
local workspace: $(pwd)
caller: ${__MAIN__}
-------------------------------------------------------------------------------
EOF

###############################################################################
msger "$@"


