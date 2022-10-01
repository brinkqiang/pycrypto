# dmpymodule

Copyright (c) 2013-2018 brinkqiang (brink.qiang@gmail.com)


## Build status
| [Linux][lin-link] | [Mac][mac-link] | [Windows][win-link] |
| :---------------: | :----------------: | :-----------------: |
| ![lin-badge]      | ![mac-badge]       | ![win-badge]        |

[lin-badge]: https://github.com/brinkqiang/dmpymodule/workflows/linux/badge.svg "linux build status"
[lin-link]:  https://github.com/brinkqiang/dmpymodule/actions/workflows/linux.yml "linux build status"
[mac-badge]: https://github.com/brinkqiang/dmpymodule/workflows/mac/badge.svg "mac build status"
[mac-link]:  https://github.com/brinkqiang/dmpymodule/actions/workflows/mac.yml "mac build status"
[win-badge]: https://github.com/brinkqiang/dmpymodule/workflows/win/badge.svg "win build status"
[win-link]:  https://github.com/brinkqiang/dmpymodule/actions/workflows/win.yml "win build status"

## Intro

- dmpymodule
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
## Thanks
