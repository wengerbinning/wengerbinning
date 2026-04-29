UUID

RFC 4122 + RFC9562 -> RFC 9562

* 128bit(16B * 8)
xxxxxxxx-xxxx-xxxx-xxxx-xxxxxxxxxxxx(36:8-4-4-4-12)
xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx(32)

Version(4bit)
* 0b0000: Unused.
* 0b0001: The Gregorian time-based UUID specified in this document.
* 0b0010: Reserved for DCE Security version, with embedded POSIX UUIDs.
* 0b0011: The name-based version specified in this document that uses MD5 hashing.
* 0b0100: The randomly or pseudorandomly generated version specified in this document.
* 0b0101: The name-based version specified in this document that uses SHA-1 hashing.
* 0b0110: Reordered Gregorian time-based UUID specified in this document.
* 0b0111: Unix Epoch time-based UUID specified in this document.
* 0b1000: Reserved for custom UUID formats specified in this document.

Variant(4bit):
* 0b0xxx: Reserved. Network Computing System (NCS) backward compatibility, and includes Nil UUID as per
* 0b10xx: The variant specified in this document.
* 0b110x: Reserved. Microsoft Corporation backward compatibility.
* 0b111x: Reserved for future definition and includes Max UUID as per






UUIDv1 & UUIDv6
* timestamp(60bit): 实时
* version(4bit): 固定
* variant(2bit): 输入
* clock sequence(14bit): 取值随机或单调递增
* node(48bit): 输入


UUIDv2 for DCE Security UUID

UUIDv3
* md5(122bit):namespace + name calc md5
* version(4bit):固定
* variant(2bit):输入

UUIDv4
* random(122bit):
* version(4bit):
* variant(2bit):


UUIDv5
* sha1(122bit):
* version(4bit):
* variant(2bit):

UUIDv8
* constom-a
* version
* constom-b
* variant
* comstom-c
