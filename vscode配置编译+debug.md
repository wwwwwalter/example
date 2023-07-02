## ![image.png](https://cdn.nlark.com/yuque/0/2023/png/250312/1688325395428-2df6f607-12fc-4dc4-b118-664085aaa73f.png#averageHue=%23282727&clientId=u80cb01c8-7080-4&from=paste&height=277&id=u51657343&originHeight=277&originWidth=718&originalType=binary&ratio=1&rotation=0&showTitle=false&size=29133&status=done&style=none&taskId=u786ff5f6-f577-4425-8b5d-5c016784e8e&title=&width=718)
## 
## task.json
```json
{
  // See https://go.microsoft.com/fwlink/?LinkId=733558
  "version": "2.0.0",
  "options": {
    "cwd": "${workspaceFolder}/build"
  },
  "tasks": [
    {
      "label": "cmake -GMinGW Makefiles",
      "type": "shell",
      "command": [
        "cmake"
      ],
      "args": [
        "-GMinGW Makefiles",
        "-DCMAKE_BUILD_TYPE=Release",
        "-DCMAKE_CXX_FLAGS_DEBUG=-O -g",
        ".."
      ]
    },
    {
      "label": "mingw32-make",
      "type": "shell",
      "command": [
        "mingw32-make"
      ], //要把mingw32-make添加到环境path中
      "args": [
        "-j14"
      ]
    },
    {
      "label": "cmake mingw-make(gcc)",
      "dependsOrder": "sequence",
      "dependsOn": [
        "cmake -GMinGW Makefiles",
        "mingw32-make"
      ]
    },
    {
      "label": "cmake -GVisual Studio 17 2022",
      "type": "shell",
      "command": [
        "cmake"
      ],
      "args": [
        "-GVisual Studio 17 2022",
        "-DCMAKE_BUILD_TYPE=Debug",
        ".."
      ]
    },
    {
      "label": "msbuild",
      "type": "shell",
      "command": [
        "cmake"
      ],
      "args": [
        "--build",
        ".",
        "-j14"
      ]
    },
    {
      "label": "cmake msbuild(cl)",
      "dependsOrder": "sequence",
      "dependsOn": [
        "cmake -GVisual Studio 17 2022",
        "msbuild"
      ]
    }
  ]
}
```


## launch.json
```json
{
    // Use IntelliSense to learn about possible attributes.
    // Hover to view descriptions of existing attributes.
    // For more information, visit: https://go.microsoft.com/fwlink/?linkid=830387
    "version": "0.2.0",
    "configurations": [        
        {
            "name": "(Windows) Launch",
            "type": "cppvsdbg",
            "request": "launch",
            "program": "${workspaceFolder}/lib/Debug/outDebug.exe",
            "args": [],
            "stopAtEntry": false,
            "cwd": "${workspaceFolder}/lib/Debug",
            "environment": [],
            "console": "internalConsole",
            "preLaunchTask": "cmake msbuild(cl)"
        },
        {
            "name": "(gdb) Launch",
            "type": "cppdbg",
            "request": "launch",
            "program": "${workspaceFolder}/lib/Debug/outDebug.exe",
            "args": [],
            "stopAtEntry": false,
            "cwd": "${fileDirname}",
            "environment": [],
            "externalConsole": false,
            "MIMode": "gdb",
            "miDebuggerPath": "gdb",
            "setupCommands": [
                {
                    "description": "Enable pretty-printing for gdb",
                    "text": "-enable-pretty-printing",
                    "ignoreFailures": true
                },
                {
                    "description": "Set Disassembly Flavor to Intel",
                    "text": "-gdb-set disassembly-flavor intel",
                    "ignoreFailures": true
                }
            ],
            "preLaunchTask": "cmake mingw-make(gcc)"
        }
    ]
}
```
