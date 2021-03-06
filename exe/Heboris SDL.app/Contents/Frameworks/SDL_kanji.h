#ifndef SDLbdf_h_
#define SDLbdf_h_

#include <SDL.h>

/* Set up for C function definitions, even when using C++ */
#ifdef __cplusplus
extern "C" {
#endif

typedef enum { KANJI_SJIS, KANJI_EUC, KANJI_JIS } Kanji_CodingSystem;

typedef struct {
	int k_size;
	int a_size;
	Kanji_CodingSystem sys;
	/* メモリ効率わるいけど、まあ死にはしないわな。 */
	Uint32* moji[96*96+256];
} Kanji_Font;

Kanji_Font* Kanji_OpenFont(const char* file, int size);

int Kanji_AddFont(Kanji_Font* font, const char* file);

void Kanji_SetCodingSystem(Kanji_Font* font, Kanji_CodingSystem sys);

int Kanji_FontHeight(Kanji_Font* font);
/* text == 0 なら ASCII 一文字分の幅を返す */
int Kanji_FontWidth(Kanji_Font* font, const char* text);

SDL_Surface* Kanji_CreateSurface(Kanji_Font* font, const char* text,
								 SDL_Color fg, int bpp);
int Kanji_PutText(Kanji_Font* font, int dx, int dy,
				  SDL_Surface* dst, const char* text, SDL_Color fg);
SDL_Surface* Kanji_CreateSurfaceTate(Kanji_Font* font, const char* text,
								     SDL_Color fg, int bpp);
int Kanji_PutTextTate(Kanji_Font* font, int dx, int dy,
				      SDL_Surface* dst, const char* text, SDL_Color fg);

#if		SDL_USE_OPENGL
int Kanji_PutTextGL(Kanji_Font* font, int dx, int dy, const char* txt, int r, int g, int b, float rate = 1.0f);
#endif

void Kanji_CloseFont(Kanji_Font* font);

/* Ends C function definitions when using C++ */
#ifdef __cplusplus
};
#endif

#endif

