/**
 * Function to find the number of cores
 * 
 * adapted from a snippet found here:
 * http://www.cprogramming.com/snippets/source-code/find-the-number-of-cpu-cores-for-windows-mac-or-linux
 *
 * Original-Author: Dirk-Jan Kroon
 */
#include <stdint.h>
#ifdef _WIN32
#include <windows.h>
#elif MACOS
#include <sys/param.h>
#include <sys/sysctl.h>
#else
#include <unistd.h>
#endif

int find_number_of_cores ( void )
{

#ifdef WIN32
    SYSTEM_INFO sysinfo;
    GetSystemInfo(&sysinfo);
    return sysinfo.dwNumberOfProcessors;

#elif MACOS
    int name[2];
    uint32_t count;
    size_t len = 4;

    name[0] = CTL_HW; name[1] = HW_AVAILCPU;
    sysctl(name, 2, &count, &len, NULL, 0);

    if(count < 1) {
        name[1] = HW_NCPU;
        sysctl(name, 2, &count, &len, NULL, 0);
        if(count < 1) { count = 1; }
    }
    return count;

#else
    return sysconf(_SC_NPROCESSORS_ONLN);

#endif

}

