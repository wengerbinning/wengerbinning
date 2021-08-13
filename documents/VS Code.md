# Virtual Studio Code

[//]: # (__author__ = "Clark Aaron")

VS Code 是一款强大的轻量级的集成开发环境，支持C、C++、Python、Java、HTML、PHP、C#、Go等主流的开发语言;

## 资源链接

> [官方网站](https://code.visualstudio.com/) ☛ <https://code.visualstudio.com/>

* [官方文档](https://code.visualstudio.com/docs) ☛ <https://code.visualstudio.com/docs>

* 终端安装插件: `code --install-extension DavidAnson.vscode-markdownlint`

markdownlint   : 一个Markdown的规则检测插件;

${workspaceFolder} - the path of the folder opened in VS Code
${workspaceFolderBasename} - the name of the folder opened in VS Code without any slashes (/)
${file} - the current opened file
${relativeFile} - the current opened file relative to workspaceFolder
${relativeFileDirname} - the current opened file's dirname relative to workspaceFolder
${fileBasename} - the current opened file's basename
${fileBasenameNoExtension} - the current opened file's basename with no file extension
${fileDirname} - the current opened file's dirname
${fileExtname} - the current opened file's extension
${cwd} - the task runner's current working directory on startup
${lineNumber} - the current selected line number in the active file
${selectedText} - the current selected text in the active file
${execPath} - the path to the running VS Code executable
${defaultBuildTask} - the name of the default build task

## 环境配置

### 预定义变量

* `${workspaceFolder}`: VScode的工作目录;
* `${workspaceFolderBasename}`: VScode的工作目录名称;
* `${file}`: 当前打开文件;
* `${fileDirname}`：当前文件所在目录；
* `${relativeFile}`: 当前文件相对于工作目录的路径;
* `${relativeFileDirname}`: 当前文件的目录相对于工作目录的路径;
* `${fileBasename}`: 当前文件的文件名;
* `${fileBasenameNoExtension}`: 当前文件的文件名(不带文件扩展名的);
* `${fileDirname}`: 当前文件的目录名;
* `${fileExtname}`: 当前文件使用的扩展;
* `${cwd}`: task运行时的目录;
* `${lineNumber}`: 当前悬着好的行号;
* `${selectedText}`: 当前所选内容;
* `${execPath}`: 运行时路径;
* `${defaultBuildTask}`: 默认的task;

## 基本使用

## 插件扩展

VS Code 通过扩展API可以实现许多功能;

### 创建演示扩展

在创建之前,需要确认已安装Node.js与Git;

## 关闭错误提示

C_Cpp.error Squiggles
