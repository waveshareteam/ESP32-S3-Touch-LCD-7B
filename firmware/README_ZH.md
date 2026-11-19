# 出厂固件

按硬件型号选择合并 BIN，并从 `0x0` 烧录。两个型号均使用 ESP32-S3 和 16 MB Flash。

| 文件 | 适用型号 | 版本日期 | 烧录偏移 |
| --- | --- | --- | --- |
| [ESP32-S3-Touch-LCD-7B_FactoryOnly_20250701.bin](ESP32-S3-Touch-LCD-7B_FactoryOnly_20250701.bin) | ESP32-S3-Touch-LCD-7B (触摸版) | 2025-07-01 | `0x0` |
| [ESP32-S3-LCD-7B_FactoryOnly_20250623.bin](ESP32-S3-LCD-7B_FactoryOnly_20250623.bin) | ESP32-S3-LCD-7B (非触摸版) | 2025-06-23 | `0x0` |

将 `PORT` 替换为实际串口，只运行对应型号的命令。

```sh
esptool --chip esp32s3 --port PORT write-flash 0x0 ESP32-S3-Touch-LCD-7B_FactoryOnly_20250701.bin
esptool --chip esp32s3 --port PORT write-flash 0x0 ESP32-S3-LCD-7B_FactoryOnly_20250623.bin
```
