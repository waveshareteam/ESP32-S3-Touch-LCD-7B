# Factory firmware

| File | Use | Flash offset |
| --- | --- | --- |
| [ESP32-S3-Touch-LCD-7B_FactoryOnly_20250701.bin](ESP32-S3-Touch-LCD-7B_FactoryOnly_20250701.bin) | Factory test firmware for ESP32-S3-Touch-LCD-7B (16 MB Flash) | `0x0` |

From this directory, connect the board in download mode and run:

```sh
python -m esptool --chip esp32s3 write-flash 0x0 ESP32-S3-Touch-LCD-7B_FactoryOnly_20250701.bin
```
