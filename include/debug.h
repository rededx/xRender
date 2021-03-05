#ifndef XRENDER_INCLUDE_DEBUG_MODE_H_
#define XRENDER_INCLUDE_DEBUG_MODE_H_

#ifdef _DEBUG
#define DEBUG(x)        \
  std::cerr << "#debug" \
            << ": " x << "\n"
#else
#define DEBUG(x) \
  do {           \
  } while (0)
#endif  // _DEBUG

#endif  // XRENDER_INCLUDE_DEBUG_MODE_H_