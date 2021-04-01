//TODO:Clean regedit
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
int main()
{
	cout << "------------------------------------------------\n"
			"             Babonock.A Fixer v4.4\n" 
			"           Copyright 2020-2021 by NFLSCode.\n"
			"              All rights reserved.\n"
			"------------------------------------------------"<<endl;
    freopen("Fixer.log","w",stdout);
    computer();
    udisk();
    return 0;
}
void computer()
{
//    if (FilePathExists("%APPDATA%\\Microsoft\\Office\\rundll.exe"))
//    {
        cout<<"Virus found in the drive.\n";
        system("chdir /D %APPDATA%\\Microsoft\\Office"
        	   "&del mspoint.pip"
        	   "&attrib -h -s rundll32.exe"
        	   "&taskkill /f /im rundll32.exe /t" 
               "&del rundll32.exe");
        cout<<"Virus fixed.\n";
//    }
//    else cout<<"Virus not found in the drive.\n";
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
           	system(("del \"" + ss + ".exe\"").c_str());
        }
    }
    closedir(dir);
    system("attrib /s /d +h +s \"System Volume Information\"");
    cout<<"The removable drive is fixed.";
}
