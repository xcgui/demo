@echo off
@echo 请将文件 Flash32_11_7_700_224.ocx 复制到 C:\Windows\SysWow64\ 并且用管理员权限运行这个注册bat

regsvr32 C:\Windows\SysWow64\Flash32_11_7_700_224.ocx
rem regsvr32 C:\Windows\SysWow64\Flash32_11_7_700_224.ocx /u