
#ifndef AMB_INCLUDE_AMB_API_H_
#define AMB_INCLUDE_AMB_API_H_


#if defined _WIN32 // if Windows
  #ifdef BUILDING_DLL
    #define DLL_PUBLIC __declspec(dllexport)
  #else
    #define DLL_PUBLIC __declspec(dllimport)
  #endif
  #define DLL_LOCAL
#else  // if Linux
  #if __GNUC__ >= 4
    #define DLL_PUBLIC __attribute__ ((visibility ("default")))
    #define DLL_LOCAL  __attribute__ ((visibility ("hidden")))
  #else
    #define DLL_PUBLIC
    #define DLL_LOCAL
  #endif
#endif








// Generic helper definitions for shared library support
#if defined _WIN32 || defined __CYGWIN__
  #define AMB_DLL_IMPORT __declspec(dllimport)
  #define AMB_DLL_EXPORT __declspec(dllexport)
  #define AMB_DLL_LOCAL
#else
  #if __GNUC__ >= 4
    #define AMB_DLL_IMPORT __attribute__ ((visibility ("default")))
    #define AMB_DLL_EXPORT __attribute__ ((visibility ("default")))
    #define AMB_DLL_LOCAL  __attribute__ ((visibility ("hidden")))
  #else
    #define AMB_DLL_IMPORT
    #define AMB_DLL_EXPORT
    #define AMB_DLL_LOCAL
  #endif
#endif

// In the header file:
//#ifdef MY_MODULE_MAIN
//  #define   AMBAPI   AMB_DLL_EXPORT
//#else
//  #define   AMBAPI   AMB_DLL_IMPORT
//#endif
//#define     AMBLOCAL AMB_DLL_LOCAL
//
// AMBAPI MyMod* creatorMethod();
// AMBLOCAL void priv_helper();

// In the module file
//#define MY_MODULE_MAIN
//#include "my_module.h"
//
//AMBAPI MyMod* creatorMethod() {
//  priv_helper();
//  return new MyMod();
//}
//
//AMBLOCAL priv_helper() {
//  std::cout << "can't touch this" << std::endl;
//}

