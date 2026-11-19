# Factory firmware

Select the merged BIN for your hardware model and flash it at `0x0`. Both models use ESP32-S3 and 16 MB of flash.

| File | Hardware model | Version date | Flash offset |
| --- | --- | --- | --- |
| [ESP32-S3-Touch-LCD-7B_FactoryOnly_20250701.bin](ESP32-S3-Touch-LCD-7B_FactoryOnly_20250701.bin) | ESP32-S3-Touch-LCD-7B (with touch) | 2025-07-01 | `0x0` |
| [ESP32-S3-LCD-7B_FactoryOnly_20250623.bin](ESP32-S3-LCD-7B_FactoryOnly_20250623.bin) | ESP32-S3-LCD-7B (without touch) | 2025-06-23 | `0x0` |

Replace `PORT` with your serial port and run the command for your model.

```sh
esptool --chip esp32s3 --port PORT write-flash 0x0 ESP32-S3-Touch-LCD-7B_FactoryOnly_20250701.bin
esptool --chip esp32s3 --port PORT write-flash 0x0 ESP32-S3-LCD-7B_FactoryOnly_20250623.bin
```
