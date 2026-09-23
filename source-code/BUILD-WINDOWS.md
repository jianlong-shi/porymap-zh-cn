# Windows 构建说明

源码来自 Porymap 6.3.1。已修改：

- `porymap.pro`：目标名设为 `porymap-cn`，并登记简体中文 Qt 翻译表。
- `src/main.cpp`：启动时加载同目录的 `porymap_zh_CN.qm`。
- `translations/porymap_zh_CN.ts`：简体中文界面词条。

使用 MSYS2 UCRT64 的 MinGW 与 Qt 6 开发包（Core、Gui、Widgets、Charts、Network、Qml、OpenGL、OpenGLWidgets、Svg），在本目录运行：

```sh
qmake porymap.pro -spec win32-g++
make -j4
lrelease translations/porymap_zh_CN.ts -qm porymap_zh_CN.qm
```

发布 Windows 运行包时，将 `release/porymap-cn.exe` 和 `porymap_zh_CN.qm` 放到 `zh_CN` 目录，并一并部署 Qt 6、MinGW UCRT64 及其传递依赖。不要覆盖原有 `porymap.exe`。
