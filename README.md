<div align="left" style="position: relative;">
<img src="https://raw.githubusercontent.com/PKief/vscode-material-icon-theme/ec559a9f6bfd399b82bb44393651661b08aaf7ba/icons/folder-markdown-open.svg" align="right" width="30%" style="margin: -20px 0 0 20px;">
<h1>TIC-TAC-TOE (SFML)</h1>
<p align="left">
	<em>A sleek, high-performance 2D Tic-Tac-Toe implementation built with C++ and SFML.</em>
</p>
<p align="left">
	<img src="https://img.shields.io/github/last-commit/Jaynguyen-dev/Tic-Tac-Toe?style=default&logo=git&logoColor=white&color=ff0024" alt="last-commit">
	<img src="https://img.shields.io/github/languages/top/Jaynguyen-dev/Tic-Tac-Toe?style=default&color=ff0024" alt="repo-top-language">
	<img src="https://img.shields.io/github/languages/count/Jaynguyen-dev/Tic-Tac-Toe?style=default&color=ff0024" alt="repo-language-count">
</p>
</div>
<br clear="right">

## 🔗 Table of Contents

- [📍 Overview](#-overview)
- [👾 Features](#-features)
- [📁 Project Structure](#-project-structure)
  - [📂 Project Index](#-project-index)
- [🚀 Getting Started](#-getting-started)
  - [☑️ Prerequisites](#-prerequisites)
  - [⚙️ Installation](#-installation)
  - [🤖 Usage](#-usage)
  - [🧪 Testing](#-testing)
- [📌 Project Roadmap](#-project-roadmap)
---

## 📍 Overview

This repository contains a desktop-based **Tic-Tac-Toe** game developed using the **C++** programming language and the **Simple and Fast Multimedia Library (SFML)**. The project serves as a practical implementation of 2D game loops, event handling, and basic win-state algorithms within a graphical environment.

---

## 👾 Features

* **Real-time Rendering:** Uses SFML's hardware acceleration for smooth 60 FPS gameplay.
* **Intuitive UI:** Dynamic graphical feedback for Player X and Player O.
* **Win Logic:** Efficient algorithms to detect horizontal, vertical, and diagonal wins.
* **Asset Management:** Integrated font loading for scoreboards and game-over screens.
* **Portable Execution:** Includes all necessary dynamic link libraries (`.dll`) for Windows execution.

---

## 📁 Project Structure

```sh
└── Tic-Tac-Toe/
    ├── Game1.cpp               # Main source code and game loop
    ├── Game1.sln               # Visual Studio Solution file
    ├── Game1.vcxproj           # Visual Studio Project file
    ├── Open_Sans.zip           # Game fonts and UI assets
    ├── openal32.dll            # Audio support library
    ├── sfml-graphics-2.dll     # SFML Graphics module
    ├── sfml-window-2.dll       # SFML Windowing module
    └── sfml-system-2.dll       # SFML System module

```

### 📂 Project Index

<details open>
<summary><b><code>TIC-TAC-TOE</code></b></summary>
<details>
<summary><b>Source & Assets</b></summary>
<blockquote>
<table>
<tr>
<td><b>Game1.cpp</b></td>
<td>Contains the core logic, grid management, and SFML window initialization.</td>
</tr>
<tr>
<td><b>Open_Sans.zip</b></td>
<td>Contains the typography assets required for the graphical interface.</td>
</tr>
<tr>
<td><b>Game1.sln</b></td>
<td>The primary workspace for building and debugging in Visual Studio.</td>
</tr>
</table>
</blockquote>
</details>
</details>

---

## 🚀 Getting Started

### ☑️ Prerequisites

To build or run this project, you need:

* **Windows OS** (required for the provided `.dll` files).
* **Visual Studio 2019 or 2022** with the "Desktop development with C++" workload.
* **SFML SDK** (if you plan to reconfigure build paths).

### ⚙️ Installation

1. **Clone the Repository:**
```sh
git clone [https://github.com/Jaynguyen-dev/Tic-Tac-Toe.git](https://github.com/Jaynguyen-dev/Tic-Tac-Toe.git)
cd Tic-Tac-Toe

```


2. **Extract Assets:**
Unzip `Open_Sans.zip` into the root directory so the application can locate the font files.
3. **Open the Project:**
Double-click `Game1.sln` to open the project in Visual Studio.

### 🤖 Usage

1. Set your build configuration to **Release** and your platform to **x64** (or x86 depending on your SFML config).
2. Press `F5` or click **Start Debugging**.
3. **Gameplay:** Use your mouse to click on the grid squares. The game will automatically alternate between players.

### 🧪 Testing

To verify the game logic:

1. Launch the application.
2. Complete a game to ensure the "Win" or "Draw" screen triggers correctly.
3. Check the console output (if enabled) for event logs and state changes.

---

## 📌 Project Roadmap

* [x] **`Task 1`**: Code the basic logic of a Tic-Tac-Toe game (state management).
* [x] **`Task 2`**: Handle user interface (rendering sprites and text).
* [x] **`Task 3`**: Implementation and comprehensive testing (bug fixing and edge cases).
