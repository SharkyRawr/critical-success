#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <wchar.h>
#include <time.h>

#define WIN32
#ifdef WIN32
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#endif

#include "mt19937.h"
#include "messages.h"

wchar_t * pick_random_msg(wchar_t ** msgs, unsigned int nummsgs) {
    int rng = genrand_int32() % nummsgs;
    return msgs[rng];
}

void ShowRandomMessage() {
    init_genrand(time(NULL));

    wchar_t *msg = pick_random_msg((wchar_t**)success_msgs, success_msgs_len);

    HWND wnd = GetForegroundWindow();
    MessageBoxEx(wnd, msg, L"Critical Success!", MB_OK|MB_ICONERROR, MAKELANGID(LANG_ENGLISH, SUBLANG_NEUTRAL));
}


#ifdef WIN32
    int WINAPI WinMain (HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
    {
        ShowRandomMessage();
    }
#else
    int main(int argc, char** argv)
    {
        ShowRandomMessage();
        return 0;
    }
#endif


