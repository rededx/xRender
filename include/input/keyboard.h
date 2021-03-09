#ifndef XRENDER_INCLUDE_INPUT_KEYBOARD_H_
#define XRENDER_INCLUDE_INPUT_KEYBOARD_H_

#include <GLFW/glfw3.h>

namespace xrn {

enum class Keyboard : int {
  // The unknown key
  kUnknown = -1,

  // Printable keys
  kSpace = 32,
  kApostrophe = 39,  // '
  kComma = 44,       // ,
  kMinus = 45,       // -
  kPeriod = 46,      // .
  kSlash = 47,       // /
  k0 = 48,
  k1 = 49,
  k2 = 50,
  k3 = 51,
  k4 = 52,
  k5 = 53,
  k6 = 54,
  k7 = 55,
  k8 = 56,
  k9 = 57,
  kSemicolon = 59,  // ;
  kEqual = 61,      // =
  kA = 65,
  kB = 66,
  kC = 67,
  kD = 68,
  kE = 69,
  kF = 70,
  kG = 71,
  kH = 72,
  kI = 73,
  kJ = 74,
  kK = 75,
  kL = 76,
  kM = 77,
  kN = 78,
  kO = 79,
  kP = 80,
  kQ = 81,
  kR = 82,
  kS = 83,
  kT = 84,
  kU = 85,
  kV = 86,
  kW = 87,
  kX = 88,
  kY = 89,
  kZ = 90,
  kLeftBracket = 91,   // [
  kBackslash = 92,     // \
  kRightBracket = 93, // ]
  kGraveAcccent = 96,  // `
  kWorld1 = 161,       // non-US #1
  kWorld2 = 162,       // non-US #2

  // Function keys
  kEscape = 256,
  kEnter = 257,
  kTab = 258,
  kBackspace = 259,
  kInsert = 260,
  kDelete = 261,
  kRight = 262,
  kLeft = 263,
  kDown = 264,
  kUp = 265,
  kPageUp = 266,
  kPageDown = 267,
  kHome = 268,
  kEnd = 269,
  kCapsLock = 280,
  kScrollLock = 281,
  kNumLock = 282,
  kPrintScreen = 283,
  kPause = 284,
  kF1 = 290,
  kF2 = 291,
  kF3 = 292,
  kF4 = 293,
  kF5 = 294,
  kF6 = 295,
  kF7 = 296,
  kF8 = 297,
  kF9 = 298,
  kF10 = 299,
  kF11 = 300,
  kF12 = 301,
  kF13 = 302,
  kF14 = 303,
  kF15 = 304,
  kF16 = 305,
  kF17 = 306,
  kF18 = 307,
  kF19 = 308,
  kF20 = 309,
  kF21 = 310,
  kF22 = 311,
  kF23 = 312,
  kF24 = 313,
  kF25 = 314,
  kKP0 = 320,
  kKP1 = 321,
  kKP2 = 322,
  kKP3 = 323,
  kKP4 = 324,
  kKP5 = 325,
  kKP6 = 326,
  kKP7 = 327,
  kKP8 = 328,
  kKP9 = 329,
  kKPDecimal = 330,
  kKPDivide = 331,
  kKPMultiply = 332,
  kKPSubtact = 333,
  kKPAdd = 334,
  kKPEnter = 335,
  kKPEqual = 336,
  kLeftShift = 340,
  kLeftCantrol = 341,
  kLeftAlt = 342,
  kLeftSuper = 343,
  kRightShift = 344,
  kRightControl = 345,
  kRightAlt = 346,
  kRightSuper = 347,
  kMenu = 348,

  kLast = kMenu
};

}  // namespace xrn
#endif  // XRENDER_INCLUDE_INPUT_KEYBOARD_H_
