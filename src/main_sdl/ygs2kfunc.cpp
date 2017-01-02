#include "include.h"
#include "prototypes.h"
#include "gamedef.h"
#include "sdl_kanji.h"
#include "ygs2kfunc.h"

#define		SCREEN_BPP			0
#define		USE_SOFTSTRETCH		1

#define		USE_GL_KANJI		(0 && SDL_USE_OPENGL)
#define		USE_SDLKANJI		1
#define		USE_PNGKANJI		0
#define		YGS_KANJIFONT_MAX	6

#define		YGS_TEXTURE_MAX		100
#define		YGS_SOUND_MAX		100
#define		YGS_MUSIC_MAX		100
#define		YGS_KEYREPEAT_MAX	512
#define		YGS_JOYREPEAT_MAX	20
#define		YGS_JOYPAD_MAX		2
#define		YGS_TEXTLAYER_MAX	16

#if		SDL_USE_OPENGL
#include "gl_kanji.h"
#define		GAME_CAPTION		"HEBORIS C7-EX OpenGL"
#else
#define		GAME_CAPTION		"HEBORIS C7-EX SDL"
#endif

struct SScreenInfo
{
    int		real_w;
    int		real_h;
    int		win_w;
    int		win_h;
    int		full_screen;
};

struct STextLayer
{
    bool	enable;
    int		x;
    int		y;
    int		r, g, b;
    int		size;
    char	string[256];
};

enum
{
    YGS_SOUNDTYPE_NONE,
    YGS_SOUNDTYPE_WAV,
    YGS_SOUNDTYPE_MUS,
};

static SDL_Window       *s_pWindow = NULL;
static SDL_Surface      *s_pScreenSurface = NULL;

#if		SDL_USE_OPENGL
static GL_Texture		s_pYGSTexture[YGS_TEXTURE_MAX];
#else
static SDL_Surface		*s_pYGSTexture[YGS_TEXTURE_MAX];
#endif

static int				s_iKeyRepeat[YGS_KEYREPEAT_MAX];
static int				s_iJoyRepeat[YGS_JOYPAD_MAX][YGS_JOYREPEAT_MAX];
static SDL_Joystick		*s_pJoyPads[YGS_JOYPAD_MAX];
static int				s_iYGSSoundType[YGS_SOUND_MAX];
static Mix_Chunk		*s_pYGSSound[YGS_SOUND_MAX];
static int				s_iYGSSoundVolume[YGS_SOUND_MAX];
static Mix_Music		*s_pYGSExMusic[YGS_SOUND_MAX];
static Mix_Music		*s_pYGSMusic;

#if		USE_GL_KANJI
#define		YGS_KANJIFONTFILE_MAX	3
static ist::glKanji		s_pKanjiFont[YGS_KANJIFONTFILE_MAX];
#elif	USE_SDLKANJI
#define		YGS_KANJIFONTFILE_MAX	3
static Kanji_Font		*s_pKanjiFont[YGS_KANJIFONTFILE_MAX];
#elif	USE_PNGKANJI
static SDL_Surface		*s_pKanjiSurface[YGS_KANJIFONT_MAX];
#endif

static int				s_iActivePad;

static int				s_iWinWidth;
static int				s_iWinHeight;
#if SDL_USE_OPENGL
static float			s_fDrawScale = 1.0f;
#endif

static unsigned int		s_uTimeCount;
static unsigned int		s_uFPSCount;
static unsigned int		s_uNowFrame;
static unsigned int		s_uFPSCnting;
static unsigned int		s_uFPS;
static unsigned int		s_uNowFPS = 60;

static STextLayer		s_TextLayer[YGS_TEXTLAYER_MAX];
extern int				screenMode;

static int				s_iNewOffsetX = 0, s_iNewOffsetY = 0;
static int				s_iOffsetX = 0, s_iOffsetY = 0;

#if		SDL_USE_OPENGL
static SScreenInfo	s_ScreenInfo[] =
{
    { 320, 240,  320,  240, true },		// 0
    { 320, 240,  320,  240, false },	// 1
    { 640, 480,  640,  480, false },	// 2
    { 640, 480,  640,  480, true },		// 3
    { 640, 480,  800,  600, false },	// 4
    { 640, 480, 1024,  768, false },	// 5
    { 640, 480, 1280,  960, false },	// 6
    { 320, 240,  640,  480, true },		// 7
    { 320, 240,  480,  360, false },	// 8
    { 320, 240,  640,  480, false },	// 9
    { 320, 240,  800,  600, false },	// 10
    { 320, 240, 1024,  768, false },	// 11
    { 320, 240, 1280,  960, false },	// 12
};
#endif

