repo 是Android为管理多个git仓库而开发的python脚本工具。repo会通过集中维护的repo清单获取git仓库的数量、名称以及路径等，然后通过这些基本信息对git仓库进行操作。repo是通过一个git仓库（mainifests）来管理项目的repo清单。repo工具也是通过repo仓库来维护的，我们本地的repo只是获取这两个仓库资源的脚本。


repo清单是一个标准的XML文档。其中`remote`标签描述了远程仓库的基本信息。`default`标签描述了`project`标签的默认属性。`project`标签描述了每一个仓库。

repo在每一次初始化时，会将repo仓库下载到`.repo/`下来为我们提供服务；

# 使用方法

<https://blog.csdn.net/nwpushuai/article/details/78778602>

* `repo init`: 

  ```shell
  # 初始化repo
  repo init -u <url> -b <branch> -m <mainifests name>
  # url： 用于指定mainifests的仓库地址。
  # branch： 用于指定仓库的分支。
  # mainifests name: 用于指定使用mainifests中的repo清单名称。
  # --trace：用于打印输出执行过程。
  # --repo-url：用于指定repo仓库的地址。
  # --repo-branch：用于指定repo仓库的分支。
  # -no-repo-verify：配置下载repo仓库是不启用检查。
  ```

  > Note:执行该命令会在当前目录下创建一个`.repo`的隐藏目录，其中有以下内容：
  > * `.repo/mainifests`： 是一个repo清单仓库，存放我们使用的repo清单。
  > * `.repo/mainifests.git`:mainifests仓库的实体。
  > * `.repo/mainifests.xml`:是`.repo/mainifests`下default.xml的软连接。
  > * `.repo/repo`:是repo工具集仓库。

* `repo sync`:将本地仓库代码根据远程仓库同步到最新，默认对所有仓库代码更新。

  ```shell
  # 同步仓库代码。
  repo sync -j<number>
  # number: 用于指定开启多线程的线程数，默认情况下是4个。
  # -c： current-branch 只同步指定的远程分支。
  # -d： detach 脱离当前的本地分支，切换到repo清单中的分支中。
  # -f： force-broken 当有仓库sync失败后，指定继续sync接下来的仓库。
  # -no-clone-bundel：
  ```

* `repo upload`:

  ```shell
  # 将本地仓库同步到远程仓库。
  repo upload
  
  ```




