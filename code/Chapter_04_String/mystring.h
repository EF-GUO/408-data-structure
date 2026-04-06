#pragma once

const int MAXLEN = 255;
struct SString
{
    char ch[MAXLEN];
    int length;
};

struct HString
{
    char *ch = nullptr;
    int length;
};