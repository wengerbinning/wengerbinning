#!/bin/sh

#=============================================================================#
interal_get_param() {
    local index=0
    for param in "$@"; do
        if [ $(($index)) -eq $1 ]; then
            echo $param && break
	fi
        index=$(($index+1))
    done
}

#=============================================================================#
interal_print_list() {
    for each in "$@"; do
        test -n "$each" && echo -e "$each"
    done
}

#=============================================================================#
get_disks() {
    local disks=$(ls -x /tmp/mounts)
    echo $disks
}

#=============================================================================#
get_partitions() {
    if [ -n "$1" ]; then
        local disk="$1"
        local partistions=$(ls '/dev' | grep -r "^$disk" | grep -vr "^$disk$" | xargs)
    else
        local disks=$(get_disks)
        for disk in $disks; do
            local partistions="${partistions} $(ls '/dev' | grep -r "^$disk" | grep -vr "^$disk$" | xargs ) "
        done
    fi
    echo $partistions
}

#=============================================================================#
interal_get_partition_info() {
    local partition="$1"
    local result=$(blkid "$partition")
    local label=$(echo ${result} | sed -ne "s/^.*LABEL=\"\([^\"]*\).*/\1/p")
    local uuid=$(echo ${result} | sed -ne "s/.*UUID=\"\([^\"]*\).*/\1/p")
    local format=$(echo ${result} | sed -ne "s/.*TYPE=\"\([^\"]*\).*/\1/p")
    result=$(df -Th | grep ${partition})
    local total=$(interal_get_param 3 $result)
    local usable=$(interal_get_param 4 $result)
    local mount=$(interal_get_param 7 $result)
    test -z "$label" && label="partition"
    echo -e "$partition \t $mount \t \"$label\" \t $format \t $total \t $usable"
}

#=============================================================================#
get_partition_info() {
    if [ -n "$1" ]; then
        local partition=$1
            if [ -b "${partition}" ]; then
                interal_get_partition_info "${partition}"
            else
                interal_get_partition_info "/dev/$partition"
            fi
    else
        local partistions=$(get_partitions)
        for partition in $partistions; do
            interal_get_partition_info "/dev/$partition"
        done
    fi
}

#=============================================================================#
main() {
    local index=1
    while [ $index -le $# ]; do
    	local param=$(interal_get_param $index "$@")
        case "$param" in
        "get_disks")
	        get_disks
            break
        ;;
        "get_partitions")
            disk="$(interal_get_param $(($index+1)) "$@")"
            if [ -n "$disk" ]; then
                get_partitions "$disk"
            else
                get_partitions
            fi
            break
        ;;
	    "get_partition_info")
            partition="$(interal_get_param $(($index+1)) "$@")"
            if [ -n "$partition" ]; then
                get_partition_info "$partition"
            else
                get_partition_info 
            fi
            break
        ;;
        *)
        ;;
        esac
        index=$(($index+1))
    done 
}
###############################################################################

main "$@"
