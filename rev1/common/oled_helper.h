#ifdef OLED_DRIVER_ENABLE

void render_logo(void);

#    define RENDER_LOGO(a) render_logo(a)

#else

#    define RENDER_LOGO(a)

#endif