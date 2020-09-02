#include <windows.h>
#include <tchar.h>
#include <stdio.h>
#include <iostream>

wchar_t* getPCname() {
    wchar_t buffer[256];
    unsigned long size = 256;
    GetComputerName(buffer, &size);
    return buffer;
}

int main() {
    HW_PROFILE_INFO hwProfileInfo;
    if (GetCurrentHwProfile(&hwProfileInfo)) {
        std::wstring pcid = getPCname();
        std::wstring hwid = hwProfileInfo.szHwProfileGuid;
        std::wcout << "Current PC name: " << pcid << std::endl << "Current hardware profile: " << hwid << std::endl;
    } else {
        std::cout << "unknown error" << std::endl;
    }
    std::cin.get();
}
