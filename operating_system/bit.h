#pragma once

#if defined(_M_ARM)

#define ARM
#define OS32BIT
#define OSBIT 32


#elif defined(_M_ARM64)

#define ARM64
#define OS64BIT
#define OSBIT 64


#elif defined(_M_X64)  // X64


#define AMD64
#define OS64BIT
#define OSBIT 64


#elif defined(_M_IX86)


#define _X86_
#define OS32BIT
#define OSBIT 32


#endif











