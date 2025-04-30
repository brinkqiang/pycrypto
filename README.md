# pycrypto

Copyright (c) 2013-2018 brinkqiang (brink.qiang@gmail.com)


## Build status
| [Linux][lin-link] | [Mac][mac-link] | [Windows][win-link] |
| :---------------: | :----------------: | :-----------------: |
| ![lin-badge]      | ![mac-badge]       | ![win-badge]        |

[lin-badge]: https://github.com/brinkqiang/pycrypto/workflows/linux/badge.svg "linux build status"
[lin-link]:  https://github.com/brinkqiang/pycrypto/actions/workflows/linux.yml "linux build status"
[mac-badge]: https://github.com/brinkqiang/pycrypto/workflows/mac/badge.svg "mac build status"
[mac-link]:  https://github.com/brinkqiang/pycrypto/actions/workflows/mac.yml "mac build status"
[win-badge]: https://github.com/brinkqiang/pycrypto/workflows/win/badge.svg "win build status"
[win-link]:  https://github.com/brinkqiang/pycrypto/actions/workflows/win.yml "win build status"

## Intro

- pycrypto
```python
# -*- coding: utf-8 -*-
import pycrypto

rc = pycrypto.CDMRC()
rc.SetKey("123456")
enbuf = rc.Encrypt("hello world")
print(enbuf)
debuf = rc.Decrypt(enbuf)
print(debuf)

md5 = pycrypto.CDMMD5()
print(md5.GetMD5("hello world"))

base64 = pycrypto.CDMBase64()
base64_encode = base64.Base64Encode("hello world")
print(base64_encode)
base64_decode = base64.Base64Decode(base64_encode)
print(base64_decode)


aes = pycrypto.CDMAES()

plain = "hello world12345" # Plaintext length must be divisible by 16
iv = "hello world"
key = "hello world"

aes_encode = aes.EncodeECB(plain, key)

print(f"aes_ecb -> {aes_encode}")

aes_decode = aes.DecodeECB(aes_encode, key)

print(f"aes_ecb -> {aes_decode}")

aes_encode2 = aes.EncodeCFB(plain, key, iv)

print(f"aes_cfb -> {aes_encode2}")

aes_decode2 = aes.DecodeCFB(aes_encode2, key, iv)

print(f"aes_cfb -> {aes_decode2}")

```

output
```
b'\xa2f\xb0\x98=\xe8\x94\x18\xb8\xc4\x8c'
b'hello world'
5EB63BBBE01EEED093CB22BB8F5ACDC3
aGVsbG8gd29ybGQ=
hello world
aes_ecb -> b'\x03\xfa,\x12\xed\x0e\x90\\3\xc6O\xcdP\xe59\x9b'
aes_ecb -> b'hello world12345'
aes_cfb -> b'\x1a\xe9\x92\x9c\xa5\x7f\xd0\x02\xd9\xe0\x8f\x14\xbe{jO'
aes_cfb -> b'hello world12345'
```

## Thanks
