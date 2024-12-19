/**
 * \brief PlatformTypes.h: for arm 64 bit systems
 */
#ifndef PLATFORM_TYPES_H_
#define PLATFORM_TYPES_H_

#include <cstdint>
#include <cinttypes>
#include <limits>

#ifdef  __cplusplus
extern "C" {
#endif

#define FW_HAS_64_BIT    1 //!< Architecture supports 64 bit integers
#define FW_HAS_32_BIT    1 //!< Architecture supports 32 bit integers
#define FW_HAS_16_BIT    1 //!< Architecture supports 16 bit integers
#define FW_HAS_F64    1 //!< Architecture supports 64 bit floating point numbers

typedef int32_t PlatformIntType;
#define PRI_PlatformIntType "ld"

typedef uint32_t PlatformUIntType;
#define PRI_PlatformUIntType "lu"

typedef PlatformIntType PlatformIndexType;
#define PRI_PlatformIndexType PRI_PlatformIntType

typedef PlatformUIntType PlatformSizeType;
#define PRI_PlatformSizeType PRI_PlatformUIntType

typedef PlatformIntType PlatformSignedSizeType;
#define PRI_PlatformSignedSizeType PRI_PlatformSignedSizeType

typedef PlatformIntType PlatformAssertArgType;
#define PRI_PlatformAssertArgType PRI_PlatformIntType

typedef PlatformIntType PlatformTaskPriorityType;
#define PRI_PlatformTaskPriorityType PRI_PlatformIntType

typedef PlatformIntType PlatformQueuePriorityType;
#define PRI_PlatformQueuePriorityType PRI_PlatformIntType

#ifndef PLATFORM_POINTER_CAST_TYPE_DEFINED
  // Check for __SIZEOF_POINTER__ or cause error
  #ifndef __SIZEOF_POINTER__
    #error "Compiler does not support __SIZEOF_POINTER__, cannot use Linux/Darwin types"
  #endif

  // Pointer sizes are determined by size of compiler
  #if __SIZEOF_POINTER__ == 8
    typedef uint64_t PlatformPointerCastType;
    #define PRI_PlatformPointerCastType PRIx64
  #elif __SIZEOF_POINTER__ == 4
    typedef uint32_t PlatformPointerCastType;
    #define PRI_PlatformPointerCastType PRIx32
  #elif __SIZEOF_POINTER__ == 2
    typedef uint16_t PlatformPointerCastType;
    #define PRI_PlatformPointerCastType PRIx16
  #else
    typedef uint8_t PlatformPointerCastType;
    #define PRI_PlatformPointerCastType PRIx8
  #endif
#endif

#ifdef  __cplusplus
}
#endif

#endif //PLATFORM_TYPES_H_