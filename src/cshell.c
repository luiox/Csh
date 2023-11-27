#include <cshell.h>
#include <string.h>

/*
 * If it is initialized ,then set to true.
 */
static bool cshell_initialize_flag = false;

static cshell_getc_pf cshell_getc_func;

static cshell_getc_pf cshell_putc_func;

// Initialize the corresponding IO interface
bool
cshell_initialize_cfg(CShellCfg * cfg)
{
    if (NULL == cfg)
        return false;
    if (NULL == cfg->getc_pf)
        return false;
    if (NULL == cfg->putc_pf)
        return false;
    cshell_getc_func = cfg->getc_pf;
    cshell_putc_func = cfg->putc_pf;
    return true;
}

void
cshell_readline(int8_t * buf, uint32_t maxlen)
{
    if (!cshell_initialize_flag)
        return;

    int i = 0;
    do {
        int8_t ch = cshell_getc_func();
        buf[i] = ch;
    } while (buf[i] != '\n' && i < maxlen);
}

// Perform initialization work.
void
cshell_init()
{
    // Now is nothing to do.
}

void
cshell_dispatch(int8_t * buf)
{
    
}

void
cshell_start()
{
    int8_t buf[CSHELL_CMDLINE_MAX_BUFFER_SIZE] = { 0 };
    cshell_init();
    while (true) {
        cshell_readline(buf, CSHELL_CMDLINE_MAX_BUFFER_SIZE);
        cshell_dispatch(buf);
        memset(buf, 0, CSHELL_CMDLINE_MAX_BUFFER_SIZE);
    }
}
