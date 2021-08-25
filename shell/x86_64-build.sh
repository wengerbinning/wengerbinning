#!/usr/bin/bash

start_time=$(date +%s)

test -z "${PROJECT_PATH}" && PROJECT_PATH="$(cd "../" && pwd)"
test -z "${PROJECT_NAME}" && PROJECT_NAME="$(basename $(pwd))"
test -z "${SCRIPT_PATH}" && SCRIPT_PATH="$(cd ${0%/*} && pwd)"
test -z "${SCRIPT_NAME}" && SCRIPT_NAME="${0##*/}"


TARGET_PREFIX="/usr"
TARGET_EXEC_PREFIX="/usr"
DESTDIR="./target_home"

cat << EOF
-------------------------------------------------------------------------------
$(echo -e "\033[33;3mProject Path:\033[0m ${PROJECT_PATH}")
$(echo -e "\033[33;3mProject Name:\033[0m ${PROJECT_NAME}")
$(echo -e "\033[33;3mScript:\033[0m ${SCRIPT_PATH}/${SCRIPT_NAME}") 
-------------------------------------------------------------------------------
EOF

./configure ${CONFIGURE_PARAM}                                                \
        --prefix="${TARGET_PREFIX}"                                           \
        --exec-prefix="${TARGET_EXEC_PREFIX}"                                 \
        --bindir="${TARGET_EXEC_PREFIX}/bin"                                  \
        --sbindir="${TARGET_EXEC_PREFIX}/sbin"                                \
        --includedir="${TARGET_PREFIX}/include"                               \
        --oldincludedir="${TARGET_EXEC_PREFIX}/include"                       \
        --libdir="${TARGET_EXEC_PREFIX}/lib"                                  \
        --libexecdir="${TARGET_EXEC_PREFIX}/libexec"                          \
        --sysconfdir="${TARGET_PREFIX}/etc"                                   \
        --sharedstatedir="${TARGET_PREFIX}/com"                               \
        --localstatedir="${TARGET_PREFIX}/var"                                \
        --datarootdir="${TARGET_PREFIX}/share"                                \

if [ $? -ne 0 ]; then echo -e "\033[31m\nConfigure is fail!\033[0m"; exit 1; fi

cat << EOF
-------------------------------------------------------------------------------
$(echo -e "\033[33;3mConfigure is successful! Start make build ...\033[0m")
-------------------------------------------------------------------------------
EOF

make ${MAKE_PARAM}

if [ $? -ne 0 ]; then echo -e "\033[31m\nMake is fail!\033[0m"; exit 2; fi

cat << EOF
-------------------------------------------------------------------------------
$(echo -e "\033[33;3mMake is successful! Start install files to target directory ...\033[0m")
-------------------------------------------------------------------------------
EOF

make install DESTDIR=${DESTDIR}

if [ $? -ne 0 ]; then echo -e "\033[31m\nInstall is fail!\033[0m"; exit 2; fi

cat << EOF
-------------------------------------------------------------------------------
$(echo -e "\033[33;3mInstall is successful! target is \'\033[032m${DESTDIR}\033[33;3m\'\033[0m")
-------------------------------------------------------------------------------
EOF
