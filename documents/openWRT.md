openWRT是一个适用于嵌入式设备的Linux操作系统。用来代替静态、整体的固件；openWRT在管理包中提供一个高度可写的文件系统。

每个守护进程在特定的命名空间下注册一组路径。每个路径都可以提供具有任意数量参数的多个过程。

## ubus（openWRT微总线体系结构）

ubus是实现守护进程与应用程序之间进程通信的通用框架。使进程间通信变得非常简单。它是由daemon，library，extra helpers组成，该项目的核心是ubus守护进程，它为其他守护进程提供一个接口来注册他们自己来发送消息，是基于unix socket实现的，使用TLV（type-length-Value）消息。该项目提供一个libubus来简化开发人员使用ubus。每一个守护进程在特定的命名空间下注册一组路经，每一个路经为多任务提供任意数量的参数。多任务也可以回复消息。

## UCI

UCI（Unified Configuration Interface，统一配置接口）为openWRT提供一个集中控制配置参数的管理接口。继承于NVRAM-based配置方法。所有配置信息在uci配置文件中。有许多软件支持uci模式管理。

有以下命令：

```shell
# 面向LAN口提供的IP地之一服务配置。
/etc/config/dhcp
# SSH服务配置
/etc/config/dropbear
# 路由转发、端口转发、防火墙规则。
/etc/config/firewall
# 自身网络接口配置。
/etc/config/network
# 时间服务时区配置。
/etc/config/system
# 无线网络配置。
/etc/config/wireless

### uci配置工具

所有未执行生效的修改都只存储在缓存中。

* 【功能】获取配置内容。

  ```shell
  # 获取节点类型。
  uci get <config>.<section>
  # 获取选项的值。
  uci get <config>.<section>.<option>
  # 显示尚未生效的配置。
  uci changes <config>
  # 显示所有配置项。使用-X参数可以显示匿名节点。
  uci show
  # 显示指定配置。
  uci show <config>
  # 显示指定配置的节点。
  uci show <config>.<section>
  # 显示指定配置指定节点的选项。
  uci show <config>.<section>.<option>
  ```

* 【功能】添加配置选项。

   ```shell
   # 添加一个隐藏节点。
   uci add <config> <section type>
   # 增加一个节点。或者修改已存在节点。
   uci set <config>.<section>=<section type>
   # 增加一个选项。或修改选项值。
   uci set <config>.<section>.<option>=<value>
   # 增加一个选项到列表中。
   uci add_list <config>.<section>.<option>=<value>
   ```

* 【功能】删除配置信息。

  ```shell
  # 删除指定节点。
  uci delete <config>.<section>
  # 删除指定选项。
  uci delete <config>.<section>.<option>
  # 删除指定列表。
  uci delete <config>.<section>.<list>
  # 删除指定列表中的值。
  uci del_list <config>.<section>.<option>=<string>
  ```
   
* 【功能】生效修改。

  ```shell
  uci commit <config name>
  '```

## UCI配置文件

```uci
# config 节点
config <section type> <section label>
    # option 选项
    option <key>       <value>
    # list 列表
    list    <list key> <list value>
```