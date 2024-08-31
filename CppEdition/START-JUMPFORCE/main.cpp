#include <Windows.h>
#include <iostream>
#include <filesystem>
using namespace std;
namespace fs = std::filesystem;

int main() 
{
	std::wstring fspath = fs::current_path();
	STARTUPINFOW info = { sizeof(info) };
	PROCESS_INFORMATION processInfo;
	ZeroMemory(&info, sizeof(info));
	info.cb = sizeof(info);
	ZeroMemory(&processInfo, sizeof(processInfo));
	std::wstring path_p = fspath + L"\\JUMP_FORCE\\Binaries\\Win64\\JUMP_FORCE-Win64-Shipping.exe";
	std::wstring eacload_disable = L"-eac-nop-loaded";
	if ((CreateProcessW((LPCWSTR)path_p.c_str(), (LPWSTR)eacload_disable.c_str(), NULL, NULL, FALSE, 0, NULL, NULL, &info, &processInfo)))
	{
		cout << "Process Created!!!" << endl;
		exit(343);
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