bool YGS2kInit()
{
    int		winWidth, winHeight;
    
    s_iNewOffsetX = 0;	s_iNewOffsetY = 0;
    s_iOffsetX = 0;		s_iOffsetY = 0;
    
    /* CONFIG.SAVÇÊÇËê›íËÇÉçÅ[Éh */
    if ( LoadConfig() )
    {
        readdef::readdef();
        LoadConfig();
    }
    
    int		fullscreen = 0;
    
#if		SDL_USE_OPENGL
    /* âÊñ ÉÇÅ[ÉhÇÃïœçX */
    if ( screenMode >= 0 && screenMode <= 12 )
    {
        SScreenInfo		*s = &s_ScreenInfo[screenMode];
        winWidth  = s->win_w;
        winHeight = s->win_h;
        fullscreen = s->full_screen ? SDL_WINDOW_FULLSCREEN : 0;
        s_fDrawScale = (float)s->win_w / (float)s->real_w;
        SDL_GL_SetDrawRate(s_fDrawScale);
    }
#else
    /* âÊñ ÇÃê›íË */
    if ( screenMode > 3 ) { screenMode = 1; }
    
    switch ( screenMode )
    {
        case 0:
        case 1:
            winWidth  = 320;
            winHeight = 240;
            break;
            
        default:
            winWidth  = 640;
            winHeight = 480;
            break;
    }
    
    /* ÉEÉBÉìÉhÉEÇÃèâä˙âª */
    fullscreen = (screenMode == 0 || screenMode == 3) ? SDL_WINDOW_FULLSCREEN : 0;
#endif
    
    s_iWinWidth  = winWidth;
    s_iWinHeight = winHeight;

#if		SDL_USE_OPENGL
    s_pWindow = SDL_CreateWindow(GAME_CAPTION,
                                 SDL_WINDOWPOS_UNDEFINED,
                                 SDL_WINDOWPOS_UNDEFINED,
                                 winWidth, winHeight,
                                 SDL_WINDOW_OPENGL | fullscreen);
    SDL_GL_CreateContext(s_pWindow);
#else
    s_pWindow = SDL_CreateWindow(GAME_CAPTION,
                                 SDL_WINDOWPOS_UNDEFINED,
                                 SDL_WINDOWPOS_UNDEFINED,
                                 winWidth, winHeight,
                                 SDL_SWSURFACE | fullscreen);
#endif

    s_pScreenSurface = SDL_GetWindowSurface( s_pWindow );
    
    /* É}ÉEÉXÉJÅ[É\ÉãÇè¡Ç∑èÍçáÇÕ */
    if ( fullscreen == SDL_WINDOW_FULLSCREEN )
    {
        SDL_ShowCursor(SDL_DISABLE);
    }
    
    /* ÉLÅ[ÉäÉsÅ[ÉgÉoÉbÉtÉ@èâä˙âª */
    for ( int i = 0 ; i < YGS_KEYREPEAT_MAX ; i ++ )
    {
        s_iKeyRepeat[i] = 0;
    }
    
    for ( int pl = 0 ; pl < YGS_JOYPAD_MAX ; pl ++ )
    {
        for ( int i = 0 ; i < YGS_JOYREPEAT_MAX ; i ++ )
        {
            s_iJoyRepeat[pl][i] = 0;
        }
    }
    
    /* ÉeÉNÉXÉ`ÉÉóÃàÊÇÃèâä˙âª */
    for ( int i = 0 ; i < YGS_TEXTURE_MAX ; i ++ )
    {
#if		SDL_USE_OPENGL
        memset(s_pYGSTexture, 0, sizeof(s_pYGSTexture));
#else
        s_pYGSTexture[i] = NULL;
#endif
    }
    
    /* ÉTÉEÉìÉhÇÃèâä˙âª */
    for ( int i = 0 ; i < YGS_SOUND_MAX ; i ++ )
    {
        s_iYGSSoundType[i] = YGS_SOUNDTYPE_NONE;
        s_iYGSSoundVolume[i] = 0;
        s_pYGSSound[i] = NULL;
        s_pYGSExMusic[i] = NULL;
    }
    
    s_pYGSMusic = NULL;
    
    /* ÉpÉbÉhÇÃèâä˙âª */
    for ( int i = 0 ; i < YGS_JOYPAD_MAX ; i ++ )
    {
        s_pJoyPads[i] = SDL_JoystickOpen(i);
    }
    
    /* ÉeÉLÉXÉgÉåÉCÉÑÅ[ÇÃèâä˙âª */
    for ( int i = 0 ; i < YGS_TEXTLAYER_MAX ; i ++ )
    {
        memset(&s_TextLayer[i], 0, sizeof(STextLayer));
        s_TextLayer[i].r = s_TextLayer[i].g = s_TextLayer[i].b = 255;
        s_TextLayer[i].size = 16;
    }
    YGS2kKanjiFontInitialize();
    
    s_iActivePad = 0;
    
    s_uTimeCount = SDL_GetTicks();
    s_uFPSCount  = SDL_GetTicks();
    s_uNowFrame  = 0;
    s_uFPSCnting = 0;
    s_uFPS       = 0;
    
    srand((unsigned int)time(NULL));
    
    return true;
}

void YGS2kExit()
{
    /* ÉeÉNÉXÉ`ÉÉóÃàÊÇÃâï˙ */
    for ( int i = 0 ; i < YGS_TEXTURE_MAX ; i ++ )
    {
#if		SDL_USE_OPENGL
        SDL_GL_FreeTexture(&s_pYGSTexture[i]);
#else
        if ( s_pYGSTexture[i] )
        {
            SDL_FreeSurface(s_pYGSTexture[i]);
            s_pYGSTexture[i] = NULL;
        }
#endif
    }
    
    /* ÉpÉbÉhÇÃÉNÉçÅ[ÉY */
    for ( int i = 0 ; i < YGS_JOYPAD_MAX ; i ++ )
    {
        if ( s_pJoyPads[i] )
        {
            SDL_JoystickClose(s_pJoyPads[i]);
            s_pJoyPads[i] = NULL;
        }
    }
    
    /* ÉTÉEÉìÉhÇÃâï˙ */
    for ( int i = 0 ; i < YGS_SOUND_MAX ; i ++ )
    {
        s_iYGSSoundType[i] = YGS_SOUNDTYPE_NONE;
        
        if ( s_pYGSSound[i] )
        {
            Mix_FreeChunk(s_pYGSSound[i]);
            s_pYGSSound[i] = NULL;
        }
        if ( s_pYGSExMusic[i] )
        {
            Mix_FreeMusic(s_pYGSExMusic[i]);
            s_pYGSExMusic[i] = NULL;
        }
    }

    if (s_pScreenSurface != NULL) {
        SDL_FreeSurface(s_pScreenSurface);
    }
    
    if (s_pWindow != NULL) {
        SDL_DestroyWindow(s_pWindow);
    }
    
    YGS2kKanjiFontFinalize();
    
    if ( s_pYGSMusic )
    {
        Mix_FreeMusic(s_pYGSMusic);
        s_pYGSMusic = NULL;
    }
}

