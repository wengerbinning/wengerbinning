# route

route是一个管理路由表信息的工具。在Linux中route是属于net-tools中的一个的工具。

## 使用示例

* 查看路由：

  ```shell
  # 显示路由表。
  route
  # 冗长显示路由表。
  route -v
  # 以纯数字的形式显示路由表。
  route -n
  # 显示更多信息。
  route -e
  # 
  route -F
  # 显示路由缓存。
  route -C
  # 显示软件版本信息。
  route -V
  ```

* 添加路由：

  ```shell
  route add
  ```

* 删除路由：

  ```shell
  route del
  ```

