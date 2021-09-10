# Docker

Docker是一个使用Go开发的基于Apache2.0开源的应用容器引擎。可以让开发者打包他们的应用程序以及依赖包到一个轻量级、可移植的的容器中。在docker中，有三个主要的内容：仓库、镜像、容器；仓库是一个管理镜像的控制中心，镜像是服务及运行环境的集合，容器是镜像的运行实例。其中镜像类似于系统快照，容器是基于快照创建的系统环境。在docker中主要包括镜像的管理、容器的管理以及网络的管理。

## 镜像管理

* 【功能】拉取镜像资源：

  ```shell
  # 拉取仓库中的镜像资源。
  docker pull <image>:<tag>
  ```

  > Note：如果未指定tag，默认使用latest。

* 【功能】显示本地镜像：

  ```shell
  # 显示本地所有镜像文件。
  docker images
  ```

* 【功能】查询镜像资源：

  ```shell
  # 从仓库中查询镜像资源。
  docker search <image>:<tag>
  ```

* 【功能】删除镜像资源：

  ```shell
  # 删除镜像资源。
  docker rmi <image>:<tag>
  ```

* 【功能】创建镜像资源：

  ```shell
  # 基于存在的容器创建一个镜像资源。
  docker commit -m=<description> -a=<author> <container id> <image name>:<tag>
  ```

  > Note：镜像文件名一般为小写。

  除此之外，还可以基于其他镜像创建一个新的镜像资源。首先需要创建一个名为`Dockerfile`的文件，其具体内容为：

  ```dockerfile
  FROM    <image>:<tag>
  MAINTAINER  <user name> <user email>

  RUN     useradd runoob
  RUN     /bin/echo -e "LANG=\"en_US.UTF-8\"" >/etc/default/local
  ```

  然后通过docker build构建新的镜像。

   ```shell
   docker build -t <image>:<tag> <Dockerfile path>
   ```

* 【功能】设定镜像标签：

  ```shell
  # 通过镜像的id来设定镜像的名称和标签。
  docker tag  <images id> <image name>:<tag>
  # 通过镜像名和标签来指定别名和标签。
  docker tag <iamge>:<tag> <image name>:<tag>
  ```

## 容器管理

* 【功能】创建新的容器：

  ```shell
  # 基于镜像创建新的容器并运行command程序。该容器是在后台运行。
  docker run <image>:<tag> <command>
  # 基于镜像创建新的容器并启动一个shell程序进行交互。
  docker run  -i -t <image>:<tag> <shell>
  # 基于镜像创建新的容器并指定容器在后台运行程序。
  docker run -d  <image>:<tag> <command>
  # 基于镜像创建新的容器并为容器指定一个别名。
  docker run --name <name> <image>:<tag> <command>
  # 基于镜像创建新的容器并未容器指定网络。
  docker run --network <net name> <image>:<tag> <command>
  ```

* 【功能】查看运行容器：

  ```shell
  # 查看运行的容器。
  docke ps
  # 产看所有容器。
  docker ps -a
  ```

* 【功能】停止运行容器：

  ```shell
  docker stop <container id>
  ```

* 【功能】重启运行容器：

  ```shell
  docker restart <container id>
  ```

* 【功能】进入后台容器：通过`docker attach`与`docker exec`来管理运行容器的程序。

  ```shell
  # 退出时容器停止运行。
  docker attach <container id>
  ```

  > Note：使用attach进入后台运行的容器，在退出时会暂停容器的运行。

  ```shell
  # 运行容器的bash。
  docker exec -it <container id> /bin/bash
  ```

  > Note：使用exec进入后台运行的容器，在退出时不会暂停容器的运行。

* 【功能】导出容器资源：

  ```shell
  docker export <container id> > <*.tar>
  ```

* 【功能】导入容器资源：

  ```shell
   cat docker/ubuntu.tar | docker import - test/ubuntu:v1
  ```

* 【功能】删除存在容器：

  ```shell
  docker rm -f <container id>
  // 清除所有未运行的容器。
  docker container prune
  ```

* 【功能】运行一个应用：

  ```shell
  # 创建一个web应用程序的后台运行的容器，执行 python app.py。并将容器内部使用的网络端口映射在本地主机上。
  docker run -d -P training/webapp python app.py
  ```

  > Note：通过-p参数可以指定映射端口。

* 【功能】查看映射端口：

  ```shell
  docker port <container id>
  ```

* 【功能】查看标准输出：

  ```shell
  docker logs -f <container id>
  ```

* 【功能】查看容器进程：

  ```shell
  docker top <container id>
  ```

* 【功能】查看容器信息：

  ```shell
  docker inspect <container id>
  ```
  
  
  ## LINKS
  
  * ifconfig： net-tools
  * ping：iputils-ping
  * ip：iproute2

* 

```shell
docker start
```


## 网络管理

docker有4种网络工作模式：

* bridge：将所有的的容器链接到一个虚拟桥docker0,通过docker0网桥以及iptable net表配置与宿主通信。

* host：直接使用宿主主机的IP与端口。容器不会获得一份独立的network namespace,而和宿主主机共用一个network namespace.

* none：关闭了容器的网络功能。

* container：和一个指定的容器共享ip与端口。指定与特定的容器使用同一个network namespace。

当然也可以自定义网络。

* 【功能】创建链接网络：

  ```shell
  dokcer network ls
  
  docker natwork create -d bridge <net name>
  
  ```

## Docker的架构

Docker包含三个概念：镜像、容器、仓库。容器是镜像运行的实体。仓库是一个代码控制中心，用来保存镜像。

docker使用Linux的namespace技术来进行资源隔离，例如PID namespace、mount namespace、network namespace等;

## Docker的应用

* Web应用的自动化打包和发布。

* 自动化测试和持续集成和分布。

