/* Minimal SDL compatibility definitions used when RENDER_DISABLED=1
   Provides token definitions so code can compile without SDL installed.
   This is intentionally minimal and only for build-time (no runtime).
*/
#ifndef SDL_COMPAT_H
#define SDL_COMPAT_H

#ifdef RENDER_DISABLED

/* version check macro */
#ifndef SDL_VERSION_ATLEAST
#define SDL_VERSION_ATLEAST(a,b,c) 0
#endif

/* joystick/type stubs */
typedef struct SDL_Joystick SDL_Joystick;

/* window/renderer/surface stubs (some files reference these types) */
typedef struct SDL_Window SDL_Window;
typedef struct SDL_Renderer SDL_Renderer;
typedef struct SDL_Surface SDL_Surface;

/* modifier masks */
#define KMOD_SHIFT 0x0001

/* Mouse buttons used */
#define SDL_BUTTON_LEFT 1
#define SDL_BUTTON_MIDDLE 2
#define SDL_BUTTON_RIGHT 3
#define SDL_BUTTON_WHEELUP 4
#define SDL_BUTTON_WHEELDOWN 5

/* Provide a broad set of SDLK_* tokens used across the codebase */
enum {
    SDLK_UNKNOWN = 0,
    /* arrows and navigation */
    SDLK_UP = 273,
    SDLK_DOWN = 274,
    SDLK_RIGHT = 275,
    SDLK_LEFT = 276,
    SDLK_PAGEUP = 266,
    SDLK_PAGEDOWN = 267,
    SDLK_HOME = 278,
    SDLK_END = 279,
    SDLK_INSERT = 277,
    SDLK_DELETE = 127,
    SDLK_RETURN = 13,
    SDLK_BACKSPACE = 8,
    SDLK_TAB = 9,
    SDLK_SPACE = 32,
    SDLK_ESCAPE = 27,

    /* function keys */
    SDLK_F1 = 282,
    SDLK_F2 = 283,
    SDLK_F3 = 284,
    SDLK_F4 = 285,
    SDLK_F5 = 286,
    SDLK_F6 = 287,
    SDLK_F7 = 288,
    SDLK_F8 = 289,
    SDLK_F9 = 290,
    SDLK_F10 = 291,
    SDLK_F11 = 292,
    SDLK_F12 = 293,

    /* keypad */
    SDLK_KP_MINUS = 269,
    SDLK_KP_PLUS = 270,

    /* letters and digits (lowercase) */
    SDLK_a = 'a', SDLK_b = 'b', SDLK_c = 'c', SDLK_d = 'd', SDLK_e = 'e', SDLK_f = 'f', SDLK_g = 'g', SDLK_h = 'h', SDLK_i = 'i', SDLK_j = 'j', SDLK_k = 'k', SDLK_l = 'l', SDLK_m = 'm', SDLK_n = 'n', SDLK_o = 'o', SDLK_p = 'p', SDLK_q = 'q', SDLK_r = 'r', SDLK_s = 's', SDLK_t = 't', SDLK_u = 'u', SDLK_v = 'v', SDLK_w = 'w', SDLK_x = 'x', SDLK_y = 'y', SDLK_z = 'z',
    SDLK_LALT = 308,
    SDLK_0 = '0', SDLK_1 = '1', SDLK_2 = '2', SDLK_3 = '3', SDLK_4 = '4', SDLK_5 = '5', SDLK_6 = '6', SDLK_7 = '7', SDLK_8 = '8', SDLK_9 = '9',

    /* miscellaneous */
    SDLK_BACKQUOTE = '`',
    SDLK_MINUS = '-',

    /* last sentinel used in input.h */
    SDLK_LAST = 512
};

/* Minimal SDL functions used at compile time */
#ifdef __cplusplus
extern "C" {
#endif

const char *SDL_GetKeyName(int scancode);

#ifdef __cplusplus
}
#endif

#endif /* RENDER_DISABLED */

#endif /* SDL_COMPAT_H */
