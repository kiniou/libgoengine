#ifndef _Manager_SYSTEM_H
#define _Manager_SYSTEM_H

#include <nds.h>
#include <nds/ipc.h>
#include <nds/timers.h>
#include <nds/system.h>


class Manager_System
{
    public:

        int32 * millisec;
        int32 last_millisec;

        Manager_System();
        ~Manager_System();

        void init_DS();

        void init_timer(void xp_fct_timer(), int32 * xp_millisec);

        void reset_timer();
        int32 get_millisec();
};



#endif // _Manager_SYSTEM_H
