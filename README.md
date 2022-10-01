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
```

output
```
皹=钄改
hello world
```

## Thanks
