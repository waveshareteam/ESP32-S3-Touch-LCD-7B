| Supported Targets | ESP32-S3 |
| ----------------- | -------- |

# 13_LVGL_TRANSPLANT

## 功能说明

本示例演示 LVGL 移植结果。程序完成 LCD、触摸和 LVGL 端口初始化后，默认运行 `lv_demo_widgets()` 官方示例界面。

## 前置条件

- 开发板：微雪 `ESP32-S3-Touch-LCD-7B`
- 已完成 ESP-IDF 开发环境配置

## 可修改项

如需切换为其他 LVGL 官方示例，可修改 `main/main.c` 中的演示函数，例如：

- `lv_demo_stress()`
- `lv_demo_benchmark()`
- `lv_demo_music()`
- `lv_demo_widgets()`

## 构建与烧录

1. 在当前目录执行 `idf.py set-target esp32s3`
2. 执行 `idf.py -p PORT flash monitor`

## 运行现象

- 屏幕显示 LVGL 官方 Widgets 演示界面
- 触摸屏可直接操作界面中的控件

## 参考

- ESP-IDF 入门说明：<https://docs.espressif.com/projects/esp-idf/en/latest/esp32s3/get-started/>
- LVGL 文档：<https://docs.lvgl.io/>
