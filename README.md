# Porymap 6.3.1 简体中文独立包

这是可叠加安装的 Windows x64 简体中文版本。它在 `zh_CN` 子目录中提供单独编译的 Porymap 和所需运行库；现有的 `porymap.exe` 不会被覆盖。

## 安装和启动

下载同目录的 `Porymap-6.3.1-简体中文包.zip`，将压缩包内容解压到已有 `porymap.exe` 的 Porymap 文件夹中，然后运行 `启动简体中文版.cmd`。压缩包根目录包含 `zh_CN` 文件夹、启动脚本、安装说明和许可证。

在 SeaBreezeGBA 项目内也可以直接运行项目根目录的 `打开中文地图编辑器.cmd`，它会从游戏的 `source` 目录启动编辑器。

原版和中文版可以并排使用。卸载时删除新增的 `zh_CN` 文件夹及启动脚本即可。本包不包含游戏工程、ROM、地图或 Pokémon 素材。

## 版本与翻译

基于上游 Porymap 6.3.1（Windows x64）。712 条界面词条中，698 条已编译进中文翻译文件；其余是标点或数值类文本，由原版界面直接显示。地图、图块集、事件、碰撞、快捷键及运行时占位符已统一检查。

上游项目：[huderlem/porymap](https://github.com/huderlem/porymap)，标签 `6.3.1`，提交 `139eda92b3b06a5fd675a9825a07ac62e98c1566`。

## 源码构建

编译所需的上游源码及修改后的 `porymap.pro`、`src/main.cpp` 和 `translations/porymap_zh_CN.ts` 位于 `source-code`。为控制下载体积，源码目录省略了上游手册网站和 GIF 示例；上游手册可在项目仓库查看。使用带 Qt 6 的 MSYS2 UCRT64 MinGW 环境，在 `source-code` 目录执行：

```sh
qmake porymap.pro -spec win32-g++
make -j4
lrelease translations/porymap_zh_CN.ts -qm porymap_zh_CN.qm
```

将生成的 `porymap_zh_CN.qm` 放在 `porymap-cn.exe` 旁即可加载翻译。当前压缩包已包含编译好的运行库，无需安装 MSYS2 或 Qt。

## 许可证

Porymap 源码按 LGPL-3.0-or-later 授权。Qt 和随包的 MinGW/第三方运行库使用各自的许可证；对应文本和通知位于 `LICENSES`。上游许可证也保留在 `source-code/LICENSE.md`。