bool YGS2kHalt()
{
    SDL_Event	ev;
    SDL_Keycode	*key;
    
    /* ÉeÉLÉXÉgÉåÉCÉÑÅ[ÇÃï`âÊ */
    for ( int i = 0 ; i < YGS_TEXTLAYER_MAX ; i ++ )
    {
        TextBlt(i);
    }
    
#if		SDL_USE_OPENGL
    SDL_GL_Leave2DMode();
    SDL_GL_SwapWindow(s_pWindow);
    
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    
    SDL_GL_Enter2DMode(s_pScreenSurface->w, s_pScreenSurface->h);
#else
    SDL_UpdateWindowSurface(s_pWindow);
    
    SDL_FillRect( s_pScreenSurface, NULL, SDL_MapRGB( s_pScreenSurface->format, 0xFF, 0xFF, 0xFF ) );
#endif
    
    /* ÉCÉxÉìÉgèàóù */
    while(SDL_PollEvent(&ev) )
    {
        switch(ev.type){
            case SDL_QUIT:						// ÉEÉBÉìÉhÉEÇÃÅ~É{É^ÉìÇ™âüÇ≥ÇÍÇΩéûÇ»Ç«
                return false;
                break;
            case SDL_KEYDOWN:					// ÉLÅ[É{Å[ÉhÇ©ÇÁÇÃì¸óÕÇ™Ç†Ç¡ÇΩéû
            {
                key = &(ev.key.keysym.sym); // Ç«ÇÃÉLÅ[Ç™âüÇ≥ÇÍÇΩÇ©ÇéÊìæ
                if ( *key == 27 )			// ESCÉLÅ[
                {
                    return false;
                }
            }
                break;
        }
    }
    
    /* ÉtÉåÅ[ÉÄÉåÅ[Égë“Çø */
    while (s_uTimeCount + (1000 / s_uNowFPS) >= SDL_GetTicks())
    {
        SDL_Delay(0);
    };
    
    /* ÉtÉåÅ[ÉÄÉåÅ[ÉgåvéZ */
    s_uFPSCnting ++;
    s_uNowFrame ++;
    
    s_uTimeCount = SDL_GetTicks();
    
    if ( s_uFPSCount + 1000 <= SDL_GetTicks() )
    {
        s_uFPS = s_uFPSCnting;
        s_uFPSCnting = 0;
        s_uFPSCount = SDL_GetTicks();
    }
    
    /* âÊñ Ç∏ÇÁÇµó ÇÃîΩâf */
    s_iOffsetX = s_iNewOffsetX;
    s_iOffsetY = s_iNewOffsetY;
    
    return true;
}

void YGS2kTextOut(int x, int y, char* text, int r, int g, int b, int size)
{
    YGS2kKanjiDraw(x, y, r, g, b, size, text);
}

int IsPlayMIDI()
{
    return Mix_PlayingMusic();
}

void SelectJoyStick( int pl )
{
    s_iActivePad = pl;
}

int IsPushKey ( int key )
{
    return s_iKeyRepeat[key] == 1 ? 1 : 0;
}

int IsPressKey ( int key )
{
    return s_iKeyRepeat[key] != 0 ? 1 : 0;
}

int IsPushJoyKey ( int key )
{
    return s_iJoyRepeat[s_iActivePad][key] == 1 ? 1 : 0;
}

int IsPressJoyKey ( int key )
{
    if ( s_pJoyPads[s_iActivePad] )
    {
        switch ( key )
        {
            case 0:		// è„
                if ( SDL_JoystickGetAxis(s_pJoyPads[s_iActivePad], 1) < -32767 / 4 ) return 1;
                break;
                
            case 1:		// â∫
                if ( SDL_JoystickGetAxis(s_pJoyPads[s_iActivePad], 1) > +32767 / 4 ) return 1;
                break;
                
            case 2:		// ç∂
                if ( SDL_JoystickGetAxis(s_pJoyPads[s_iActivePad], 0) < -32767 / 4 ) return 1;
                break;
                
            case 3:		// âE
                if ( SDL_JoystickGetAxis(s_pJoyPads[s_iActivePad], 0) > +32767 / 4 ) return 1;
                break;
                
            default:
                int		key2 = key - 4;
                if ( key2 >= 0 && key2 < 16 ) return SDL_JoystickGetButton(s_pJoyPads[s_iActivePad], key2);
                break;
        }
    }
    
    return 0;
}

int IsPushReturnKey()
{
    return IsPushKey(SDL_SCANCODE_RETURN);
}

int IsPushDeleteKey()
{
    return IsPushKey(SDL_SCANCODE_DELETE);
}

int IsPushBSKey()
{
    return IsPushKey(SDL_SCANCODE_BACKSPACE);
}

int IsPushEscKey()
{
    return IsPushKey(SDL_SCANCODE_ESCAPE);
}

int IsPushEndKey()
{
    return IsPushKey(SDL_SCANCODE_END);
}

