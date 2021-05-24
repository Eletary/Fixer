#include <bits/stdc++.h>
#include <dirent.h>
#include <windows.h>
using namespace std;
BOOL FindFirstFileExists(LPCTSTR lpPath, DWORD dwFilter)
{
    WIN32_FIND_DATA fd;
    HANDLE hFind = FindFirstFile(lpPath, &fd);
    BOOL bFilter = (FALSE == dwFilter) ? TRUE : fd.dwFileAttributes & dwFilter;
    BOOL RetValue = ((hFind != INVALID_HANDLE_VALUE) && bFilter) ? TRUE : FALSE;
    FindClose(hFind);
    return RetValue;
}
BOOL FilePathExists(LPCTSTR lpPath)
{
    return FindFirstFileExists(lpPath, FALSE);
}
bool IsFolder(const char* tempPath)
{
	WIN32_FIND_DATAA FindFileData;
    FindFirstFileA((LPCSTR)tempPath,&FindFileData);
    if(FindFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
        return true;
    else
        return false;
}
void computer();
void udisk();
void reg();
int main()
{
	cout << "------------------------------------------------\n"
			"             	Babonock.A Fixer\n" 
			"           Copyright 2020-2021 by NFLSCode.\n"
			"              All rights reserved.\n"
			"------------------------------------------------"<<endl;
    freopen("Fixer.log","w",stdout);
    computer();
    udisk();
    reg();
    return 0;
}
void reg()
{
	system("reg delete HKCU\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run /v \"Microsoft Windows\" /f"); 
}
void computer()
{
    system( "chdir /D %APPDATA%\\Microsoft\\Office"
        	"&del /f /q mspoint.pip"
        	"&attrib -h -s rundll32.exe"
        	"&taskkill /f /im rundll32.exe /t" 
            "&del /f /q rundll32.exe");
    cout<<"Virus in fixed drive fixed(qwq)\n";
}
void udisk()
{
    if (!FilePathExists("System Volume Information.exe"))
    {
       cout<<"Not in a removable dirve (root) or no virus found.\n";
       return;
    }
    cout<<"Fixing the removable drive...\n";
    DIR *dir;
    dirent *ptr;
    dir = opendir(".");
    while ((ptr = readdir(dir)) != NULL)
    {
        string ss = ptr->d_name;
        if (IsFolder(ss.c_str()))
        {
        	if (ss=="."/*||ss=="System Volume Information.exe"*/) continue;
            system(("attrib /s /d -h -s \"" + ss + "\"").c_str());
           	system(("del /f /q \"" + ss + ".exe\"").c_str());
        }
    }
    closedir(dir);
    system("attrib /s /d +h +s \"System Volume Information\"");
    cout<<"The removable drive is fixed.";
}
