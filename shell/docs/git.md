git是一个免费开源DVCS（Distributed Version Control System，分布式版本控制系统），是为了快速高效地处理所有项目的版本变迁，具有易学、体积小等特点。git支持快速管理多个完全独立的本地分支，当推送到远程存储仓库时，你可以指定推送的分支，在git工作中，有Working Directory、Staging Area、Repository三个区，其中Staging Area是可以在提交之前对提交格式化和检查；git项目属于Software Freedom Conservancy。

## 环境配置

在使用git之前，需要配置用户信息，全局配置文件`~/.gitconfig`，仓库配置文件`<repository>/.git/config`。git提供`git config`来配置信息;当然如果熟悉配置文件，则可以直接修改配置文件。

* 【功能】指定全局默认用户名：

  ```shell
  # 指定全局默认的用户名。
  git config --global user.name <your name>
  ```

  > Note：如果没有--global参数会为当前仓库设置用户信息，当然你的工作目录必须在一个仓库下才能这样使用。

* 【功能】指定全局默认用户邮箱：

  ```shell
  # 指定全局默认的用户邮箱。
  git config --global user.email <your email>
  ```

* 【功能】支持中文显示：

  ```shell
   git config --global core.quotepath off
   ```

* 【功能】：查看配置信息：

  ```shell
  # 查看所有变量。
  git config -l
  # 查看指定变量信息，这里以user.name为例。
  git config user.name
  ```

  > Note：可以使用`git help config`来查看git config的详细使用方法。

## 使用示例

Git的使用主要有管理本地仓库、远程仓库、仓库文件、版本回溯、解决冲突、服务搭建等主要内容。

### 本地仓库

* 【功能】新建仓库：新建一个本地仓库。

  ```shell
  # 初始化当前工作目录为一个新的仓库。默认会在该目录下新建一个.git/来存储生成的仓库信息文件。
  git init
  # 指定一个工作目录初始化为新的仓库。
  git init <directory>
  # 初始化当前工作目录为一个新的裸库。即直接在当前工作目录下生成仓库信息文件。
  git init --base
  ```

  > Note：如果工作目录下存在其他文件，则会有提示，但也可以创建成功。

* 【功能】添加文件：将工作目录下新建文件或者更新文件添加到暂存区。

  ```shell
  # 添加新建文件或更新文件到暂存区。
  git add <file>
  # 将当前工作目录下所有新建文件或更新文件添加到暂存区。
  git add *
  ```

  > 暂存区会对添加到暂存区的新建文件或更新文件进行跟踪。当文件未被跟踪或者跟踪的文件发生变更，都需要进行添加文件操作。

* 【功能】撤销添加：撤销添加到暂存区的新建文件或者更新文件的操作。

  ```shell
  # 撤销添加到暂存区的文件，恢复之前文件的状态。
  git restore --staged <file>
  ```

* 【功能】提交变更：将暂存区跟踪文件的变更进行提交。

  ```shell
  # 将暂存区。
  git commit -m <commit>
  # 首先会检查暂存区已跟踪的文件是否有更新文件，然后将更新文件添加到暂存区，最后提交此次变更。
  git commit  -am <comment>
  ```

  > Note：每一次变更提交都具有一个commit id来标识此次提交。

* 【功能】文件对比：将工作目录下的更新文件、暂存区下的跟踪文件以及仓库中的存储文件进行对比。

  ```shell
  # 将暂存区下的跟踪文件与工作目录下的更新文件进行对比。
  git diff <file>
  # 将当前提交与上一次提交的变更文件进行对比。
  git show <file>
  ```

* 【功能】检查工作区：将工作区与暂存区进行对比显示。

  ```shell
  # 将工作区与暂存区进行对比显示。
  git status
  ```

* 【功能】设定标签：为每一次提交设定一个标签。

  ```shell
  # 为当前分支的HEAD设定一个标签。
  git tag <tag name>
  # 为指定提交设定一个标签。
  git tag -a <tag name> <commit id> -m <messgae>
  # 显示当前分支的所有标签。
  git tag
  # 删除一个标签。
  git tag -d <label>
  ```

  > Note：标签相当于commit id的一个别名，是为了以后便于版本的回溯。

* 【功能】创建分支：为当前默认主分支master创建一个分支。

  ```shell
  # 为当前分支创建一个分支。
  git branch <branch name>
  # 切换分支。
  git switch <branch>
  # 显示该仓库的所有分支。
  git branch
  # 删除一个分支。在删除前会检查当前分支是否被合并如果未合并，则删除失败。
  git branch -d <branch>
  # 直接删除分支。
  git branch -D <branch>
  ```

  > Note：创建分支其实是创建一个分支地址指向当前分支的HEAD，并没有复制文件。

