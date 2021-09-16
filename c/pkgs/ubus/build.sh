#!/bin/bash

. ../../../../public/build_funcs.sh

make CROSS_COMPILE=${CROSS_PREFIX}
if [ "$?" != "0" ]; then
    echo "Make Error"
    exit
fi

ccd 'libubus.h ubus_common.h ubusmsg.h' ${TOOLCHAIN_INCLUDE_DIR}/
ccd libubus.so ${IMAGE_BUILD}packages/files/ubus_core/${PRODUCT_TYPE}/${DEV}/lib/
ccd libubus.so ${STAGING_DIR}/usr/lib/
ccd ubusd ${IMAGE_BUILD}packages/files/ubus_core/${PRODUCT_TYPE}/${DEV}/sbin/
ccd ubus ${IMAGE_BUILD}packages/files/ubus_core/${PRODUCT_TYPE}/${DEV}/usr/bin/

#cp -av fake_root/usr/lib/libjson*so* ../../../image_build/packages/files/ubus_core/${CROSS}/usr/lib/
#cp -av fake_root/usr/include/json-c/ ${TOOLCHAIN_INCLUDE_DIR}