int getMaxKey()
{
    return YGS_KEYREPEAT_MAX;
}

void SetJoyButtonMax ( int max )
{
    
}

void SetConstParam ( char *param, int value )
{
    
}

void KeyInput()
{
    int		padbak = s_iActivePad;
    int		keynum = 0;
    const Uint8	*KeyInp = SDL_GetKeyboardState(&keynum);
    
    for ( int i = 0 ; i < YGS_KEYREPEAT_MAX ; i ++ )
    {
        if ( i != 300 && i < keynum && KeyInp[i] == SDL_PRESSED )
        {
            s_iKeyRepeat[i] ++;
        }
        else
        {
            s_iKeyRepeat[i] = 0;
        }
    }
    
    if ( SDL_NumJoysticks() > 0 )
    {
        SDL_JoystickUpdate();
    }
    
    for ( int pl = 0 ; pl < 2 ; pl ++ )
    {
        s_iActivePad = pl;
        
        for ( int i = 0 ; i < YGS_JOYREPEAT_MAX ; i ++ )
        {
            if ( IsPressJoyKey(i) )
            {
                s_iJoyRepeat[pl][i] ++;
            }
            else
            {
                s_iJoyRepeat[pl][i] = 0;
            }
        }
    }
    
    s_iActivePad = padbak;
}

int Rand ( int max )
{
    return rand() % max;
}

void PauseMIDI()
{
    Mix_PauseMusic();
}

void ReplayMIDI()
{
    Mix_ResumeMusic();
}

void PlayWave ( int no )
{
    switch ( s_iYGSSoundType[no] )
    {
        case YGS_SOUNDTYPE_WAV:
            Mix_PlayChannel(no, s_pYGSSound[no], 0);
            Mix_Volume(no, s_iYGSSoundVolume[no]);
            break;
            
        case YGS_SOUNDTYPE_MUS:
            Mix_PlayMusic(s_pYGSExMusic[no], -1);
            
            Mix_VolumeMusic(s_iYGSSoundVolume[no]);
            break;
    }
}

void ReplayWave ( int no )
{
    switch ( s_iYGSSoundType[no] )
    {
        case YGS_SOUNDTYPE_WAV:
            Mix_Resume(no);
            break;
            
        case YGS_SOUNDTYPE_MUS:
            Mix_RewindMusic();
            break;
    }
}

void StopWave ( int no )
{
    switch ( s_iYGSSoundType[no] )
    {
        case YGS_SOUNDTYPE_WAV:
            Mix_HaltChannel(no);
            break;
            
        case YGS_SOUNDTYPE_MUS:
            Mix_HaltMusic();
            break;
    }
}

void PauseWave ( int no )
{
    switch ( s_iYGSSoundType[no] )
    {
        case YGS_SOUNDTYPE_WAV:
            Mix_Pause(no);
            break;
            
        case YGS_SOUNDTYPE_MUS:
            Mix_PauseMusic();
            break;
    }
}

void SetVolumeWave( int no, int vol )
{
    int		volume = (vol + 10000) * 127 / 10000;
    if ( volume > 127 ) { volume = 127; }
    if ( volume < 0 )   { volume = 0; }
    s_iYGSSoundVolume[no] = volume;
    
    switch ( s_iYGSSoundType[no] )
    {
        case YGS_SOUNDTYPE_WAV:
            Mix_Volume(no, volume);
            break;
            
        case YGS_SOUNDTYPE_MUS:
            Mix_VolumeMusic(volume);
            break;
    }
}

int IsPlayWave( int no )
{
    switch ( s_iYGSSoundType[no] )
    {
        case YGS_SOUNDTYPE_WAV:
            /* Ç»Ç∫Ç©Ç±Ç±Çé¿çsÇ∑ÇÈÇ∆óéÇøÇÈÅc */
            return Mix_Playing(no);
            break;
            
        case YGS_SOUNDTYPE_MUS:
            return Mix_PlayingMusic();
            break;
    }
    return 0;
}

void LoadWave( char* filename, int no )
{
    int		len = (int)strlen(filename);
    if ( len < 4 ) { return; }
    
    if ( s_pYGSSound[no] != NULL )
    {
        Mix_FreeChunk(s_pYGSSound[no]);
        s_pYGSSound[no] = NULL;
    }
    
    if ( s_pYGSExMusic[no] != NULL )
    {
        Mix_FreeMusic(s_pYGSExMusic[no]);
        s_pYGSExMusic[no] = NULL;
    }
    
    s_iYGSSoundType[no] = YGS_SOUNDTYPE_NONE;
    
    // ägí£éqÅAÇ‹ÇΩÇÕî‘çÜ(50î‘à»ç~Ç™BGM)Ç…ÇÊÇ¡Çƒì«Ç›çûÇ›ï˚ñ@ÇïœÇ¶ÇÈ
    if ( strcasecmp(&filename[len - 4], ".wav") || no >= 50 )
    {
        s_pYGSExMusic[no] = Mix_LoadMUS(filename);
        s_iYGSSoundType[no] = YGS_SOUNDTYPE_MUS;
        s_iYGSSoundVolume[no] = 127;
    }
    else
    {
        s_pYGSSound[no] = Mix_LoadWAV(filename);
        s_iYGSSoundType[no] = YGS_SOUNDTYPE_WAV;
        s_iYGSSoundVolume[no] = 127;
    }
}

void SetLoopModeWave( int no, int mode )
{
    
}

