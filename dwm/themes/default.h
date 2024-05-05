static const char black[]       = "#181818";
static const char gray2[]       = "#005577";
static const char gray3[]       = "#bbbbbb";
static const char gray4[]       = "#eeeeee";
static const char blue[]        = "#005577"; //OG #005577  #1E1E2E
static const char *colors[][3]      = {
	//               fg     bg    border
	[SchemeNorm] = { gray3, black, blue },
	[SchemeSel]  = { gray4, blue,  gray2  },
	[SchemeHid]  = { blue,  black, blue  },
};

