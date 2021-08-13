# Samba

samba是一个在UNIX与Linux系统上实现的SMB协议的项目。

信息服务块协议（SMB Protocol，Server Messages Block Protocol）是一种在LAN中共享文件和打印机的通信协议，是基于C/S架构模型，客户端通过该协议可以访问服务器上的共享资源。SMB实现了Linux的文件系统NFS与Windows的网络文件共享服务（CIFS，Common Internet File System）之间的资源共享。

## 环境搭建

## 使用示例

## 配置文件

在samba中只要在服务器上配置服务，通常为`/etc/samba/smb.conf`文件：

```config
# If you have any question you can click <https://www.samba.org/samba/docs/current/man-html/smb.conf.5.html>

# Samba服务的全局设置，对整个服务器有效。
###############################################################################
[global]
#=============================== BASIC SETTING ===============================#
    # 指定服务名称。
    netbios name = samba
    # 用于描述服务。
    server string = This is a samba server.
    # 设定服务群组。
    workgroup = WORKGROUP

    dos charset = UFT-8         # ASCII

    unix charset = UTF-8

    keeplive = 300

    deadtime=

    max connections = 10

#================================ ROLE SETTING ===============================#
    # 设置服务器的安全角色。
    security = auto
    # 设置服务器的角色。 在3.6.25中无效。
    server role = auto

    domain master = no
    
    local master = no

    preferred master = no
    
    os level = 33

    default service = home

    wins support = yes
    wins server = <ip>

#========================== USER & PASSWORD SETTING ==========================#
    # 指定用户验证的服务器。仅在security设定为ads与domain时有效。
    ; password server = *
    # 指定存储账户及密码的后台。
    passdb backend = smbpasswd
    # 用于设定samba服务的密码文件。
    smb passwd file = /etc/samba/smbpasswd
    # 设定密码开启加密，在4.11版本之后被弃用。
    ; encrypt passwords = yes
    # 设定账户可以使用空密码。在3.6.25中显示已弃用。
    ； null passwords = no


    # 用于设定来宾账户（即访问时无需验证账户信息）。默认为pcguest
    guest account = nobody
    # 在登录时未匹配到一个有效的系统用户时，映射的账户。
    map to guest = Bad User

    ; username map  = /user/local/samba/lib/users.map
    ; username map cache time = 60
    ; username map script

    ; debug class = no
    ; debug encryption = no
    ; debug hires timestamp = yes
    ; debug pid = no

    # 用于指定password的位数限制。
    ; password level = 8
    # 用于指定username的位数限制。
    ; username level =8
    # 用于控制是否加密密码。

#================================ LOG SETTING ================================#
    # 用于指定日志文件的存储路径。%m为客户端主机名。
    log file = /var/log/samba/%m.log
    logging = syslog: file
    # 设置日志等级
    log level = 3
    ； debuglevel
    max log size = 50
#============================ INTERFACES SETTING =============================#
    # 指定监听的网卡。
    interfaces
 
#========================== SCRIPT SETTING ===================================#

    ; add group script = /usr/sbin/groupadd %g
    ; delete group script
    ; add machine script = 
    ; delete share command = 
    ; add user script
    ; delete user script
    ; add user to group script
    ; passwd program
    ; rename user script
    ; delete share command
    ; aio max threads
    ; disable netbios

###############################################################################
[shares]

    #=============================== General =================================#
    # 资源描述。
    comment = user's home.
    # 资源路径。
    path = /data/pchome/%S
    
    #============================== Control ==================================#
    browseable = yes
    # 来宾访问。
    ; guest ok = no
    # 仅来宾连接有效，仅在guest ok设置的情况下有效。
    ; guest only = no 

    read only = yes
    # 设定该共享资源是否在* GWN系列产品终端固件升级：编辑。
    writable = yes
    # 用于指定访问用户。%s是samba服务搭建的用户。
    valid users = %s
    # 设定该共享资源是否生效。
    available = yes


    hide dot files
    hide files
    hide new files timeout
    hide special files
    hide unreadable
    hide unwriteable files
    public
    # 该项可以跳过所有的账户检查。
    guest only = yes
    # 管理共享资源的用户。
    admin users = root
    # 访问共享资源使用guest账户。
    guest ok
    
    writable

    valid user
    invlid users

    read list
    write list
    # 创建文件权限，与create mode同义。
    create mask = 0744
    # 创建文件权限，与create mode同义。
    directory mask = 0755
    # 连接超时时间，单位分钟。
    deadtime = 10
    force group
    force user
    force create mode
    force directory mode
    force direcrory security mode
    # 允许访问的用户，同 hosts allow，优先使用global中的参数。
    allow hosts = 
    deny hosts =
```

> Notes: samba服务的配置文件由global部分与共享资源部分组成，其中gloabl是全局参数设定。