void LoadMIDI( char* filename )
{
    if ( s_pYGSMusic != NULL )
    {
        Mix_FreeMusic(s_pYGSMusic);
        s_pYGSMusic = NULL;
    }
    
    s_pYGSMusic = Mix_LoadMUS(filename);
}

void LoadBitmap( char* filename, int plane, int val )
{
#if		SDL_USE_OPENGL
    if ( s_pYGSTexture[plane].active )
    {
        SDL_GL_FreeTexture(&s_pYGSTexture[plane]);
    }
    
    SDL_Surface		*surface	= IMG_Load(filename);
    if ( surface != NULL )
    {
        surface = SDL_ConvertSurfaceFormat(surface, SDL_PIXELFORMAT_ARGB8888, 0);
        SDL_GL_LoadTexture(surface, &s_pYGSTexture[plane]);
        SDL_FreeSurface(surface);
    }
    
#else
    if ( s_pYGSTexture[plane] )
    {
        SDL_FreeSurface(s_pYGSTexture[plane]);
        s_pYGSTexture[plane] = NULL;
    }
    
    s_pYGSTexture[plane] = IMG_Load(filename);
    if ( s_pYGSTexture[plane] != NULL )
    {
        s_pYGSTexture[plane] = SDL_ConvertSurfaceFormat(s_pYGSTexture[plane], SDL_PIXELFORMAT_ARGB8888, 0);
    }
#endif
}

void PlayMIDI()
{
    Mix_PlayMusic(s_pYGSMusic, -1);
}

void StopMIDI()
{
    Mix_HaltMusic();
}

void SetColorKeyPos(int plane, int x, int y)
{
    
}

void EnableBlendColorKey(int plane, int key)
{
    
}

void CreateSurface(int surf, int w, int h)
{
    
}

void ClearSecondary()
{
    
}

void SetFillColor(int col)
{
    
}

void LoadFile( char* filename, void* buf, int size )
{
    FILE	*file;
    file = fopen(filename, "rb");
    if ( file )
    {
        fread(buf, 1, size, file);
        fclose(file);
        
        int		i, *buf2;
        
        /* ÉGÉìÉfÉBÉAÉìïœä∑ */
        buf2 = (int*)buf;
        for ( i = 0 ; i < size / 4 ; i ++ )
        {
            buf2[i] = SWAP32(buf2[i]);
        }
    }
}

void SaveFile( char* filename, void* buf, int size )
{
    FILE	*file;
    int		i, *buf2;
    
    /* ÉGÉìÉfÉBÉAÉìïœä∑ */
    buf2 = (int*)buf;
    for ( i = 0 ; i < size / 4 ; i ++ )
    {
        buf2[i] = SWAP32(buf2[i]);
    }
    
    file = fopen(filename, "wb");
    if ( file )
    {
        fwrite(buf, 1, size, file);
        fclose(file);
    }
    
    /* Ç‡Ç«Ç∑ */
    for ( i = 0 ; i < size / 4 ; i ++ )
    {
        buf2[i] = SWAP32(buf2[i]);
    }
}

void TextLayerOn ( int layer, int x, int y )
{
    s_TextLayer[layer].enable = true;
    s_TextLayer[layer].x = x;
    s_TextLayer[layer].y = y;
}

void TextMove ( int layer, int x, int y )
{
    s_TextLayer[layer].x = x;
    s_TextLayer[layer].y = y;
}

void TextColor ( int layer, int r, int g, int b )
{
    s_TextLayer[layer].r = r;
    s_TextLayer[layer].g = g;
    s_TextLayer[layer].b = b;
}

void TextBackColorDisable ( int layer )
{
    
}

void TextSize ( int layer, int size )
{
    s_TextLayer[layer].size = size;
}

void TextHeight ( int layer, int height )
{
    
}

void TextOut ( int layer, char* text )
{
    strcpy(s_TextLayer[layer].string, text);
}

void TextBlt ( int layer )
{
    if ( s_TextLayer[layer].enable )
    {
        YGS2kTextOut(s_TextLayer[layer].x + s_iOffsetX, s_TextLayer[layer].y + s_iOffsetY, s_TextLayer[layer].string, s_TextLayer[layer].r, s_TextLayer[layer].g, s_TextLayer[layer].b, s_TextLayer[layer].size);
    }
}

void TextLayerOff ( int layer )
{
    s_TextLayer[layer].enable = false;
}

void Blt(int pno, int dx, int dy)
{
#if		SDL_USE_OPENGL
    if ( !s_pYGSTexture[pno].active ) { return; }
    BltRect(pno, dx, dy, 0, 0, s_pYGSTexture[pno].real_width, s_pYGSTexture[pno].real_height);
#else
    if ( s_pYGSTexture[pno] == NULL ) { return; }
    BltRect(pno, dx, dy, 0, 0, s_pYGSTexture[pno]->w, s_pYGSTexture[pno]->h);
#endif
}

void BltRect(int pno, int dx, int dy, int sx, int sy, int hx, int hy)
{
#if		SDL_USE_OPENGL
    SDL_GL_PutTexture(&s_pYGSTexture[pno], dx, dy, hx, hy, sx, sy, hx, hy);
#else
    if ( s_pYGSTexture[pno] == NULL ) return;
    
    SDL_Rect	src;
    SDL_Rect	dst;
    
    src.x = sx;					src.y = sy;
    src.w = hx;					src.h = hy;
    dst.x = dx + s_iOffsetX;	dst.y = dy + s_iOffsetY;
    
    SDL_BlitSurface( s_pYGSTexture[pno], &src, s_pScreenSurface, &dst );
#endif
}

