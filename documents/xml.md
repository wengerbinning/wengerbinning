# XML

[//]: # (__author__ = "Wenger Binning")

xml即可扩展标记语言，用于传输和存储数据。xml文档使用树形结构来管理内容。所有xml标签均可以自定义，但是必须有关闭标签与唯一的根标签。对大小写敏感。通过xslt可以格式化xml文本内容

* xml声明：

  ```xml
  <?xml version="1.0" encoding="ISo--8859-1"?>
  ```

* xml标签：支持自定义，必须成对出现。

* 标签属性：标签可以添加属性，但是其值只能为字符串。

* 实体引用字符：

  * `&lt;`：<
  * `&gt;`：>
  * `&amp;`：&
  * `&apos;`：'
  * `&quot;`："

* 文档注释：

  ```xml
  <!-- comment -->
  ```

* 以LF存储换行。

* 导入xslt：
  
  ```xml
  <?xml-stylesheet type="text/xsl" href="*.xsl"?>

