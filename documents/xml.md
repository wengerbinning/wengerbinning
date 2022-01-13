# XML

[//]: # (__author__ = "Wenger Binning")

可扩展标记语言(XML,Extensible Markup Language)是W3C开发的一种标记语言，该语言使用一
种人与计算机均可读的文档格式。该语言的设计目标是增强互联网上数据传输的简单性、通用性以及可
用性。xml文档是一种文本数据格式，并支持unicode编码。尽管该语言的重点在与文档，但是在也广
泛用于表示任意的数据结构，例如Web服务器中的数据结构。xml语言存在几种设计来帮助标识数据，
各类编程语言也存在解析与生成xml文档的API。XML文档中的内容分为标记与内容，标记是标签、空
格等特殊的字符串，除标记之外的都是内容。

XML文档中中的标签是以`<element>`作为开始，`</element>`作为结束的标记，当两个标签之间
没有内容时，可以简化为`<element />`。当然每一个标签也可以使用键值对来指定对应的属性。




```xml
<?xml version="1.0" encoding="ISo--8859-1"?>
<!-- TODO you can do anything in here. -->

```

* xml标签：支持自定义，必须成对出现。

* 标签属性：标签可以添加属性，但是其值只能为字符串。

在xml中存在实体引用字符，例如`&lt;`表示字符`<`、`&gt;`表示字符`>`、`&amp;`表示字符`&`、
`&apos;`表示字符`'`、`&quot;`表示字符`"`。


* 文档注释：

  ```xml
  <!-- comment -->
  ```

* 以LF存储换行。

* 导入xslt：
  
```xml
<?xml-stylesheet type="text/xsl" href="*.xsl"?>
```