void BltFast(int pno, int dx, int dy)
{
    Blt(pno, dx, dy);
}

void BltFastRect(int pno, int dx, int dy, int sx, int sy, int hx, int hy)
{
    BltRect(pno, dx, dy, sx, sy, hx, hy);
}

void BlendBlt(int pno, int dx, int dy, int ar, int ag, int ab, int br, int bg, int bb)
{
#if		SDL_USE_OPENGL
    glColor4ub(255, 255, 255, ar);
    Blt(pno, dx, dy);
    glColor4ub(255, 255, 255, 255);
#else
    if ( s_pYGSTexture[pno] == NULL ) return;
    
    SDL_SetSurfaceAlphaMod(s_pYGSTexture[pno], 128);
    Blt(pno, dx, dy);
    SDL_SetSurfaceAlphaMod(s_pYGSTexture[pno], 255);
#endif
}

void BlendBltRect(int pno, int dx, int dy, int sx, int sy, int hx, int hy, int ar, int ag, int ab, int br, int bg, int bb)
{
#if		SDL_USE_OPENGL
    glColor4ub(255, 255, 255, ar);
    BltRect(pno, dx, dy, sx, sy, hx, hy);
    glColor4ub(255, 255, 255, 255);
#else
    if ( s_pYGSTexture[pno] == NULL ) return;
    
    SDL_SetSurfaceAlphaMod(s_pYGSTexture[pno], 128);
    BltRect(pno, dx, dy, sx, sy, hx, hy);
    SDL_SetSurfaceAlphaMod(s_pYGSTexture[pno], 255);
#endif
}

void BltR(int pno, int dx, int dy, int scx, int scy)
{
    BltRectR(pno, dx, dy, 0, 0, s_iWinWidth, s_iWinHeight, scx, scy);
}

void BltRectR(int pno, int dx, int dy, int sx, int sy, int hx, int hy, int scx, int scy)
{
#if		SDL_USE_OPENGL
    SDL_GL_PutTexture(&s_pYGSTexture[pno], dx, dy, (float)hx * ((float)scx / 65536.0f), (float)hy * ((float)scy / 65536.0f), sx, sy, hx, hy);
#else
    if ( s_pYGSTexture[pno] == NULL ) return;
    
#if		!USE_SOFTSTRETCH
    // ägëÂÇµÇ»Ç¢Ç≈ìKìñÇ…åÎñÇâªÇ∑ï`âÊ
    SDL_Rect	src;
    SDL_Rect	dst;
    int			wx = hx * ((float)scx / 65536.0f), wy = hy * ((float)scy / 65536.0f);
    
    if ( scx < 65536 )
    {
        src.x = sx + (hx - wx) / 2;
        src.w = hx - (hx - wx);
        dst.x = dx + s_iOffsetX;
    }
    else
    {
        src.x = sx;
        src.w = hx;
        dst.x = dx + (wx - hx) / 2 + s_iOffsetX;
    }
    
    if ( scy < 65536 )
    {
        src.y = sy + (hy - wy) / 2;
        src.h = hy - (hy - wy);
        dst.y = dy + s_iOffsetY;
    }
    else
    {
        src.y = sy;
        src.h = hy;
        dst.y = dy + (wy - hy) / 2 + s_iOffsetY;
    }
    
    SDL_BlitSurface( s_pYGSTexture[pno], &src, s_pScreenSurface, &dst );
#else
    // ÇøÇ·ÇÒÇ∆ägëÂÇµÇƒï`âÊÇ∑ÇÈ
    SDL_Rect	src;
    SDL_Rect	dst;
    
    src.x = sx;					src.y = sy;
    src.w = hx;					src.h = hy;
    dst.x = dx + s_iOffsetX;	dst.y = dy + s_iOffsetY;
    dst.w = hx * ((float)scx / 65536.0f);
    dst.h = hy * ((float)scy / 65536.0f);
    
    if ( src.w == 0 || src.h == 0 || dst.w == 0 || dst.h == 0 ) { return; }
    
    SDL_SoftStretch( s_pYGSTexture[pno], &src, s_pScreenSurface, &dst );
#endif
#endif
}

void BltFastR(int pno, int dx, int dy, int scx, int scy)
{
    BltR(pno, dx, dy, scx, scy);
}

void BltFastRectR(int pno, int dx, int dy, int sx, int sy, int hx, int hy, int scx, int scy)
{
    BltRectR(pno, dx, dy, sx, sy, hx, hy, scx, scy);
}

void BltTrans(int pno, int dx, int dy)
{
    
}

void BlendBltR(int pno, int dx, int dy, int ar, int ag, int ab, int br, int bg, int bb, int scx, int scy)
{
    BlendBltRectR(pno, dx, dy, 0, 0, s_iWinWidth, s_iWinHeight, ar, ag, ab, br, bg, bb, scx, scy);
}

