# CSS

CSS(Cascading Style Sheets,层叠样式表)是一种表现HTML或XML等文件样式的计算机语言,不仅可以静态地修饰网页,而且可以配合脚本语言动态地对网页各元素进行格式化;能够对网页中元素位置的排版进行像素级控制,几乎支持所有的字体字号样式,拥有对网页对象和模型样式编辑的能力.在CSS中,主要分为选择器与属性等内容.

在编辑CSS时: 属性和值被冒号分开。CSS声明总是以分号(;)结束，声明组以大括号({})括起来。

## 多重样式的优先级

其中优先级从高到低分别是内联样式、id选择器、伪类、属性选择器、类选择器、元素选择器、通用选择器;`!import`规则被应用在一个样式声明中时,该样式声明会覆盖CSS中任何其他的声明,不推荐使用`!import`规则.

# CSS属性

```python
__author__ = "Clark Aaron"
__date__ = "2020-04-12"
__time__ = "23:06"
```

属性由属性名与属性值组成,其中属性名是CSS中的关键字,属性值是整数、实数、百分数等.

## CSS 背景

* `background-color`属性: 定义了元素的背景颜色,属性值以#FFFFFF(十六进制的RGB).
* `background-image`属性: 定义了元素的背景图像,默认情况下,背景图像进行平铺重复显示,以覆盖整个元素实体.
* `background-repeat`属性: 定义了元素的背景图像的填充方式,其值有`repeat-x(水平方向)`
* `background-attachment`属性:
* `background-position`属性: 定义了元素的背景图像在背景中的位置

## CSS文本

* `color`属性: 定义文本颜色;
* `direction`属性: 定义文本方向;
* `letter-spacing`属性: 定义字符间距;
* `line-height`属性: 定义行高;
* `text-align`属性: 定义了文本的对齐方式;
* `text-decoration`属性: 定义了文本的修饰;
* `text-indent`属性: 定义文本的首行缩进;
* `text-shadow`属性: 定义了文本阴影;
* `text-transform`: 控制元素中的字母;
* `unicode-bidi`属性: 设置或返回文本是否被重写;
* `vertical-align`属性: 设置元素的垂直对齐;
* `white-space`属性: 设置元素中空白的处理方式;
* `word-spacing`属性: 设置字间距;

## CSS字体

在CSS中有通用字体类型与特定字体类型两种类型;

* `font`属性: 在一个声明中设定所有的字体属性;
* `font-family`属性: 指定文本的字体系列;
* `font-size`属性: 指定文本的字体大小;
* `font-style`属性: 指定文本的字体样式;
* `font-variant`属性: 以小型大写字体或正常显示文体;
* `font-weight`属性: 指定字体的粗细;

## CSS 链接

* 链接样式,链接状态:

    1. `a:link`: 正常,未访问的链接;
    2. `a:visited`: 用户已访问的链接;
    3. `a:hover`: 当鼠标放在链接上时;
    4. `a:active`: 链接被点击的时刻;

## CSS列表样式

* `list-style`属性: 简写属性;
* `list-style-image`属性:将图像设置为列表项标志;
* `list-style-position`属性: 设置列表中列表标志的位置;
* `list-style-typle`属性: 设置列表项标志的类型;

## CSS盒子模型

* `margin`属性: 外边距;
* `border`属性: 边框;
* `padding`属性: 内边距;
* `content`属性: 内容

# CSS选择器

CSS选择器用于选择属性作用的元素对象;选择器分别由id选择器与class选择器.

## id选择器

id选择器是以标有特定id的HTML元素作为编辑对象,以`#`作为id选择器的标识前缀.

## class选择器

class选择器是以HTML中的class属性来标定编辑对象,以`.`作为class选择器的标识前缀.

## CSS分组选择器

在CSS中,可以使用`,`将多个选择器作为属性作用对象;

## CSS选择器的嵌套

可以使用多个选择器嵌套;