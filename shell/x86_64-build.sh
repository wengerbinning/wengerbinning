#!/usr/bin/bash

test -z "${PROJECT_HOME}" && PROJECT_HOME="$(cd "../../../../" && pwd)"
test -z "${PROJECT_PATH}" && PROJECT_PATH="$(cd "../" && pwd)"
test -z "${PROJECT_NAME}" && PROJECT_NAME="$(basename $(pwd))"

test -z "${SCRIPT_PATH}" && SCRIPT_PATH="$(cd ${0%/*} && pwd)"
test -z "${SCRIPT_NAME}" && SCRIPT_NAME="${0##*/}"

CFLAGS="${CFLAGS}"
CPPFLAGS="${CPPFLAGS}"
LDFLAGS="${LDFLAGS}"
LIBS="${LIBS}"

# CONFIGURE_PARAM=""
# MAKE_PARAM="V=1"

TARGET_PREFIX="${PROJECT_HOME}/wenger/${PROJECT_NAME}"
TARGET_EXEC_PREFIX="${PROJECT_HOME}/wenger/${PROJECT_NAME}/usr"

cat << EOF
-------------------------------------------------------------------------------
$(echo -e "\033[33;3mProject Home:\033[0m ${PROJECT_HOME}")
$(echo -e "\033[33;3mProject Path:\033[0m ${PROJECT_PATH}")
$(echo -e "\033[33;3mProject Name:\033[0m ${PROJECT_NAME}")
$(echo -e "\033[33;3mScript:\033[0m ${SCRIPT_PATH}/${SCRIPT_NAME}") 
$(echo -e "\033[33;3mMechine:\033[0m ./configure")
-------------------------------------------------------------------------------
EOF

./configure ${CONFIGURE_PARAM}                                                \
        CFLAGS="${CFLAGS}"                                                    \
        CPPFLAGS="${CPPFLAGS}"                                                \
        LDFLAGS="${LDFLAGS}"                                                  \
        LIBS="${LIBS}"                                                        \
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

# make install

# if [ $? -ne 0 ]; then echo -e "\033[31m\nInstall is fail!\033[0m"; exit 2; fi

# cat << EOF
# -------------------------------------------------------------------------------
# $(echo -e "\033[33;3mInstall is successful!\033[0m")
# -------------------------------------------------------------------------------
# EOF