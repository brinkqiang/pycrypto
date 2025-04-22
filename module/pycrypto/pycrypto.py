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
