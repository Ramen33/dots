static const unsigned int borderpx  = 0;
static const unsigned int gappx     = 10;
static const unsigned int snap      = 32;
static const int showbar            = 1;
static const int topbar             = 1;
static const int usealtbar          = 0;
static const char *altbarclass      = "Polybar";
static const char *altbarcmd        = "$HOME/bar.sh";
static const char *fonts[]          = { "JetBrainsMono-Bold:size=7" };
static const char dmenufont[]       = "JetBrainsMono-Bold:size=7";
static unsigned int baralpha        = 0xb0;
static unsigned int borderalpha     = OPAQUE;

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

#include "themes/gruvchad.h"
#include "layouts.c"

static const Layout layouts[] = {
	{ "[]=",      tile         },
	{ "TTT",      bstack       },
	{ "===",      bstackhoriz  },

	{ "><>",      NULL    },
	{ "HHH",      grid    },

	{ "[D]",      deck    },
	{ "[M]",      monocle },

	{ "[@]",      spiral  },
	{ "[\\]",     dwindle },

        { "|M|",      centeredmaster         },
	{ ">M>",      centeredfloatingmaster },
};

#define MODKEY  Mod4Mask
#define ALTKEY  Mod1Mask
#define SHIFT   ShiftMask
#define CONTROL ControlMask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|CONTROL,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|SHIFT,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|CONTROL|SHIFT, KEY,      toggletag,      {.ui = 1 << TAG} },

#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

static char dmenumon[2] = "0";
//static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", col_gray1, "-nf", col_gray3, "-sb", col_cyan, "-sf", col_gray4, NULL };
static const char *termcmd[]  = { "st", NULL };

#include <X11/XF86keysym.h>
#define TERMINAL "st"

