//#include <Vcl.h>
#pragma hdrstop
#include "Winfs.h"

//#include <SysUtils.hpp>
#include <stdio.h>

#if !defined(NO_GLOBAL_INSTANCES) && !defined(NO_GLOBAL_SPIFFS)
fs::FS WinFS;
#endif

AnsiString BaseDir;

using namespace fs;

//------------------------------------------------------------------------------
bool FS::begin()
{
    BaseDir = GetCurrentDir() + "..\\..\\..\\filesystem\\";
    MkDir(BaseDir);
    return true;
}
//------------------------------------------------------------------------------
bool FS::exists(const char* path)
{
    auto fp = BaseDir + path;
    return FileExists(fp);
}
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
WinFile FS::open(const char* path, const char* mode)
{
    auto fp = BaseDir + path;
    std::FILE* f = fopen(fp.c_str(), mode);
    WinFile wf(f);
    return wf;
}

//------------------------------------------------------------------------------
size_t WinFile::read(uint8_t* buf, size_t size)
{
   if(!_file)
    return 0;

    return fread(buf,size,1, _file );
}
//------------------------------------------------------------------------------
void WinFile::close()
{
   if(!_file)
    return;

    fclose(_file);
    _file = nullptr;
}
//------------------------------------------------------------------------------
size_t WinFile::write(const uint8_t *buf, size_t size)
{
    if(!_file)
        return 0;

    return fwrite(buf, size,1, _file );
}
//------------------------------------------------------------------------------
size_t WinFile::write(uint8_t ch)
{
    return write( &ch, 1);
}
//------------------------------------------------------------------------------
int WinFile::read()
{
    if(!_file)
        return -1;

    return fgetc(_file);
}
//------------------------------------------------------------------------------
int WinFile::peek()
{
    if(!_file)
        return -1;

    auto ch = fgetc(_file);
    ungetc(ch, _file);

    return ch;
}
//------------------------------------------------------------------------------
void WinFile::flush()
{
    if(!_file)
        return;

    fflush(_file);
}
//------------------------------------------------------------------------------

