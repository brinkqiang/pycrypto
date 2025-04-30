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
