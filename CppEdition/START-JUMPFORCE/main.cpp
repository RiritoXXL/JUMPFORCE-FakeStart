#include <Windows.h>
#include <iostream>
#include <filesystem>
using namespace std;
namespace fs = std::filesystem;

int main(TCHAR *argv[1]) {
	fs::path fspath = fs::current_path();
	STARTUPINFO info = { sizeof(info) };
	PROCESS_INFORMATION processInfo;
	ZeroMemory(&info, sizeof(info));
	info.cb = sizeof(info);
	ZeroMemory(&processInfo, sizeof(processInfo));
	std::wstring str = fspath.c_str();
	std::string m = "\\JUMP_FORCE\\Binaries\\Win64";
	std::string jumpforcepath = (const char*)str.c_str();
	std::string mn(jumpforcepath+m);
	std::string realpath = mn;
	cout << realpath.c_str() << endl;
	if (CreateProcess((LPCWSTR)"F:\\Games\\JumpForce\\JUMP_FORCE\\Binaries\\Win64\\JUMP_FORCE-Win64-Shipping.exe", NULL, NULL, NULL, FALSE, 0, NULL, NULL, &info, &processInfo)) {
		cout << "Process Created!!!" << endl;
		WaitForSingleObject(processInfo.hProcess, INFINITE); 
		CloseHandle(processInfo.hProcess);
		CloseHandle(processInfo.hThread);
	}
	else {
		cout << "Failed to Create Process!!!" << endl;
	}
	// Wait until child process exits.
	WaitForSingleObject(processInfo.hProcess, INFINITE);

	// Close process and thread handles. 
	CloseHandle(processInfo.hProcess);
	CloseHandle(processInfo.hThread);
	return 0;
}