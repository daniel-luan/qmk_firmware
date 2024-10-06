#pragma once
#include_next <mcuconf.h>

#undef  RP_SIO_USE_UART0
#undef  RP_SIO_USE_UART1

#define RP_SIO_USE_UART0          FALSE
#define RP_SIO_USE_UART1          TRUE
