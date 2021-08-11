#!/bin/ash

manual="<<MANUAL

MANUAL"

#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@#
SCRIPT=$0
SCRIPT_NAME=${0##*/}
SCRIPT_PATH=${0%/*}

if [ -z "$__MAIN__" ]; then
    __MIAN__=$SCRIPT_NAME
fi 

#$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$#
default_samba_file="/etc/config/samba"
default_template_file="/etc/samba/smb.conf.template"
default_passwd_file="/etc/passwd"
default_smb_conf_file="/etc/samba/smb.conf"
default_smbpasswd_file="/etc/samba/smbpasswd"

samba_file=$default_samba_file
template_file=$default_template_file
passwd_file=$default_passwd_file
smb_conf_file=$default_smb_conf_file
smbpasswd_file=$default_smbpasswd_file

SAMBA_GID=65534
SAMBA_UID=65534

uid=65535
gid=$SAMBA_GID
shell="/bin/false"

# usage: get_param <index> "$@"
#=============================================================================#
get_param() {
    local index=0
    for param in "$@"; do
        if [ $(($index)) -eq $1 ]; then
            echo $param && break
	fi
        index=$(($index+1))
    done
}

# usage: get_smb_conf <smb.conf file> <section> <key>
#=============================================================================#
get_smb_conf() {
    local smb_file="$1"
    local section="$2"
    local key="$3"
    result=$(sed -n "/$key/p" $smb_file)
    echo ${result#*=}
}

# usage: set_smb_conf <smb.conf file> <section> <key>
#=============================================================================#
set_smb_conf() {
    local file="$1"
    local section="$2"
    local name="$3"
    local value="$4"
	echo "set $file $section $name is $value."
    sed -iback "s/$name.*/$name = $value/" $file
}

# usage: format_name <name>
#=============================================================================#
format_name() {
    local name=$1
    name="$(echo $name | sed -n "s/_/ /p")"
    if [ -z "$name" ]; then
    	name=$1
    fi
    echo $name
}
# format_name "guest_ok"

# usage: format_value <value> 
#=============================================================================#
format_value() {
    local value="${1#\'}"
    value="${value%\'}"
    if [ $value = 1 ]; then
	echo "yes"
    elif [ $value = 0 ]; then
  	echo "no"
    else
    	echo "$value"
    fi
}
# format_name "'1'"

# usage A: smbconf set <section> <name> <value>
# usage B: smbconf get <section> <name>
#=============================================================================#
smbconf() {
   	local file=$smb_conf_file
    local index=1
    while [ $index -le $# ]; do
    	local param=$(get_param $index "$@")
        case "$param" in
        "set")
	        local section="$(get_param $(($index+1)) "$@")"
	        local key="$(get_param $(($index+2)) "$@")"
	        local value="$(get_param $(($index+3)) "$@")"
   	        echo "set $file -> $section -> $key: $value"
	        set_smb_conf "$file" "$section" "$key" "$value"
	        index=$(($index+3))
        ;;
        "get")
	        local section="$(get_param $(($index+1)) "$@")"
	        local key="$(get_param $(($index+2)) "$@")"
	        # echo "get $file -> $section -> $key"
	        get_smb_conf "$file" "$section" "$key"
	        index=$(($index+2))
        ;;
	    "-f")
	        index=$(($index+1))
		;;
        *)
        ;;
        esac
        index=$(($index+1))
    done
}

# usage: smbuser <user name> <user password>
#=============================================================================#
smbuser() {
    local user=$1
    local password=$2
    if [ $user = "nobody" ]; then
        set_smb_conf "$smb_conf_file" "$section" "valid users" "$user"
    fi
    result=$(cat $passwd_file | sed -n "/.*:[*x]:$uid:.*/p")
    # echo $result
    if [ -n "$result" ]; then
        echo "old: $result"
        sed -iback "s/.*:[x*]:$uid/$user:*:$uid/" $passwd_file
    else
        echo "$user:*:$uid:$gid:usb share:/var/$user:$shell" >> $passwd_file
    fi
    result=$(cat $passwd_file | sed -n "/$user:[x*]:$uid:.*/p")
    if [ -n "$result" ]; then
        echo "new: $result"
    fi
    
    if [ -n "$smbpasswd_file" ]; then
        rm -f "$smbpasswd_file"
    fi
    
    touch $smbpasswd_file

    echo -e "$password\n$password" | smbpasswd -a -s $user
    set_smb_conf "$smb_conf_file" "$section" "valid users" "$user"
}

# usage: parse_samba <samba file> <command>
#=============================================================================#
parse_samba() {
    local file=$1
    local nobody=0
    while read type name value; do
		if [ -z "$type" ]; then
	    	continue
		elif [ "$type" = "config" ]; then
	    	section="[$(format_value $value)]"
		elif [ "$type" = "option" ]; then
            # echo $section $name $value
	    	if [ -z "$section" ]; then
		    	section="[global]"
        	fi
	    	name=$(format_name $name)
			value=$(format_value $value)
			case $name in
			"user")
				smb_user=$value
			;;
			"password")
				smb_password=$value
			;;
            "security")
                if [ $value = "share" ]; then
                    nobody=1
                fi
                smbconf set "$section" "$name" "$value"
            ;;
			*)
                # echo $section $name $value
		        smbconf set "$section" "$name" "$value"
			;;
		esac
	else
	    echo "$type, $name = $value"
	fi
    done < $file
    if [ $nobody -eq 1 ]; then
        smb_user="nobody"
        smb_password="nobody"
    fi
}

# parse_samba "$samba_file" "echo"

#=============================================================================#
update_smb_conf() {
    parse_samba "$samba_file"
    if [ -n "$smb_user" -a -n "$smb_user" ]; then
	    smbuser ${smb_user} ${smb_password}
	fi
}

#=============================================================================#
main() {
    update_smb_conf
}

###############################################################################

if [ $__MAIN__=$SCRIPT_NAME ]; then
    main "$@"
fi
