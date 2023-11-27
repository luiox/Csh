#include <stdio.h>
#include <stdlib.h>
#include <cshell.h>

int main()
{
    CShellCfg cfg={
        .getc_pf = getc,
        .putc_pf = putc
    };
    cshell_initialize(&cfg);
    cshell_start();
    return EXIT_SUCCESS;
}
