import os
import sys
import pathlib
from ctypes import *
WORD = c_ushort
DWORD = c_ulong
LPBYTE = POINTER(c_ubyte)
LPTSTR = POINTER(c_char)
HANDLE = c_void_p
DEBUG_PROCESS = 0x00000001
class STARTUPINFO(Structure):
        _fields_ = [
        ("cb", DWORD),
        ("lpReserved", LPTSTR),
        ("lpDesktop", LPTSTR),
        ("lpTitle", LPTSTR),
        ("dwX", DWORD),
        ("dwY", DWORD),
        ("dwXSize", DWORD),
        ("dwYSize", DWORD),
        ("dwXCountChars", DWORD),
        ("dwYCountChars", DWORD),
        ("dwFillAttribute",DWORD),
        ("dwFlags", DWORD),
        ("wShowWindow", WORD),
        ("cbReserved2", WORD),
        ("lpReserved2", LPBYTE),
        ("hStdInput", HANDLE),
        ("hStdOutput", HANDLE),
        ("hStdError", HANDLE),
        ]
class PROCESS_INFORMATION(Structure):
        _fields_ = [
        ("hProcess", HANDLE),
        ("hThread", HANDLE),
        ("dwProcessId", DWORD),
        ("dwThreadId", DWORD),
        ]
def Main():
    import ctypes as ct
    startupinfo = STARTUPINFO()
    processinfo = PROCESS_INFORMATION()
    ctypes_createprocess = ct.WinDLL("Kernel32")
    processinfo = PROCESS_INFORMATION()
    startupinfo.dwFlags = 0x1
    startupinfo.wShowWindow = 0x0
    startupinfo.cb = sizeof(startupinfo)
    currentpath = os.getcwd()
    if ctypes_createprocess.CreateProcessA(bytes(currentpath + "\\JUMP_FORCE\\Binaries\\Win64\\JUMP_FORCE-Win64-Shipping.exe", "UTF-8"), None, None, None, None, 0, None, None, byref(startupinfo), byref(processinfo)):
       print("[+] Process Created!!!")
    else:
        print("[-] Failed!!!")

if __name__ == "__main__":
    Main()