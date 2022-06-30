# Hypertext Transfer Protocol

超文本传输协议(HTTP, Hypertext Transfer Protocol)是一个应用层协议，是基于TCP的请求响应协议。在HTTP发真过程中，主要有0.9、1.0、1.1以及2.0这几个版本。


### 请求类型

在HTTP协议中

**GET**

get


### 请求头部

**Cache-Control**

Cache-Control用于控制缓存，以下是取值的详细说明

-- `no-cache`表示服务端不做缓存，每次都去请求数据
-- `no-store`表示所有内容都不做缓存。强制缓存以及对比缓存都不会出发。
-- `public`
-- `private`
-- `max-age`
