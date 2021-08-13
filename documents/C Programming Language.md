# C Programming Language

[//]: # (__author__ = "Clark Aaron")

1. 在安装完 VS Code 之后, 首先在扩展商店( Ctrl + shift + X )中安装`C/C++`插件, 之后在任意位置新建一个文件夹作为工作空间,然后使用
VS Code 打开该文件夹.

2. 在工作空间中新建一个名为`.vscode`的子文件夹保存 VS Code 的配置信息; 并在`.vscode`子文件夹中新建`c_cpp_properties.json`、
`tasks.json`与`launch.json`三个配置文件.

   * 其中`c_cpp_properties.json`基本配置内容如下:

     ```json
     {
         "configurations": [
             {
                 "name": "MinGW64",
                 "intelliSenseMode": "gcc-x64",
                 "compilerPath": "D:/mingw64/bin/g++.exe",
                 "includePath": [
                     "${workspaceFolder}/include/**"
                 ],
                 "browse": {
                     "path": [
                         "${workspaceFolder}"
                     ]
                 },
                 "cStandard": "c11",
                 "cppStandard": "c++17"
             }
         ],
         "version": 4
     }
     ```

   * `tasks.json`基本配置内容如下:

     ```
     {
         "version": "2.0.0",
         "tasks": [
             {
                 "label": "Compile",
                 "command": "g++",
                 "args": [
                     "${file}",
                     "-o",
                     "${workspaceFolder}/bin/${fileBasenameNoExtension}.exe",
                     "-O0",      // 优化级别
                     "-ggdb3",   // 生成和调试有关的信息
                     "-Wall",    // 开启额外警告
                     "-static-libgcc",   // 静态链接
                     "-std=c++17",       // 使用c++17标准
                     "-finput-charset=UTF-8", //输入编译器文本编码 默认为UTF-8
                     "-fexec-charset=GB18030",   //输出exe文件的编码
                     "-D _USE_MATH_DEFINES"
                 ],
                 "type": "shell",        
                 "group": {
                     "kind": "build",
                     "isDefault": true
                 },
                 "presentation": {
                     "echo": true,
                     "reveal": "never",
                      "focus": false,
                      "panel": "shared"
                 },
             }
         ]
     }
     ```

   * `launch.json`基本配置内容如下:

     ```
     {
         "version": "0.2.0",
         "configurations": [
             {
                 "name": "C++ Launch (GDB)",  
                 "type": "cppdbg",               
                 "request": "launch",              
                 "targetArchitecture": "x64",           
                 "program": "${workspaceFolder}/bin/${fileBasenameNoExtension}.exe",
                 "args": [],                           
                 "stopAtEntry": false,                  
                 "cwd": "${workspaceRoot}",           
                 "externalConsole": false,              
                 "internalConsoleOptions": "neverOpen",  
                 "MIMode": "gdb",                            // 指定连接的调试器
                 "miDebuggerPath": "D:/mingw64/bin/gdb.exe", // 调试器路径
                 "setupCommands": [
                     {
                         "description": "Enable pretty-printing for GDB",
                         "text": "-enable-pretty-printing",
                         "ignoreFailures": false
                     }
                 ],
                 "logging": {         
                     "exceptions": true,
                     "moduleLoad": true,
                     "programOutput": true,
                     "engineLogging": false,
                     "trace": false,
                     "traceResponse": false
                 },
                 "preLaunchTask": "Compile" 
             }
         ]
     }
     ```

   * 以上配置信息需要在工作空间中新建`bin`文件夹作为可执行文件存储目录, `resource`作为源代码存储目录, `include`作为自定义头文件搜索路径.
   