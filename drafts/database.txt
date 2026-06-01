* 富豪(millionaire) - 优化资源配比
* 投资(Investment) - 提升资金价值
* 助理(Assistant) - 解放生产力












* 数据结构与算法：

    * 排序，KMP
    * 红黑树
    * B树以及B+树，
    * hash
    * 图论


* 设计模式：

    * 创建型设计模式： 单例模式，工厂方法模式与与抽象工厂模式，原型模式
    * 结构型设计模式： 适配器模式，代理模式、桥接模式，组合模式
    * 行为型设计模式：策略模式，观察者模式，责任链模式，状态模式

* 工程管理：make,cmake,git

* Liinux基础学习

* 数据库：SQLlite, MySQL, Redis,MariaDB,

### 网络设计

* 网络io与select以及poll与epoll
* reacter原理
* http服务实现
* websockert实现
* Apache，NGINX源码解析
* 网络协议栈
* 网络框架


### 基础组件

* 池化技术
* 进程通信
* 锁技术*
* 开源组件

### 中间件开发

* 事务操作
* REDIS
* MYSQL
* MondGB*

### 框架学习

* SykNet
* ZeroMQ*



* 数据



* 模型(数值/字符/枚举/数组/引用)
* 事件(订阅/通知/广播)
* 接口(属性/状态/实现/文档)



GRANT ALL PRIVILEGES ON *.* TO 'root'@'localhost' IDENTIFIED BY 'root' WITH GRANT OPTION;
GRANT ALL PRIVILEGES ON *.* TO 'root'@'127.0.0.1' IDENTIFIED BY 'root' WITH GRANT OPTION;


* 服务器：连接、断开、检查
* 数据库：创建、删除、修改、查找、更新、备份、导入、搜索
* 数据表：创建、删除、修改、查找、更新、导出、导入、搜索
* 数据项：创建、删除、修改、查找、更新、导出、导入、搜索



* 最小权限原则 (Principle of Least Privilege)
* 账户识别：每个数据库账户由 '用户名'@'主机名' 联合确定
* 主机限定: 精细化控制登录来源



* sys - sys_schema: 一个集合了视图 (View)、函数 (Function) 和存储过程 (Stored Procedure) 的工具库
* mysql -
* information_schema -
* performance_schema -

* mysql.user
* mysql.db
* mysql.tables_priv
* mysql.columns_priv
* mysql.procs_priv
* mysql.proxies_priv

* 全局权限 (Global Privileges)
* 数据库权限 (Database Privileges)
* 数据表权限 (Table Privileges)
* 数据列权限 (Column Privileges)



* 服务维护


```
# 安全模式
mariadbd-safe --skip-grant-tables
# 加载权限模块
FLUSH PRIVILEGES;
SELECT * FROM mysql.user ORDER BY User, Host;
```


* 用户管理

```
# 创建用户
CREATE USER 'app_user'@'localhost' IDENTIFIED BY 'StrongP@ssw0rd!';
CREATE USER 'app_user'@'192.168.1.%' IDENTIFIED BY 'StrongP@ssw0rd!';
```

* 权限管理

```
# 权限审查
SHOW GRANTS;
SHOW GRANTS FOR CURRENT_USER();
SHOW GRANTS FOR 'wenger'@'localhost';
# 撤销权限
REVOKE ALL PRIVILEGES, GRANT OPTION FROM 'app_user'@'localhost';
# 授予权限
GRANT ALL PRIVILEGES ON *.* TO 'root'@'localhost' IDENTIFIED BY 'root' WITH GRANT OPTION;
GRANT ALL PRIVILEGES ON wenger.* TO 'wenger'@'localhost' WITH GRANT OPTION;
GRANT SELECT, INSERT, UPDATE ON my_app_db.orders TO 'app_user'@'localhost';
GRANT CREATE USER, RELOAD, SUPER ON *.* TO 'db_admin'@'localhost';
```

* 数据库管理

```
SHOW DATABASES;
CREATE DATABASE wenger;
```

* 数据表管理

```
SHOW COLUMNS FROM users;
CREATE TABLE users (
    uuid     TINYINT UNSIGNED NOT NULL AUTO_INCREMENT,
    name VARCHAR(64),
    type     TINYINT UNSIGNED,
    PRIMARY KEY(uuid)
);
```

* 数据项管理

```
INSERT INTO users (name, type) VALUES ('test', 0);
SELECT * FROM mysql.user;
```
