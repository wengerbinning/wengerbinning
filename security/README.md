

X.509是密码学中公钥证书的标准格式，该标准有两种编码格式(PEM, Privacy Enhanced Mail)与(DER, Distinguished Encoding Rules)两种
这两种格式都可以存储私钥、公钥以及证书。

自签证书是使用自己的私钥签发证书

crt 证书
cer 证书
key 私钥
pub 公钥
csr 证书签名请求

生成私钥文件，私钥是非对称加密的一部分，根据私钥可以生成另一部分公钥。

* openssl生成私钥，默认密钥长度是生成2048。默认生成的是pem格式的文件

```shell
# RSA
openssl genrsa -out private-key.key 2048
```

* openssl根据私钥生成公钥。

```shell
# 查看私钥信息。
openssl rsa -text -in private-key.key

# 根据私钥生成公钥。
openssl rsa -in private-key.key -pubout -out public-key.pub
```

在生成密钥文件之后，需要根据密钥文件来生成一份证书请求，该文件会包含组织的相关信息。

* openssl根据私钥生成证书请求。

```shell
# 生成证书请求
openssl req -new -key private-key.key -out certificate-request.csr

# 查看证书请求
openssl req -in cerificate-request.csr -noout -text
```

在有证书请求之后，可以根据证书请求以及请求的私钥来生成一份根证书，根据证书请求与根证书以及根证书的私钥来生成服务端证书或客户端证书。
来openssl根据私钥与证书请求生成证书。

* 根据根证书请求与请求的私钥来生成根证书。

```shell
# CA Certificates
openssl x509 -req -days 365 -in ca.csr -signkey ca.key -out ca.crt
```

根据证书请求与根证书以及根证书的私钥生成对应的证书


```shell
openssl x509 -req -days 365 -CA ca.crt -CAkey private/ca.key -CAserial private/ca.srl -CAcreateserial -in server.csr -out server.crt
```
openssl x509 -req -days 365 -CA private/ca.crt -CAkey private/ca.key -CAcreateserial -in newcerts/localhost/localhost.csr -out  newcerts/localhost/localhost.crt


CA(Certificate Authority)有证书授权、认证中心以及认证机构的含义。



## 

**根证书**

* 生成根证书私钥。

```log
wenger private $ openssl genrsa -out ca.key 2048
Generating RSA private key, 2048 bit long modulus (2 primes)
...............+++++
........................................+++++
e is 65537 (0x010001)
```

```shell
openssl req -new -key ca.key -out ca.csr
```

**localhost**

```log

```



