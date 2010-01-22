#include <GOEN_Manager_System.h>

Manager_System::Manager_System()
{
    //ctor
}

Manager_System::~Manager_System()
{
    //dtor
}

void Manager_System::init_DS()
{
    powerOn(POWER_ALL);
	//swiWaitForVBlank();
    // IRQ basic setup
    //irqInit();
    //irqSet(IRQ_VBLANK, 0);
}

void Manager_System::init_timer(void xp_fct_timer(), int32 * xp_millisec)
{
    this->last_millisec = 0;
//    TIMER0_CR = 0;
//    TIMER0_DATA = TIMER_FREQ(0x409);
//    TIMER0_CR = TIMER_ENABLE | TIMER_DIV_1 | TIMER_IRQ_REQ;
    this->millisec = xp_millisec;
//    irqSet(IRQ_TIMER0, xp_fct_timer);
//    irqEnable(IRQ_TIMER0);
	timerStart(0,ClockDivider_1,timerFreqToTicks_1(25),xp_fct_timer);
    irqEnable(IRQ_TIMER0);
}


void Manager_System::reset_timer()
{

    if (this->millisec != 0 )
    {
        this->last_millisec = (*this->millisec);
        (*this->millisec) = 0;
    }
}

int32 Manager_System::get_millisec()
{
    return this->last_millisec;
}
