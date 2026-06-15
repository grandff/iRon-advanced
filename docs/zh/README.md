<div align="center">

<h1>iRon-Advanced</h1>
轻量且功能强大的 iRacing 扩展叠加层 (Overlay)<br><br>

[**English**](../../README.md) | [**English (UK)**](../en-GB/README.md) | [**한국어**](../ko/README.md) | [**日本語**](../ja/README.md) | **简体中文** | [**Deutsch**](../de/README.md) | [**Français**](../fr/README.md) | [**Italiano**](../it/README.md) | [**Português**](../pt/README.md) | [**Русский**](../ru/README.md)

</div>

---

该项目是原版 `iRon` 叠加层 (Overlay) 的重度扩展版本。在保留原项目核心设计理念（极其轻量、且无外部运行时依赖）的同时，它为 iRacing 玩家增添了强大且必不可少的实用功能。

> **基于原版 iRon 项目（作者：lespalt）：** [https://github.com/lespalt/iRon](https://github.com/lespalt/iRon)

<br>

### ✨ 与原版 iRon 有何不同？

**1. 💾 全局布局自动保存**
* 原版 iRon 每次重启应用程序时窗口位置都会被重置。
* **iRon-Advanced** 会将您的屏幕坐标布局、窗口大小以及叠加层开关状态（开/关）保存到 Windows 的 `Documents\iRon_Advanced\config.json` 路径中。重新启动时，上一次的布局将被完美恢复！

**2. 📊 增强版排名与遥测 (Standings & Telemetry)**
* 在 Standings 叠加层中的车手姓名旁添加了 **3 位国家/地区缩写徽章**（例如 `[KOR]`、`[USA]`），以便快速识别对手的国籍。
* 清理了冗余的车模文本，呈现出极其专业、整洁的视觉效果。
* 在 Relative 叠加层中，直接引入了基于 Elo 评级系统计算的**实时预期 iRating 变化 (+/-)**。

**3. 🚀 全新加入的叠加层：**
* **左右视觉辅助观察员 (Spotter) (全新)：** 盲区的视觉警示。左侧和右侧面板是分离的，可以独立拖动和调整大小！它们会根据您身旁车辆的实际临近距离闪烁**黄色**或**红色**，在安全时保持 100% 透明。
* **雷达 (Proximity Radar) (全新)：** 俯视视角的临近车辆雷达，在周围没有车辆时保持完全透明，以避免干扰视线。
* **事故警示 (Smart Incident) (全新)：** 对前方 150 米以内的事故进行闪烁的警示横幅提示并显示精确距离。
* **交通状况 (Multiclass Traffic) (全新)：** 当后方有更快的组别车辆逼近时，根据圈速步幅差异动态显示的蓝旗 UI。

---

# 目录

- [下载地址](#-下载地址)
- [叠加层 (Overlays)](#-叠加层-overlays)
  - [*Relative (相对位置)*](#relative-相对位置)
  - [*DDU (仪表盘)*](#ddu-仪表盘)
  - [*Inputs (输入曲线)*](#inputs-输入曲线)
  - [*Standings (排名)*](#standings-排名)
  - [*Cover (遮挡板)*](#cover-遮挡板)
  - [*Spotter (辅助观察员) (全新)*](#spotter-辅助观察员-全新)
  - [*Radar (雷达) (全新)*](#radar-雷达-全新)
  - [*Incident Warning (事故警示) (全新)*](#incident-warning-事故警示-全新)
  - [*Multiclass Traffic (多组别交通状况) (全新)*](#multiclass-traffic-多组别交通状况-全新)
  - [*Head to Head (单挑对决) (全新)*](#head-to-head-单挑对决-全新)
  - [*Bomb Avenge (复仇追踪) (全新)*](#bomb-avenge-复仇追踪-全新)
- [安装与运行](#-安装与运行)
- [配置说明](#️-配置说明)
- [从源码构建](#️-从源码构建)
- [依赖项](#-依赖项)

---

## 📥 下载地址

您可以在[此处](https://github.com/lespalt/iRon/releases/latest)找到最新的二进制发布版本。

<br>

## 📺 叠加层 (Overlays)

### *Relative (相对位置)*
类似于 iRacing 中的 *Relative* 窗口，但提供了额外的信息，例如安全等级 (License)、iRating、自上次进站以来行驶的圈数，以及当前组别参赛者的**实时预期 iRating 变化**。您还可以通过将好友的名字添加到好友列表中来高亮显示他们。
顶部是一个可选的迷你地图。它可以设置为相对模式（自身车辆固定在中心）或绝对模式（起跑/终点线固定在中心）。

![relative](https://github.com/lespalt/iRon/blob/main/relative.png?raw=true)

### *DDU (仪表盘)*
一个集中了各种重要信息的仪表盘，否则您必须在 iRacing 中翻阅多个不同的窗口。
燃油计算器显示预计剩余圈数、剩余燃油量、预计每圈燃油消耗量、完成比赛预计所需的_额外_燃油量，以及计划在下一次进站时加注的燃油量。

![ddu](https://github.com/lespalt/iRon/blob/main/ddu.png?raw=true)

### *Inputs (输入曲线)*
通过动态图表显示油门/刹车/转向输入。对于练习稳定的循迹刹车 (Trail Braking) 极其有用。

![inputs](https://github.com/lespalt/iRon/blob/main/inputs.png?raw=true)

### *Standings (排名)*
显示全场的排名信息，包括安全等级 (Safety Rating)、iRating、自上次进站以来的圈数（“进站时龄”），以及每个车手姓名左侧简洁的**国家/地区缩写徽章**。主要在全场黄旗 (Caution) 期间或赛前使用，以了解竞争对手的水平。

![standings](https://github.com/lespalt/iRon/blob/main/standings.png?raw=true)

### *Cover (遮挡板)*
该功能省去截图。它只是一个简单的空白黑色矩形，可用于遮挡游戏中分散注意力的仪表盘（例如 Next-Gen NASCAR 中的仪表盘）。

### *Spotter (辅助观察员) (全新)*
一个视觉辅助观察员，当有车辆处于您的盲区时，会在屏幕的左侧和右侧绘制彩色矩形。
* 左侧和右侧面板是**独立配置、移动和调整大小**的。
* 当有邻车靠近时显示**黄色**警告条，如果车辆危险地逼近（<= 2.2米），则转为醒目的**红色**警示条。
* 默认情况下完全透明，仅在启用布局编辑时显示为半透明。

![spotter](../../screenshot_placeholder_spotter.png)

### *Radar (雷达) (全新)*
一个临近雷达，渲染您周围车辆的俯视视图。
* 默认情况下，当周围没有车辆时保持 100% 透明，以保持屏幕清晰。
* 一旦周围车辆进入近距离范围，就会激活并渲染周围车辆的俯视视图。

![radar](../../screenshot_placeholder_radar.png)

### *Incident Warning (事故警示) (全新)*
一个智能事故警示系统。该叠加层不仅显示通用的黄旗横幅，还会计算前方车辆在黄旗期间是否偏离了赛道。如果检测到前方 150 米内有撞车或偏离赛道的车辆，它将渲染一个醒目的闪烁警示横幅，并标明与事故发生的距离。

![incident](../../screenshot_placeholder_incident.png)

### *Multiclass Traffic (多组别交通状况) (全新)*
专为多组别赛事设计的动态蓝旗警示系统。它会将周围车辆的预计圈速与您的圈速进行比较。如果更快的组别车辆从后方逼近到临界时间差内，它会触发渐进式发光 UI，强烈闪烁蓝色/白色以向您发出警告，且不会遮挡您的视线。

![traffic](../../screenshot_placeholder_traffic.png)

### *Head to Head (单挑对决) (全新)*
显示与您前后车手之间的实时对比。显示上一圈完成时的位置、姓名、差距、圈速以及分段计时（S1、S2、S3）。
* 对于监控您与直接竞争对手相比在哪里损失或赢得了时间非常有用。
* 自身所在行具有醒目的高亮条显示。

### *Bomb Avenge (复仇追踪) (全新)*
显示撞击您的车手的实时追踪信息。
* 当碰撞导致您的事故积分 (Incident Count) 增加时自动触发。
* 显示肇事车手的姓名、当前比赛位置以及以米为单位的实时距离差距。
* 在 *Relative* 叠加层中，肇事车手所在的行将呈红色脉冲闪烁，其车号背景将变为红色，且其姓名将添加 `[BOMB]` 前缀。

---

## 🚀 安装与运行

该应用程序无需安装。只需将可执行文件 (`.exe`) 复制到您选择的文件夹中即可。

要使用它，只需双击可执行文件。无论是在启动 iRacing 之前还是之后操作都可以。弹出的控制台窗口会显示 iRon 正在运行。一旦您进入 iRacing 中的赛车，叠加层就会显示出来。我们强烈建议在**无边框窗口 (Borderless Window)** 模式下运行 iRacing。

---

## ⚙️ 配置说明

要调整叠加层的位置和大小，请按 **ALT-J**。这将进入布局编辑模式，您可以使用鼠标移动叠加层，并通过拖动其右下角来调整它们的大小。再次按 **ALT-J** 即可返回正常模式。

在运行时，可以使用启动期间显示的快捷键来开启或关闭叠加层。所有快捷键都是可配置的。

您的布局和设置会自动全局保存至：
`Documents\iRon_Advanced\config.json`

### 默认快捷键映射：
* **ALT-J**：移动与调整大小模式（布局编辑）
* **Ctrl-Space**：切换 Standings（排名）
* **Ctrl-1**：切换 DDU（仪表盘）
* **Ctrl-2**：切换 Inputs（踏板曲线图）
* **Ctrl-3**：切换 Relative 窗口
* **Ctrl-4**：切换 Cover（遮挡板）
* **Ctrl-5**：切换 Spotters（左右同步）
* **Ctrl-6**：切换临近雷达 (Proximity Radar)
* **Ctrl-7**：切换事故警示 (Incident Warning)
* **Ctrl-8**：切换轮胎仪表盘 (Tire Dash)
* **Ctrl-9**：切换 Head to Head 小部件
* **Ctrl-0**：切换 Bomb Avenge 小部件
* **Ctrl-Shift-D**：循环切换全局显示模式（仅比赛 / 仅重放 / 均显示）

---

## 🛠️ 从源码构建

本应用使用 Visual Studio 2022 构建。免费版本（Community）应该就足够了，尽管我们尚未验证。项目/解决方案文件应该可以直接使用。取决于您的 Visual Studio 设置，您可能需要安装构建 DirectX 应用程序所需的其他前置条件（静态库）。

---

## 📦 依赖项

除 DirectX 等标准 Windows 组件外，没有其他运行时依赖项。对于大多数（如果不是全部的话）可以运行 iRacing 的系统，这些组件应该已经存在。构建依赖项（最明显的是 iRacing SDK 和 picojson）已保持在最低限度，并已包含在仓库中。
