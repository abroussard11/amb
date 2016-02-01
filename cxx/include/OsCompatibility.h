/**
 * A Compatibility header
 */
#ifndef AMB_OSCOMPATIBILITY_
#define AMB_OSCOMPATIBILITY_

#ifdef WIN32
#define dllExport __declspec(dllexport)
#define dllImport __declspec(dllimport)
#else
#define dllExport
#define dllImport
#endif

#endif  // AMB_OSCOMPATIBILITY_