void BlendBltRectR(int pno, int dx, int dy, int sx, int sy, int hx, int hy, int ar, int ag, int ab, int br, int bg, int bb, int scx, int scy)
{
#if		SDL_USE_OPENGL
    glColor4ub(255, 255, 255, ar);
    SDL_GL_PutTexture(&s_pYGSTexture[pno], dx, dy, (float)hx * ((float)scx / 65536.0f), (float)hy * ((float)scy / 65536.0f), sx, sy, hx, hy);
    glColor4ub(255, 255, 255, 255);
#else
    if ( s_pYGSTexture[pno] == NULL ) return;
    
#if		1 // !USE_SOFTSTRETCH
    // ägëÂÇµÇ»Ç¢Ç≈ìKìñÇ…åÎñÇâªÇ∑ï`âÊ
    SDL_Rect	src;
    SDL_Rect	dst;
    int			wx = hx * ((float)scx / 65536.0f), wy = hy * ((float)scy / 65536.0f);
    
    if ( scx < 65536 )
    {
        src.x = sx + (hx - wx) / 2;
        src.w = hx - (hx - wx);
        dst.x = dx + s_iOffsetX;
    }
    else
    {
        src.x = sx;
        src.w = hx;
        dst.x = dx + (wx - hx) / 2 + s_iOffsetX;
    }
    
    if ( scy < 65536 )
    {
        src.y = sy + (hy - wy) / 2;
        src.h = hy - (hy - wy);
        dst.y = dy + s_iOffsetY;
    }
    else
    {
        src.y = sy;
        src.h = hy;
        dst.y = dy + (wy - hy) / 2 + s_iOffsetY;
    }
    
    SDL_SoftStretch( s_pYGSTexture[pno], &src, s_pScreenSurface, &dst );
#else
    // ÇøÇ·ÇÒÇ∆ägëÂÇµÇƒï`âÊÇ∑ÇÈ
    SDL_Rect	src;
    SDL_Rect	dst;
    
    src.x = sx;					src.y = sy;
    src.w = hx;					src.h = hy;
    dst.x = dx + s_iOffsetX;	dst.y = dy + s_iOffsetY;
    dst.w = hx * ((float)scx / 65536.0f);
    dst.h = hy * ((float)scy / 65536.0f);
    
    if ( src.w == 0 || src.h == 0 || dst.w == 0 || dst.h == 0 ) { return; }
    
    SDL_SoftStretch( s_pYGSTexture[pno], &src, s_pScreenSurface, &dst );
#endif
    
    SDL_SetSurfaceAlphaMod(s_pYGSTexture[pno], 255);
#endif
}

void SetSecondaryOffset(int x, int y)
{
    s_iNewOffsetX = x;
    s_iNewOffsetY = y;
}

void SetColorKeyRGB(int pno, int r, int g, int b)
{
    
}

void SwapToSecondary(int pno)
{
    
}

void SetFPS(int fps)
{
    s_uNowFPS = fps;
}

int GetFPS()
{
    return s_uNowFPS;
}

int GetRealFPS()
{
    return s_uFPS;
}

void StrCpy(char *dest, char *src)
{
    strcpy(dest, src);
}

void StrCpy(void *dest, char *src)
{
    strcpy((char*)dest, src);
}

void StrCpy(char *dest, void *src)
{
    strcpy(dest, (char*)src);
}

void StrCat(char *str1, char *str2)
{
    strcat(str1, str2);
}

int StrLen(char *stri)
{
    return (int)strlen(stri);
}

void MidStr(char *src, int start, int len, char *dest)
{
    int		i;
    for ( i = 0 ; i < len ; i ++ )
    {
        dest[i] = src[start - 1 + i];
    }
    dest[len] = '\0';
}

void LeftStr(char *src, int len, char *dest)
{
    MidStr(src, 1, len, dest);
}

char CharAt(char *stri, int pos)
{
    return stri[pos];
}

int ValLong(char *stri)
{
    return atoi(stri);
}

void FillMemory(void* buf, int size, int val)
{
    memset(buf, val, size);
}

////////////////////////////////////////////////////

void YGS2kKanjiFontInitialize()
{
#if		USE_GL_KANJI
    s_pKanjiFont[0].load("kanjifont/knj10.f1b");
    s_pKanjiFont[1].load("kanjifont/knj12.f1b");
    s_pKanjiFont[2].load("kanjifont/knj16.f1b");
#elif	USE_SDLKANJI
    /* 10pxÉtÉHÉìÉgì«Ç›çûÇ› */
    s_pKanjiFont[0] = Kanji_OpenFont("kanjifont/knj10.bdf", 10);
    if ( s_pKanjiFont[0] )
    {
        Kanji_AddFont(s_pKanjiFont[0], "kanjifont/5x10a.bdf");
    }
    else
    {
        /* ÉtÉHÉìÉgÇ™Ç»Ç¢èÍçáë„ë÷ÇégÇ§ */
        s_pKanjiFont[0] = Kanji_OpenFont("kanjifont/knj12.bdf", 10);
        Kanji_AddFont(s_pKanjiFont[0], "kanjifont/6x12a.bdf");
    }
    
    if ( s_pKanjiFont[0] )
    {
        Kanji_SetCodingSystem(s_pKanjiFont[0], KANJI_SJIS);
    }
    
    /* 12pxÉtÉHÉìÉgì«Ç›çûÇ› */
    s_pKanjiFont[1] = Kanji_OpenFont("kanjifont/knj12.bdf", 12);
    if ( s_pKanjiFont[1] )
    {
        Kanji_AddFont(s_pKanjiFont[1], "kanjifont/6x12a.bdf");
        Kanji_SetCodingSystem(s_pKanjiFont[1], KANJI_SJIS);
    }
    
    /* 16pxÉtÉHÉìÉgì«Ç›çûÇ› */
    s_pKanjiFont[2] = Kanji_OpenFont("kanjifont/knj16.bdf", 16);
    if ( s_pKanjiFont[2] )
    {
        Kanji_AddFont(s_pKanjiFont[2], "kanjifont/8x16a.bdf");
        Kanji_SetCodingSystem(s_pKanjiFont[2], KANJI_SJIS);
    }
#elif	USE_PNGKANJI
    char	*kanjifile[YGS_KANJIFONT_MAX] = 
    {
        "kanjifont/kanjifont10w.png",
        "kanjifont/kanjifont10b.png",
        "kanjifont/kanjifont12w.png",
        "kanjifont/kanjifont12b.png",
        "kanjifont/kanjifont16w.png",
        "kanjifont/kanjifont16b.png",
    };
    
    for ( int i = 0 ; i < YGS_KANJIFONT_MAX ; i ++ )
    {
        s_pKanjiSurface[i] = IMG_Load(kanjifile[i]);
        
        // if ( s_pKanjiSurface[i] )
        // {
        // Ç†Ç‹ÇËïKóvê´Ç™Ç»Ç¢ÇÃÇ≈ÇµÇ»Ç¢Ç≈Ç®Ç≠
        // s_pKanjiSurface[i] = SDL_DisplayFormat(s_pKanjiSurface[i]);
        // }
    }
#endif
}

