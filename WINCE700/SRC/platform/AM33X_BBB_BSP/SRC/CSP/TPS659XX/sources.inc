# All rights reserved ADENEO EMBEDDED 2010
_TPS659XX=tps659xx
TARGETTYPE=LIBRARY
WARNLEVEL=4

CDEFINES=$(CDEFINES) -DCEDDK_USEDDKMACRO -D_WINCEOSVER=$(_WINCEOSVER)

INCLUDES=$(INCLUDES);$(_TARGETPLATROOT)\src\CSP\COMMON_TI\inc
INCLUDES=$(INCLUDES);$(_TARGETPLATROOT)\src\CSP\TRITON\inc
INCLUDES=$(INCLUDES);$(_TARGETPLATROOT)\src\CSP\TPS659XX\inc