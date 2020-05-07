# Crazy Pong!

[![license](https://img.shields.io/badge/license-MIT-green)](LICENSE)
[![docs](https://img.shields.io/badge/docs-yes-brightgreen)](docs/README.md)

Crazy Pong! is a two player ping pong game that supports a mode of classic ping pong and a mode of "crazy" ping pong. The crazy mode includes several visual distractions intending on confusing a player and sidetracking them from where the real ball actually is. Enjoy playing!

---
**DEPENDENCIES**

This project uses [Cinder](https://libcinder.org/), a creative coding library, as well as [Choreograph](https://github.com/sansumbrella/Choreograph), an animation library to put the "crazy" in **Crazy Pong!**

Cinder Steps:
1. [Download the latest version of Cinder for your platform](https://libcinder.org/download)
    * [Basic tutorial on how to build Cinder projects](https://libcinder.org/docs/guides/tour/hello_cinder_chapter1.html)
    * [Cinder documentation](https://libcinder.org/docs/reference/index.html)
2. Extract the downloaded item into a folder
3. Open this same folder in a modern C++ compiler (CLion, XCode, or Visual Studio Code)
4. Build Cinder

Choreograph Steps:
1. Go to your cinder folder's blocks subdirectory
2. <pre><code>git clone https://github.com/sansumbrella/Choreograph.git</code></pre> into this directory
3. [Follow this guide on building external libraries](https://courses.grainger.illinois.edu/cs126/sp2020/notes/cmake/)
---
**HOW TO PLAY**
| Command-Line Flags | Description                                                                           |
|--------------------|---------------------------------------------------------------------------------------|
| --crazy            | boolean, initiates "crazy" mode (default is set to false, which is classic ping pong) |
| --duration         | int, sets time of the game in minutes                                                 |
| --speed            | int, sets the speed of the ball                                                       |

| Player Commands | up       | down       |
|-----------------|----------|------------|
| Right Player    | up arrow | down arrow |
| Left Player     | w        | s          |


**Author**: Riya Gupta - [`riyag3@illinois.edu`](mailto:riyag3@illinois.edu)