* 【功能】查看仓库状态：

  ```shell
  # 显示工作区状态。
  git status
  # 以简洁的格式显示状态。
  git status -s
  #　显示未跟踪的文件。
  git status -u
  # 显示忽略的文件。
  git status --ignored
  # 以图形的方式查看日志。
  git log --graph
  ```

* 【功能】撤销文件改动：

  ```shell
  # 撤销文件在工作区的修改，是工作区文件与暂存区文件保持一致。
  git checkout -- <file>
  # 撤销文件在暂存区的添加，是暂存区文件与仓库中文件保持一致。
  git reset HEAD <file>
  # 撤销一次提交。
  git revert
  # 恢复文件。
  git restore
  git rebase
  ```

### 远程仓库

* 【功能】克隆远程仓库：

  ```shell
  # 克隆远程仓库到当前目录，这里以我github的demo作为演示。
  git clone https://github.com/wengerbinning/demo
  # 克隆远程仓库到指定目录。
  git clone <repository> <dicestory>
  # 克隆指定版本的的仓库。
  git clone <repository> --branch <branch_tag> --single-branch
  ```

* 【功能】拉取远程仓库：

  ```shell
  # 拉取远程仓库并合并到到本地仓库。
  git pull
  ```

* 【功能】推送本地仓库：

  ```shell
  # 将本地仓库的变更推送到远程仓库。
  git push
  # 将标签一起推送。
  git push --tags
  ```

* 【功能】获取远程仓库：

  ```shell
  # 获取远程仓库，不与本地仓库合并。
  git fetch
  git fetch <remote label>
  ```

* 【功能】管理远程仓库：

  ```shell
  #　显示所有远程仓库。
  git remote -v
  git add <remote label> <url>
  ```

### 仓库文件

* 【功能】删除仓库文件：

  ```shell
  # 将文件从仓库中删除。
  git rm <file>
  ```

* 【功能】搜索仓库文件：

  ```shell
  git grep
  ```

* 【功能】显示仓库文件：
  
  ```shell
  git ls-tree
  ```

* 【功能】移动仓库文件：

  ```shell
  git mv
  ```

### 分支管理

* 【功能】新建分支：

  ```shell
  # 新建一个分支。
  git branch <branch name>
  # 查看分支列表即当前所在分支。
  git branch
  # 查看当前分支的最近的提交。
  git branch -v
  ```

* 【功能】切换分支：

  ```shell
  # 切换分支。
  git checkout <branch>
  # 新建分支并切换到新建的分支。
  git checkout -b <branch>
  ```

* 【功能】合并分支：
  
  ```shell
  # 将指定分支合并到当前分支。默认使用fast-formad模式进行合并。丢掉分支信息。
  git merge <branch>
  # 将指定分支合并到当前分支。不使用fast-formad模式进行合并。将合并当作一次提交。
  git merge --no-ff <branch>
  ```

* 【功能】删除分支：

  ```shell
  # 删除已存在并已被合并的分支。
  git branch -d <branch>
  # 强行删除分支
  git branch -D <branch>
  ```

### 版本回溯

* 【功能】撤销提交变更：

  ```shell
  # 撤销一次提交的版本。
  git reset --hard <commit ID>
  ```



### 解决冲突

* 【功能】分析文件差异：

  ```shell
  git diff
  ```

* 【功能】git栈：

  ```shell
  # 将当前工作区中的内容备份到git栈中，并将工作去恢复到上次提交的状态。
  git stash
  # 将git栈中的内容恢复到工作区中。
  git stash pop
  # 显示git栈中的存储情况。
  git stash list
  # 清空git栈。
  git stash clear
  ```

* 


* .gitignore
* .gitattuributes
* .mailmap


## 原理分析

git是一个版本控制器，由工作区、缓存区、本地仓库、远程仓库组成 


分支即一条提交的链表，master为主分区，HEAD为当前分支的最后一次提交。每一次提交包含前一次提交的commit id。




## 



git在使用ssh连接clone的仓库时。在服务器端配置好public key之后，如果key文件的路径是自己配置的，需要在.ssh/config文件中指定private key文件的路径

```config
host <service host>
    IdentityFile ~/.ssh/key/<private file>
```

## LINKS
* [官方网站](https://git-scm.com/) ☛ <https://git-scm.com/>