static const Key keys[] = {
	{ MODKEY,                       XK_s,      spawn,          {.v = (const char*[]){ "alacritty", NULL } } },
	{ MODKEY,                       XK_Return, spawn,          {.v = (const char*[]){"st", NULL } } },
	{ MODKEY,                       XK_b,      togglebar,      {0} },
	{ MODKEY,                       XK_j,      focusstackvis,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstackvis,     {.i = -1 } },
        { MODKEY|SHIFT,                 XK_j,      focusstackhid,     {.i = +1 } },
        { MODKEY|SHIFT,                 XK_k,      focusstackhid,     {.i = +1 } },
	{ MODKEY,                       XK_period,      incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_slash,      incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
//	{ MODKEY|SHIFT,                 XK_Return, spawn,          {.v = (const char*[]){ "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", col_gray1, "-nf", col_gray3, "-sb", col_cyan, "-sf", col_gray4, NULL } } },
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY,                       XK_q,      killclient,     {0} },
	{ MODKEY,                   XK_t,      setlayout,          {.v = &layouts[0]}  },
	{ MODKEY|SHIFT,             XK_t,      setlayout,          {.v = &layouts[1]}  },
	{ MODKEY|CONTROL,           XK_t,      setlayout,          {.v = &layouts[2]}  },
	{ MODKEY,                   XK_y,      setlayout,          {.v = &layouts[3]}  },
	{ MODKEY|SHIFT,             XK_y,      setlayout,          {.v = &layouts[4]}  },
	{ MODKEY|SHIFT,             XK_u,      setlayout,          {.v = &layouts[5]}  },
	{ MODKEY,                   XK_u,      setlayout,          {.v = &layouts[6]}  },
	{ MODKEY,                   XK_i,      setlayout,          {.v = &layouts[7]}  },
	{ MODKEY|SHIFT,             XK_i,      setlayout,          {.v = &layouts[8]}  },
	{ MODKEY,                   XK_o,      setlayout,          {.v = &layouts[9]}  },
	{ MODKEY|SHIFT,             XK_o,      setlayout,          {.v = &layouts[10]} },
	{ MODKEY|SHIFT,             XK_space,  zoom,                              {0} },
	{ MODKEY,                       XK_space,  togglefloating,                {0} },
	{ MODKEY,                       XK_Down,   moveresize,     {.v = "0x 25y 0w 0h" } },
	{ MODKEY,                       XK_Up,     moveresize,     {.v = "0x -25y 0w 0h" } },
	{ MODKEY,                       XK_Right,  moveresize,     {.v = "25x 0y 0w 0h" } },
	{ MODKEY,                       XK_Left,   moveresize,     {.v = "-25x 0y 0w 0h" } },
	{ MODKEY|SHIFT,             XK_Down,   moveresize,     {.v = "0x 0y 0w 25h" } },
	{ MODKEY|SHIFT,             XK_Up,     moveresize,     {.v = "0x 0y 0w -25h" } },
	{ MODKEY|SHIFT,             XK_Right,  moveresize,     {.v = "0x 0y 25w 0h" } },
	{ MODKEY|SHIFT,             XK_Left,   moveresize,     {.v = "0x 0y -25w 0h" } },
	{ MODKEY|CONTROL,           XK_Up,     moveresizeedge, {.v = "t"} },
	{ MODKEY|CONTROL,           XK_Down,   moveresizeedge, {.v = "b"} },
	{ MODKEY|CONTROL,           XK_Left,   moveresizeedge, {.v = "l"} },
	{ MODKEY|CONTROL,           XK_Right,  moveresizeedge, {.v = "r"} },
	{ MODKEY|CONTROL|SHIFT, XK_Up,     moveresizeedge, {.v = "T"} },
	{ MODKEY|CONTROL|SHIFT, XK_Down,   moveresizeedge, {.v = "B"} },
	{ MODKEY|CONTROL|SHIFT, XK_Left,   moveresizeedge, {.v = "L"} },
	{ MODKEY|CONTROL|SHIFT, XK_Right,  moveresizeedge, {.v = "R"} },
        { ALTKEY,                       XK_bracketleft,  setgaps,        {.i = -1 } },
        { ALTKEY,                       XK_bracketright,  setgaps,        {.i = +1 } },
	{ ALTKEY|SHIFT,             XK_bracketright,  setgaps,        {.i = 0 } },
	{ MODKEY,                       XK_BackSpace,      view,           {.ui = ~0 } },
	{ MODKEY|SHIFT,             XK_BackSpace,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|SHIFT,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|SHIFT,             XK_period, tagmon,         {.i = +1 } },
        { MODKEY|SHIFT,             XK_j,      movestack,      {.i = +1 } },
        { MODKEY|SHIFT,             XK_k,      movestack,      {.i = -1 } },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
	TAGKEYS(                        XK_0,                      9)
	TAGKEYS(                        XK_minus,                  10)
	TAGKEYS(                        XK_equal,                  11)
	{ MODKEY,                       XK_f,      togglefullscreen,  {0} },
	{ ALTKEY,                     XK_j,      moveresize, {.v = "0x 25y 0w 0h"} },
	{ ALTKEY,                     XK_k,      moveresize, {.v = "0x -25y 0w 0h"} },
        { ALTKEY,                     XK_l,      moveresize, {.v = "25x 0y 0w 0h"} },
        { ALTKEY,                     XK_h,      moveresize, {.v = "-25x 0y 0w 0h"} },
	{ ALTKEY|SHIFT,           XK_j,      moveresize, {.v = "0x 0y 0w 25h"} },
	{ ALTKEY|SHIFT,           XK_k,      moveresize, {.v = "0x 0y 0w -25h"} },
	{ ALTKEY|SHIFT,           XK_l,      moveresize, {.v = "0x 0y 25w 0h"} },
	{ ALTKEY|SHIFT,           XK_h,      moveresize, {.v = "0x 0y -25w 0h"} },
	{ ALTKEY|CONTROL,         XK_k,      moveresizeedge, {.v = "t"} },
        { ALTKEY|CONTROL,         XK_j,      moveresizeedge, {.v = "b"} },
        { ALTKEY|CONTROL,         XK_h,      moveresizeedge, {.v = "l"} },
        { ALTKEY|CONTROL,         XK_l,      moveresizeedge, {.v = "r"} },
        { ALTKEY|CONTROL|SHIFT,  XK_k,      moveresizeedge, {.v = "T"} },
        { ALTKEY|CONTROL|SHIFT,  XK_j,      moveresizeedge, {.v = "B"} },
        { ALTKEY|CONTROL|SHIFT,  XK_h,      moveresizeedge, {.v = "L"} },
        { ALTKEY|CONTROL|SHIFT,  XK_l,      moveresizeedge, {.v = "R"} },
	{ MODKEY,                          XK_comma,  view,    {0} },
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
        { MODKEY,                  XF86XK_MonBrightnessUp,   spawn, {.v = (const char*[]){ "brightnessctl", "set", "100%", NULL } } },
        { MODKEY,                  XF86XK_MonBrightnessDown,   spawn, {.v = (const char*[]){ "brightnessctl", "set", "1", NULL } } },
        { MODKEY|SHIFT,        XF86XK_MonBrightnessDown,   spawn, {.v = (const char*[]){ "brightnessctl", "set", "0", NULL } } },
	{ MODKEY|SHIFT,        XK_Escape,         spawn, {.v = (const char*[]){ "off", NULL } } },
	{ MODKEY,                  XK_Print,          spawn, {.v = (const char*[]){ "scrot", NULL } } },
	{ MODKEY,                  XF86XK_AudioMute,    spawn, {.v = (const char*[]){ "pavucontrol", NULL } } },
	{ MODKEY,                  XK_w,     spawn, {.v = (const char*[]){"firefox", NULL} } },
        { MODKEY,                  XK_d,            spawn, {.v = (const char*[]){"rofi", "-show", "drun", NULL } } },
        { MODKEY|SHIFT,            XK_d,            spawn, {.v = (const char*[]){"rofi", "-show", "run", NULL } } },
	{ MODKEY,                  XK_v,             spawn, {.v = (const char*[]){"sudo","systemctl", "suspend", NULL } } },
	{ MODKEY,                  XK_z,       spawn,   {.v = (const char*[]){"slock", NULL } } },
	{ MODKEY|SHIFT,            XK_w,      spawn,    {.v = (const char*[]){ TERMINAL, "sudo", "nmtui",  NULL } } },
	{ MODKEY,                  XK_r,      spawn,    {.v = (const char*[]){ TERMINAL, "sudo", "htop",   NULL } } },
	{ MODKEY,		   XK_n,	   spawn,    {.v = (const char*[]){ TERMINAL,  "nvim", NULL } } },
	{ MODKEY,                  XK_x,      spawn,    {.v = (const char*[]){"urxvt", NULL } } },
	{ MODKEY,                  XK_a,      spawn,    {.v = (const char*[]){"pcmanfm", NULL } } },
	{ MODKEY,                  XK_m,      spawn,    {.v = (const char*[]){ "mousam", NULL } } },
	{ MODKEY,                  XK_g,      spawn,    {.v = (const char*[]){ "gedit", NULL } } },
	{ MODKEY,                  XK_F11,    spawn,    {.v = (const char*[]){ "nitrogen", NULL } } },
	{ MODKEY,                  XK_apostrophe, spawn, {.v = (const char*[]){ TERMINAL,  "ncmpcpp", NULL } } },
	{ ALTKEY,                XK_apostrophe, spawn, {.v = (const char*[]){  "ario", NULL } } },
	{ MODKEY|SHIFT,        XK_apostrophe, spawn, {.v = (const char*[]){ "mpc", "update", NULL } } },
	{ MODKEY,                  XF86XK_LaunchA,    spawn,    {.v = (const char*[]){ "thunderbird", NULL } } },
	{ MODKEY|SHIFT,        XK_a,         spawn,    {.v = (const char*[]){ TERMINAL, "lf", NULL } } },
        { MODKEY,                  XK_bracketleft, spawn,   {.v = (const char*[]){ "mpc", "prev", NULL } } },
        { MODKEY|SHIFT,        XK_bracketleft, spawn,   {.v = (const char*[]){ "mpc", "seek", "-5", NULL } } },
        { MODKEY,                  XK_bracketright, spawn,   {.v = (const char*[]){ "mpc", "toggle", NULL } } },
	{ MODKEY|SHIFT,        XK_bracketright, spawn,   {.v = (const char*[]){ "mpc", "stop", NULL } } },
        { MODKEY,                  XK_backslash, spawn,   {.v = (const char*[]){ "mpc", "next", NULL } } },
        { MODKEY|SHIFT,        XK_backslash, spawn,   {.v = (const char*[]){ "mpc", "seek", "+5", NULL } } },
	{ MODKEY,                  XK_Prior,     viewprev, {0} },
	{ MODKEY,                  XK_Next,      viewnext, {0} },
	{ MODKEY,                  XK_Home, aspectresize, {.v = (float []){10}} },
        { MODKEY,                  XK_End,  aspectresize, {.v = (float []){-10}} },
	{ MODKEY|SHIFT,             XK_e,      quit,           {0} },
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

