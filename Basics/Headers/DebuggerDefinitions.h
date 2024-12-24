#ifndef DEBUG_DEFINITION_H
#define DEBUG_DEFINITION_H

// DEBUG_MSG
#if defined(DEBUG) || defined(FAST_DEBUG)
    #define DEBUG_COUT_FUNC(msg) std::cout << "[DEBUG_MSG]: " << msg << std::endl
#else
    #define DEBUG_COUT_FUNC(msg)
#endif

#if defined(DEBUG) || defined(FAST_DEBUG)
    #define DEBUG_COUT_FUNC(msg) std::cout << "[DEBUG_MSG]: " << msg << std::endl
#else
    #define DEBUG_COUT_FUNC(msg)
#endif

// DEBUG_ERR_MSG
#if defined(DEBUG) || defined(FAST_DEBUG)
    #define DEBUG_CERR_FUNC(msg) std::cerr << "[DEBUG_ERR_MSG]: " << msg << std::endl
#else
    #define DEBUG_CERR_FUNC(msg)
#endif

#endif