# 账户

GNU/Linux系统是一个多用户的系统，按照用户与群组的方式来管理用户。在Linux中每一个账户拥有用户名、用户口令、用户ID、群组ID、用户备注信息、用户的主目录以及用户默认的shell等属性。这些信息都按照下列顺序以`:`为分隔符存储在`/etc/passwd`文件中。passwd文件的权限是644.账户有系统账户与普通账户之分。

```
<user name>:<>
```
* user name：是UID的别名。
* user password：是鉴别身份的依据，为提高安全性，将加密后的口令存储在`/etc/shadow`下，在该字段使用特殊字符替换。
* uid：是用户的唯一识别码，每个用户都有不同且唯一的uid，如果用户uid相同，则本质为同一用户，但是相同uid的多个用户可以有不同口令。管理员的UID为0,系统用户的UID为1~999,普通用户的UID从1000开始;
* gid：是用户组唯一识别码，系统用户组GID为0。
* user comment：用户的描述信息，没有强制格式，但是一般以`,`来分割，依次为用户全名、邮箱、电话等。
* home path：是存储用户文件的目录，一般在`/home/`下。
* login shell：是用户默认的登录shell。

在用户口令使用shadow之后，shadow每条记录具以下有格式，shadow的权限是640.

* User name：用户名。
* Encipherment password：使用sha512加密的口令。违用户的密码是`!!`或者`*`,新建的无密码的用户使用`!!`.
* Last modified time：是计算1970年01月01日到修改时间的天数。
* Minmum modification interval：是允许两次修改密码的最小间隔天数，在该时间内不允许修改密码。
* Validify of password：在该天数后强制要求用户变更密码。是距1970年1月1日之后的天数。
* The warning date before the password expires：密码过期前的警告天数。
* The grace period after the password has expired：密码过期后的宽限天数。
* Account expiration date：用户失效时间。是距1970年1月1日之后的天数。
* retain ： 保留字段。

用户组具有组名、gid、组成员、组密码、附加用户。`/etc/group`文件记录具有以下格式：group具有644的权限。

* group name： 用户组名。
* group password： 用户组密码，正真的密码也存放在shadow文件中。
* gid：是用户组的唯一识别码。make
* Additional user： 附加用户，记录改组内所有的附加用户。

在现今的Linux中采用sudo来让普通用户暂时拥有管理员权限。

* 【配置文件】sudo授权:`/etc/sudoers`;

### 用户管理

* 【功能】创建用户:使用`useradd`工具可以创建新的用户，根据不同参数可以创建特定的用户。

  ```shell
  # 显示useradd的默认参数。
  useradd -D
  # 创建默认参数的用户。
  useradd <user name>
  # 创建指定家目录所属路径的用户。
  useradd -b <home path> <user name>
  # 创建指定注释信息的用户。
  useradd -c <comment> <user name>
  # 创建指定家目录的用户。
  useradd -d <home path> <user name>

  useradd -p <password> <user name>    # 创建指定密码的用户
  useradd -r <username>               # 创建系统用户
  useradd -u <UID>  <username>        # 创建指定UID的用户
  useradd -g <group name> <user name>   # 创建指定用户组的用户
  ```

* 【功能】查看用户:使用`id、who`等命令以及用户配置文件可以查看当前用户以及所有用的信息。
makeer name>   # 查看指定用户信息
  id <user name>                       # 查看指定用户信息
  whoami                              # 查看当前登录用户信息
  compgen -u                          # 查看所有用户
  hostname                            # 显示主机名
  uname                               # 显示系统信息
  top                                 # 动态显示进程信息
  ps -aux                             # 显示当前时刻的进程信息
  su <username>                       # 切换用户
  sudo                                # 以管理员权限执行命令,配置文件在/etc/sudoers
  ```

* 【功能】修改用户：使用`usermod`可以修改用户的信息。在修改一些参数时，需要确认该用户无活动。

  ```shell
  # 修改指定用户的密码。
  passwd <user>
  # 修改用户的UID。
  usermod -u <UID>  <user>
  ```

* 【功能】删除用户:使用`userdel`可以删除用户。

  ```shell
  userdel <username>                  # 默认选项删除用户
  userdel -r <username>               # 删除用户以及家目录与 mail spool
  ```

* 【功能】用户通信:使用`write`可以在不同活动用户之间进行通信。

  ```shell
  echo "Hello" | write <username>     # 用另一个用户通信
  ```

### 群组管理

* 【功能】创建群组:创建群组。

  ```shell
  # 创建默认参数的用户组。
  groupadd <group>
  # 创建指定GID的用户组。


  ```shell
  groupmod -g <GID> <groupname>              # 修改用户组的GID
  gpasswd                                     # 管理用户组
  ```

* 【功能】查看群组：查询群组信息。

  ```shell
  cat /etc/group                    # 查看所有用户组信息
  cat /etc/group | grep <groupname> # 查看指定用户组信息
  groups                            # 查看当前用户所在组的信息
  compgen -g                        # 查看用户组信息
  ```

* 【功能】切换群组：切换当前用户的群组。

  ```shell
  newgrp <userGroupName>            # 切换用户组
  ```

* 【功能】删除群组:删除群组。

  ```shell
  groupdel <groupname>              # 删除用户组
  ```

* 【功能】修改群组：修改群组信息。

  ```shell
  gpasswd
  groupmod
  ```
