#ifndef _DBJ_INC_COMMON_
#define _DBJ_INC_COMMON_

// MSVC STD LIB aka STL
// _ITERATOR_DEBUG_LEVEL 2 is the DEBUG build default
// and that will produce segv with dbj stack alocator 
// that was not tested with stack allocator I suppose?
// https://docs.microsoft.com/en-us/cpp/standard-library/iterator-debug-level?view=vs-2019

#if (_ITERATOR_DEBUG_LEVEL != 0)
#undef _ITERATOR_DEBUG_LEVEL
#define _ITERATOR_DEBUG_LEVEL  0
#endif

#include <future>
#include <iomanip>
#include <crtdbg.h>
#include <string_view>

#include "nanolib/dbj++tu.h"

#include "../jzon.h"
#include "../jzon_utils.h"

#endif // _DBJ_INC_COMMON_
