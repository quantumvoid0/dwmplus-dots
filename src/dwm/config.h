void dwindle(Monitor *m);
void floating(Monitor *m);
void togglefullscr(const Arg *arg);
static void cyclelayout(const Arg *arg);

static const unsigned int borderpx  = 1;        
static const unsigned int snap      = 32;      
static const int showbar            = 0;       
static const int topbar             = 0;       
static const char *fonts[]          = { "FiraCodeNerdFontMono-Regular:size=10" };
static const char col_bg[] 	    = "#111111";
static const char col_border[]      = "#ffffff";
static const char col_color[]       = "#eeeeee";
static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm] = { col_color, col_bg, col_border },
	[SchemeSel]  = { col_color, col_bg,  col_border  },
};

static const int vertpadinside = 10;   
static const int sidepadinside = 10; 	
static const int vertpad = 10;  
static const int sidepad = 15;   


static const char *tags[] = { "1", "2", "3", "4", "5" };

static const Rule rules[] = {
	{ "NULL",     NULL,       NULL,       0,            0,           -1 },
};

static const int resizehints = 1;    
static const int lockfullscreen = 1; 
static const int refreshrate = 120;  

static const Layout layouts[] = {
	{ "[D]",      dwindle },
	{ "[F]",      floating },
};

#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

static const char *term[]  = { "st", NULL };
static const char *ranger[]  = { "sh", "-c", "st ranger",  NULL };
static const char *web[]  = { "sh", "-c", "firefox", NULL };
static const char *vim[]  = { "sh", "-c", "st vim", NULL };
static const char *sss[]  = { "sh", "-c", "scrot -f -s /home/void/Pictures/img.png --exec 'xclip -selection clipboard -t image/png -i $f'", NULL };
static const char *ss[]  = { "sh", "-c", "scrot -f /home/void/Pictures/img.png --exec 'xclip -selection clipboard -t image/png -i $f'", NULL };
static const char *up[]  = { "sh", "-c", "pactl set-sink-volume @DEFAULT_SINK@ +5%", NULL };
static const char *down[]  = { "sh", "-c", "pactl set-sink-volume @DEFAULT_SINK@ -5%", NULL };
static const char *rofiapps[]  = { "sh", "-c", "rofi -show drun", NULL };
static const char *rofiwindow[]  = { "sh", "-c", "rofi -show window", NULL };
static const char *rofirun[]  = { "sh", "-c", "rofi -show run", NULL };


static const char *playpause[]  = { "sh", "-c", "playerctl play-pause", NULL };
static const char *next[]  = { "sh", "-c", "playerctl next", NULL };
static const char *prev[]  = { "sh", "-c", "playerctl previous", NULL };

static const Key keys[] = {
	{ MODKEY,	                XK_t,     spawn,      {.v = term } },
	{ MODKEY,	                XK_e,     spawn,      {.v = ranger } },
	{ MODKEY,	                XK_f,     spawn,      {.v = web } },
	{ MODKEY,	                XK_v,     spawn,      {.v = vim } },
	{ MODKEY,		        XK_Print, spawn,      {.v = sss } },
	{ MODKEY,		        XK_a,     spawn,      {.v = rofiapps } },
	{ MODKEY,		        XK_Tab,     spawn,      {.v = rofiwindow } },
	{ MODKEY,		        XK_r,     spawn,      {.v = rofirun } },

	{ MODKEY,              		XK_Return,      togglefullscr, {0} },


	{ 0,	     		        XK_Print, 		 spawn,      	{.v = ss } },
	{ 0, 				XF86XK_AudioPlay, 	 spawn,      	{.v = playpause } },
	{ 0,		                XF86XK_AudioRaiseVolume, spawn,      	{.v = up } },
	{ 0,		                XF86XK_AudioLowerVolume, spawn,      	{.v = down } },
	{ 0,		                XF86XK_AudioPrev, 	 spawn,      	{.v = prev } },
	{ 0,		                XF86XK_AudioNext, 	 spawn,      	{.v = next } },

{ MODKEY, XK_space, cyclelayout, {.i = +1} },


	{ MODKEY,                       XK_l,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_j,      focusstack,     {.i = -1 } },
	{ MODKEY,	                XK_q,      killclient,     {0} },
	{ MODKEY,             		XK_Return, togglefloating, {0} },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
	{ MODKEY|ShiftMask,             XK_q,      quit,           {0} },
};

static const Button buttons[] = {
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = term } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

