nginx

* 文件共享

  ```nginx.conf
  autoindex on;
  ```

* 服务代理


* 用户验证：nginx中提供了ngx_http_auth_basic_module模块来实现用户验证，默认支持该模块，仅需要在配置中
配置即可.

  ```nginx.conf
  # 该项是控制是否开启验证的开关，默认为off，若为其他字符，则表示开启验证并提示。
  auth_basic "Please input password"; 
  # 该项是指定验证文件的路径。
  auth_basic_user_file /etc/nginx/htpasswd;
  ```
  
  配置文件可以使用htpasswd或者openssl来生成。

    