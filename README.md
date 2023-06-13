## 项目说明
本项目使用W-AVC，对[CWE](https://cwe.mitre.org/about/index.html)中部分漏洞进行harness编写并验证。

## 项目进度
| CWE_ID | NAME | DESCRIPTION | STATUS |
|---|---|---|---|
|[119](https://cwe.mitre.org/data/definitions/119.html)|  Improper Restriction of Operations within the Bounds of a Memory Buffer | The product performs operations on a memory buffer, but it can read from or write to a memory location that is outside of the intended boundary of the buffer. | INCOMPLETE |
|[120](https://cwe.mitre.org/data/definitions/120.html) | Buffer Copy without Checking Size of Input ('Classic Buffer Overflow') | The product copies an input buffer to an output buffer without verifying that the size of the input buffer is less than the size of the output buffer, leading to a buffer overflow. | INCOMPLETE |
|[415](https://cwe.mitre.org/data/definitions/415.html) |  Double Free | The product calls free() twice on the same memory address, potentially leading to modification of unexpected memory locations. | ✅ |
|[416](https://cwe.mitre.org/data/definitions/416.html) |  Use After Free | Referencing memory after it has been freed can cause a program to crash, use unexpected values, or execute code. | INCOMPLETE |


## 贡献名单
排名不分先后
- Xie ZiAng
- Xu Zhiwei
- Zhang Zhe
