# -*- coding: utf-8 -*-
import pycrypto

rc = pycrypto.CDMRC()
rc.SetKey("123456")
enbuf = rc.Encrypt("hello world")
print(enbuf)
debuf = rc.Decrypt(enbuf)
print(debuf)