void YGS2kKanjiFontFinalize()
{
#if		USE_GL_KANJI
    
#elif	USE_SDLKANJI
    if ( s_pKanjiFont[0] ) { Kanji_CloseFont(s_pKanjiFont[0]); }
    if ( s_pKanjiFont[1] ) { Kanji_CloseFont(s_pKanjiFont[1]); }
    if ( s_pKanjiFont[2] ) { Kanji_CloseFont(s_pKanjiFont[2]); }
#elif	USE_PNGKANJI
    for ( int i = 0 ; i < YGS_KANJIFONT_MAX ; i ++ )
    {
        if ( s_pKanjiSurface[i] )
        {
            SDL_FreeSurface(s_pKanjiSurface[i]);
        }
    }
#endif
}

void YGS2kKanjiDrawSub(int font, int x, int y, int kx, int ky)
{
#if		USE_GL_KANJI
    
#elif	USE_SDLKANJI
    
#elif	USE_PNGKANJI
    SDL_Rect	src;
    SDL_Rect	dst;
    int			width = s_iKanjiWidth[font];
    
    if ( !s_pKanjiSurface[font] )
    {
        return;
    }
    
    src.x = kx * width / 2;	src.y = ky * width;
    src.w = width / 2;		src.h = width;
    dst.x = x;				dst.y = y;
    
    if ( ky > 1 ) { src.w *= 2; }
    
    SDL_BlitSurface( s_pKanjiSurface[font], &src, s_pScreenSurface, &dst );
#endif
}

void YGS2kKanjiDraw(int x, int y, int r, int g, int b, int size, char *str)
{
#if		USE_GL_KANJI
    int		font = 0;
    
    if ( size >= 12 )
    {
        font ++;
    }
    if ( size >= 16 )
    {
        font ++;
    }
    
    glBindTexture(GL_TEXTURE_2D, 0);
    glColor4ub(r, g, b, 255);
    s_pKanjiFont[font].print(x, y, str);
    glColor4ub(255, 255, 255, 255);
#elif	USE_SDLKANJI
    SDL_Color col;
    int		font = 0;
    
    if ( size >= 12 )
    {
        font ++;
    }
    if ( size >= 16 )
    {
        font ++;
    }
    
    col.r = r;
    col.g = g;
    col.b = b;
    
    if ( s_pKanjiFont[font] )
    {
#if		SDL_USE_OPENGL
        glBindTexture(GL_TEXTURE_2D, 0);
        glColor4ub(r, g, b, 255);
        Kanji_PutTextGL(s_pKanjiFont[font], x, y + 2, str, r, g, b, s_fDrawScale);
        glColor4ub(255, 255, 255, 255);
#else
        Kanji_PutText(s_pKanjiFont[font], x, y, s_pScreenSurface, str, col);
#endif
    }
#elif	USE_PNGKANJI
    int		font = 0;
    
    if ( size >= 12 )
    {
        font += 2;
    }
    if ( size >= 16 )
    {
        font += 2;
    }
    
    if ( r + g + b == 0 )
    {
        font ++;
    }
    
    if ( font < 0 || font >= YGS_KANJIFONT_MAX ) { return; }
    
    int		firstbyte = 0;
    int		xx = 0, yy = 0;
    int		len = strlen(str);
    int		width = s_iKanjiWidth[font];
    
    for ( int i = 0 ; i < len ; i ++ )
    {
        unsigned char	chr = str[i];
        
        if ( chr == '\n' )
        {
            xx = 0;
            yy += width;
        }
        else if ( firstbyte > 0 )
        {
            if ( firstbyte >= 0x81 && firstbyte <= 0x9f )
            {
                YGS2kKanjiDrawSub(font, x + xx, y + yy, (int)(chr - 0x40) * 2, firstbyte - 0x81 + 3);
            }
            else if ( firstbyte >= 0xe0 && firstbyte <= 0xea )
            {
                YGS2kKanjiDrawSub(font, x + xx, y + yy, (int)(chr - 0x40) * 2, firstbyte - 0xe0 + 34);
            }
            xx += width;
            firstbyte = 0;
        }
        else if ( (chr >= 0x81 && chr <= 0x9f) || chr >= 0xe0 )
        {
            firstbyte = chr;
        }
        else
        {
            if ( chr >= ' ' && chr <= '~' )
            {
                YGS2kKanjiDrawSub(font, x + xx, y + yy, chr - ' ', 0);
            }
            else if ( chr >= 161 /* ° */ && chr <= 223 /* ﬂ */ )
            {
                YGS2kKanjiDrawSub(font, x + xx, y + yy, chr - 161 + 1, 1);
            }
            xx += width / 2;
        }
    }
#endif
}