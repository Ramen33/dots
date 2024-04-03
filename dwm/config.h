static const unsigned int borderpx  = 0;
static const unsigned int gappx     = 10;
static const unsigned int snap      = 32;
static const int showbar            = 1;
static const int topbar             = 1;
static const int usealtbar          = 0;
static const char *altbarclass      = "Polybar";
static const char *altbarcmd        = "$HOME/bar.sh";
static const char *fonts[]          = { "JetBrainsMono-Bold:size=6" };
static const char dmenufont[]       = "JetBrainsMono-Bold:size=6";
static unsigned int baralpha        = 0xb0;
static unsigned int borderalpha     = OPAQUE;
static const char col_gray1[]       = "#181818"; //OG #222222
static const char col_gray2[]       = "#444444";
static const char col_gray3[]       = "#bbbbbb";
static const char col_gray4[]       = "#eeeeee";
static const char col_cyan[]        = "#1E1E2E"; //OG #005577 Purple #8D6298 Bl#2e3e64 C #1E1E2E
static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm] = { col_gray3, col_gray1, col_gray2 },
	[SchemeSel]  = { col_gray4, col_cyan,  col_cyan  },
	[SchemeHid]  = { col_cyan,  col_gray1, col_cyan  },
};

//static const char *tags[] = { "", "", "", "", "", "", "", "", "" };
//static const char *tags[] = { "", "", "", "", "", "", "", "", "" };
static const char *tags[] = { "", "", "", "", "", "", "", "", "", "", "", "", ""};

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     isfloating   monitor */
	{ "Gimp",     NULL,       NULL,       0,            1,           -1 },
	{ "Firefox",  NULL,       NULL,       1 << 8,       0,           -1 },
};

static const float mfact     = 0.50; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

#include "fibonacci.c"
#include "layouts.c"
#include "movestack.c"

static const Layout layouts[] = {
	{ "[]=",      tile },
//        { "[@]",      spiral },
	{ "><>",      NULL },
//	{ "[]=",      tile },
	{ "[M]",      monocle },
//	{ "[]=",       tile },
	{ "[@]",      spiral },
	{ "[\\]",     dwindle },
	{ "HHH",      grid },
};

#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

static char dmenumon[2] = "0";
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", col_gray1, "-nf", col_gray3, "-sb", col_cyan, "-sf", col_gray4, NULL };
static const char *termcmd[]  = { "st", NULL };

#include <X11/XF86keysym.h>
#define TERMINAL "st"

