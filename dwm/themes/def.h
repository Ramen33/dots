static const char col_gray1[]       = "#181818"; //OG #222222
static const char col_gray2[]       = "#005577"; //OG #444444
static const char col_gray3[]       = "#bbbbbb";
static const char col_gray4[]       = "#eeeeee";
static const char col_cyan[]        = "#1E1E2E"; //OG #005577 Purple #8D6298 Bl#2e3e64 C #1E1E2E */
static const char *colors[][3]      = {
	//               fg         bg         border
	[SchemeNorm] = { col_gray3, col_gray1, col_cyan },
	[SchemeSel]  = { col_gray4, col_cyan,  col_gray2  },
	[SchemeHid]  = { col_cyan,  col_gray1, col_cyan  },
};

