# Demo: Use yalantinglibs Git Submodule

Thanks to [@piperoc](https://github.com/piperoc)

**Step 1**: create your project directory mkdir `~/code/awesome-solution` and cd `~/code/awesome-solution`.

**Step 2**: make it a git repo by calling `git init` (this will initialize and empty git repo)

**Step 3**: add the library as a ***true submodule*** with  `git submodule add https://github.com/alibaba/yalantinglibs.git` .
At this point you should have a file system structure like:

```
awesome-solution
├── .git
├── .gitmodules
└── yalantinglibs
```


**Step 4**: there are often more than one project using the library in the solution. In our demo, there would be a client app and a server app that both use the library. Those apps would be separate projects, so the file system will start looking like:


```
awesome-solution
├── CMakeLists.txt
├── client
│   ├── CMakeLists.txt
│   ├── client.cpp
│   ├── service.h
├─── server
│    ├── CMakeLists.txt
│    ├── server.cpp
│    ├── service.h
└─── yalantinglibs
```

**Step 5**: here's the root CMakeLists.txt (it's very important to set the compiler flags as I'm running g++ 10.3.0)


```cmake

cmake_minimum_required(VERSION 3.15)

project(awesome-solution)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fcoroutines")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(client)
add_subdirectory(server)
add_subdirectory(yalantinglibs)
```