static const Key keys[] = {
	{ MODKEY,                       XK_s,      spawn,          {.v = dmenucmd } },
	{ MODKEY,                       XK_Return, spawn,          {.v = (const char*[]){"st", NULL } } },
	{ MODKEY,                       XK_b,      togglebar,      {0} },
	{ MODKEY,                       XK_j,      focusstackvis,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstackvis,     {.i = -1 } },
        { MODKEY|ShiftMask,             XK_j,      focusstackhid,     {.i = +1 } },
        { MODKEY|ShiftMask,             XK_k,      focusstackhid,     {.i = +1 } },
	{ MODKEY,                       XK_period,      incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_slash,      incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY|ShiftMask,             XK_Return, spawn,    {.v = (const char*[]){"alacritty", NULL } } },
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY,                       XK_q,      killclient,     {0} },
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_y,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_u,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY|ShiftMask,             XK_space,  setlayout,      {0} },
	{ MODKEY,                       XK_space,  togglefloating, {0} },
	{ MODKEY,                       XK_Down,   moveresize,     {.v = "0x 25y 0w 0h" } },
	{ MODKEY,                       XK_Up,     moveresize,     {.v = "0x -25y 0w 0h" } },
	{ MODKEY,                       XK_Right,  moveresize,     {.v = "25x 0y 0w 0h" } },
	{ MODKEY,                       XK_Left,   moveresize,     {.v = "-25x 0y 0w 0h" } },
	{ MODKEY|ShiftMask,             XK_Down,   moveresize,     {.v = "0x 0y 0w 25h" } },
	{ MODKEY|ShiftMask,             XK_Up,     moveresize,     {.v = "0x 0y 0w -25h" } },
	{ MODKEY|ShiftMask,             XK_Right,  moveresize,     {.v = "0x 0y 25w 0h" } },
	{ MODKEY|ShiftMask,             XK_Left,   moveresize,     {.v = "0x 0y -25w 0h" } },
	{ MODKEY|ControlMask,           XK_Up,     moveresizeedge, {.v = "t"} },
	{ MODKEY|ControlMask,           XK_Down,   moveresizeedge, {.v = "b"} },
	{ MODKEY|ControlMask,           XK_Left,   moveresizeedge, {.v = "l"} },
	{ MODKEY|ControlMask,           XK_Right,  moveresizeedge, {.v = "r"} },
	{ MODKEY|ControlMask|ShiftMask, XK_Up,     moveresizeedge, {.v = "T"} },
	{ MODKEY|ControlMask|ShiftMask, XK_Down,   moveresizeedge, {.v = "B"} },
	{ MODKEY|ControlMask|ShiftMask, XK_Left,   moveresizeedge, {.v = "L"} },
	{ MODKEY|ControlMask|ShiftMask, XK_Right,  moveresizeedge, {.v = "R"} },
        { Mod1Mask,                       XK_bracketleft,  setgaps,        {.i = -1 } },
        { Mod1Mask,                       XK_bracketright,  setgaps,        {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_bracketright,  setgaps,        {.i = 0 } },
	{ MODKEY,                       XK_BackSpace,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_BackSpace,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
        { MODKEY|ShiftMask,             XK_j,      movestack,      {.i = +1 } },
        { MODKEY|ShiftMask,             XK_k,      movestack,      {.i = -1 } },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
	TAGKEYS(                        XK_0,                  9)
	TAGKEYS(                        XK_minus,                 10)
	TAGKEYS(                        XK_equal,                  11)
	{ MODKEY|ShiftMask,             XK_e,      quit,           {0} },
	{ MODKEY,                       XK_f,      togglefullscreen,  {0} },
	{ MODKEY,                       XK_i,      setlayout,  {.v = &layouts[3]} },
	{ MODKEY,                       XK_o,      setlayout,  {.v = &layouts[4]} },
	{ MODKEY,                       XK_p,      setlayout,  {.v = &layouts[5]} },
	{ Mod1Mask,                     XK_j,      moveresize, {.v = "0x 25y 0w 0h"} },
	{ Mod1Mask,                     XK_k,      moveresize, {.v = "0x -25y 0w 0h"} },
        { Mod1Mask,                     XK_l,      moveresize, {.v = "25x 0y 0w 0h"} },
        { Mod1Mask,                     XK_h,      moveresize, {.v = "-25x 0y 0w 0h"} },
	{ Mod1Mask|ShiftMask,           XK_j,      moveresize, {.v = "0x 0y 0w 25h"} },
	{ Mod1Mask|ShiftMask,           XK_k,      moveresize, {.v = "0x 0y 0w -25h"} },
	{ Mod1Mask|ShiftMask,           XK_l,      moveresize, {.v = "0x 0y 25w 0h"} },
	{ Mod1Mask|ShiftMask,           XK_h,      moveresize, {.v = "0x 0y -25w 0h"} },
	{ Mod1Mask|ControlMask,         XK_k,      moveresizeedge, {.v = "t"} },
        { Mod1Mask|ControlMask,         XK_j,      moveresizeedge, {.v = "b"} },
        { Mod1Mask|ControlMask,         XK_h,      moveresizeedge, {.v = "l"} },
        { Mod1Mask|ControlMask,         XK_l,      moveresizeedge, {.v = "r"} },
        { Mod1Mask|ControlMask|ShiftMask,  XK_k,      moveresizeedge, {.v = "T"} },
        { Mod1Mask|ControlMask|ShiftMask,  XK_j,      moveresizeedge, {.v = "B"} },
        { Mod1Mask|ControlMask|ShiftMask,  XK_h,      moveresizeedge, {.v = "L"} },
        { Mod1Mask|ControlMask|ShiftMask,  XK_l,      moveresizeedge, {.v = "R"} },
        { 0,                       XF86XK_MonBrightnessUp,   spawn, {.v = (const char*[]){ "brightnessctl", "set", "10%+", NULL } } },
        { 0,                       XF86XK_MonBrightnessDown,   spawn, {.v = (const char*[]){ "brightnessctl", "set", "10%-", NULL } } },
    	{ 0,                       XF86XK_AudioLowerVolume, spawn, {.v = (const char*[]){ "/usr/bin/amixer", "-D", "pulse", "sset", "Master", "5%-", NULL } } },
    	{ 0,                       XF86XK_AudioMute, spawn, {.v = (const char*[]){ "/usr/bin/amixer", "-D", "pulse", "sset", "Master", "toggle", NULL } } },
    	{ 0,                       XF86XK_AudioRaiseVolume, spawn, {.v = (const char*[]){"/usr/bin/amixer", "-D", "pulse", "sset", "Master", "5%+",     NULL } } },
	{ 0,                       XF86XK_AudioMicMute,        spawn, {.v = (const char*[]){ "/usr/bin/amixer", "-D", "pulse", "sset", "Capture", "toggle", NULL } } },
	{ 0,                       XF86XK_Tools,               spawn, {.v = (const char *[]){"lxqt-config", NULL} } },
	{ 0,                       XF86XK_Explorer,            spawn, {.v = (const char *[]){"/usr/bin/rofi", "-show", "drun", NULL } } },
	{ 0,                       XK_Print,          spawn, {.v = (const char*[]){ "/usr/bin/rofi", "-show", "drun", NULL } } },
	{ 0,                       XF86XK_Search,     spawn, {.v = (const char*[]){ "fsearch", NULL } } },
	{ 0,                       XF86XK_Display,    spawn, {.v = (const char*[]){ "arandr", NULL } } },
	{ MODKEY,                  XF86XK_AudioRaiseVolume,    spawn, {.v = (const char*[]){ "/usr/bin/amixer", "-D", "pulse", "sset", "Master", "1%+", NULL } } },
	{ MODKEY,                  XF86XK_AudioLowerVolume,    spawn, {.v = (const char*[]){ "/usr/bin/amixer", "-D", "pulse", "sset", "Master", "1%-", NULL } } },
	{ MODKEY,                  XK_Escape,         spawn, {.v = (const char*[]){ "off", NULL } } },
	{ MODKEY,                  XK_Print,          spawn, {.v = (const char*[]){ "scrot", NULL } } },
	{ MODKEY,                  XF86XK_AudioMute,    spawn, {.v = (const char*[]){ "pavucontrol", NULL } } },
	{ MODKEY,                  XK_w,     spawn, {.v = (const char*[]){"firefox", NULL} } },
        { MODKEY,                  XK_d,            spawn, {.v = (const char*[]){"rofi", "-show", "drun", NULL } } },
	{ MODKEY,                  XK_v,             spawn, {.v = (const char*[]){"sudo","systemctl", "suspend", NULL } } },
	{ MODKEY,                  XK_z,       spawn,   {.v = (const char*[]){"slock", NULL } } },
	{ MODKEY|ShiftMask,        XK_w,      spawn,    {.v = (const char*[]){ TERMINAL, "sudo", "nmtui",  NULL } } },
	{ MODKEY,                  XK_r,      spawn,    {.v = (const char*[]){ TERMINAL, "sudo", "htop",   NULL } } },
	{ MODKEY,		   XK_n,	   spawn,    {.v = (const char*[]){ TERMINAL,  "nvim", NULL } } },
	{ MODKEY,                  XK_x,      spawn,    {.v = (const char*[]){"urxvt", NULL } } },
	{ MODKEY,                  XK_a,      spawn,    {.v = (const char*[]){"pcmanfm", NULL } } },
	{ MODKEY,                  XK_m,      spawn,    {.v = (const char*[]){ "mousam", NULL } } },
	{ MODKEY,                  XK_g,      spawn,    {.v = (const char*[]){ "gedit", NULL } } },
	{ MODKEY,                  XK_F11,    spawn,    {.v = (const char*[]){ "nitrogen", NULL } } },
	{ MODKEY,                  XK_backslash, spawn, {.v = (const char*[]){ "lxmusic", NULL } } },
	{ MODKEY,                  XF86XK_LaunchA,    spawn,    {.v = (const char*[]){ "thunderbird", NULL } } },
	{ MODKEY,                  XK_e,         spawn,    {.v = (const char*[]){ TERMINAL, "lf", NULL } } },
        { MODKEY,                  XK_bracketleft, spawn,   {.v = (const char*[]){ "xmms2", "prev", NULL } } },
        { MODKEY,                  XK_bracketright, spawn,   {.v = (const char*[]){ "xmms2", "next", NULL } } },
        { MODKEY,                  XK_semicolon, spawn,   {.v = (const char*[]){ "xmms2", "pause", NULL } } },
        { MODKEY,                  XK_apostrophe, spawn,   {.v = (const char*[]){ "xmms2", "play", NULL } } },
	{ MODKEY,                  XK_Prior,     viewprev, {0} },
	{ MODKEY,                  XK_Next,      viewnext, {0} },
	{ MODKEY,                  XK_Home, aspectresize, {.v = (float []){10}} }, // Decrease size while preserving aspect ratio
        { MODKEY,                  XK_End,  aspectresize, {.v = (float []){-10}} },  // Increase size while preserving aspect ratio
};

/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button1,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

