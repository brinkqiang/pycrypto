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


```

output
```
b'\xa2f\xb0\x98=\xe8\x94\x18\xb8\xc4\x8c'
b'hello world'
5EB63BBBE01EEED093CB22BB8F5ACDC3
aGVsbG8gd29ybGQ=
hello world
```

## Thanks
