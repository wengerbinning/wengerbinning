# Markdown

[//]: # (__author__ = "Clark Aaron")

Markdown是用于编辑纯文本的标记语言,于2004年由John Gruber开发;广泛用于编辑帮助文档,且易于导出为pdf,html等格式文件.例如GitHub,简书等都使用
Markdown来编辑文档,支持该语言的编辑器有Typora,Atom,VS code等,Markdown文档一般以后缀名`.md`或`.markdown`来标识。

## 基本语法

Markdown通过标记来标识文档的显示格式,并且支持html语法.

### 文本编辑

markdown拥有极简的语言格式，其中段落之间使用一个以上的空白行来标识。

* 【标题】markdown使用#来标识标题，#的数量来标识标题等级，在标识符与标题内容之间插入一个空格：

  ```markdown
  # 一级标题
  ## 二级标题
  ### 三级标题
  #### 四级标题
  ##### 五级标题
  ###### 六级标题
  ```

* 【字体】markdown使用*、_、~来标识字体的样式：

  ```markdown
  *倾斜字体*
  **加粗字体**
  ***倾斜及加粗字体***
  _倾斜字体_
  __加粗字体__
  ___倾斜及加粗字体___
  ~~删除线~~
  ```

* 【分割】markdown使用三个连续的*、-、_字符来表示一条分割线。

* 【区域】markdown区域是以`>`标识的。

  ```markdown
  > 一级引用

  >> 二级应用
  ```

#### 列表

markdown支持有序列表与无序列表两种;并且可以嵌套使用.

* 【无序列表】使用`*`、`+`以及`-`标识列表项：

  ```markdown
  * 列表一
  - 列表二
  + 列表三
  ```

* 【有序列表】使用数字加`.`的标识有序列表：

  ```markdown
  1. 有序列表一
  2. 有序列表二
  ```

#### 表格

Markdown支持表格嵌入,其具体格式如下.

```markdown
| title1 | title2 | title3 |
|:------ |:------:| ------ |
| label1 | label2 | label3 |
```

#### 代码

代码区块引用通常使用反引号标识,并注明语言,引用一句代码时,仅需要一个反引号标识即可.

```c
#include <stdio.h>

int main(int args, char * argv[] )
{
    printf("contemnt");
    return 0;
}
```

### 外部链接

#### 网站链接

Markdown可以插入链接,有隐式链接与显式链接,隐式链接使用`<>`标识链接,显式链接使用`[]<>`标识链接与名称,除此之外可以使用`[][]`标识链接变量.

```markdown
<https://www.baidu.com>         [百度一下](https://www.baidu.com)
[Linux][linux]


[linux]: https://linux.org "Linux"
```

#### 图片链接

Markdown插入图片时使用`![]()`标识图片,或者使用链接变量的形式标识,如果需要定制图片尺寸,则需要使用html标签.

```markdown
![属性文本](https://images.unsplash.com/photo-1588609274577-2976890c56a4?ixlib=rb-1.2.1&auto=format&fit=crop&w=675&q=80,title)

![属性文本][images]

[images]: https://images.unsplash.com/photo-1588609274577-2976890c56a4?ixlib=rb-1.2.1&auto=format&fit=crop&w=675&q=80m "title"
```

### 扩展功能

* 支持html元素`<kbd>`、`<b>`、`<i>`、`<em>`、`<sup>`、`<br>`等.

  ```markdown
  <!-- 标识键盘按键 -->
  <kbd>Esc</kbd>
  ```

* 支持LateX,使用`$$`标识latex语言.

  ```markdown
  $a + b = c$
  $$
  f(x) = \int_{-\infty}^\infty \hat f(\xi)\,e^{2 \pi \xi x} \,d\xi
  $$
  ```

* 支持流程图,使用`mermiad`与`flow`以及`sequence`标识流程图.

  ```mermaid
  graph TD
  A[方形] --> B(圆角)
      B --> C{条件a}
      C --> |a=1| D[结果1]
      C --> |a=2| E[结果2]
      F[竖向流程图]
  ```
