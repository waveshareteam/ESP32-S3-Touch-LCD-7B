# 出厂固件

| 文件 | 用途 | 烧录偏移 |
| --- | --- | --- |
| [ESP32-S3-Touch-LCD-7B_FactoryOnly_20250701.bin](ESP32-S3-Touch-LCD-7B_FactoryOnly_20250701.bin) | ESP32-S3-Touch-LCD-7B（16 MB Flash）出厂测试固件 | `0x0` |

将开发板置于下载模式并连接电脑，在本目录运行：

```sh
python -m esptool --chip esp32s3 write-flash 0x0 ESP32-S3-Touch-LCD-7B_FactoryOnly_20250701.bin
```
