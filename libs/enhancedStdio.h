int printfflush(const char *format, ...) {
    va_list arg;
    int done;
    va_start(arg, format);
    done = vprintf(format, arg);
    fflush(stdout);
    va_end(arg);
    return done;
}

int scanfrewind(const char *format, ...) {
    va_list arg;
    int done;
    va_start(arg, format);
    done = vscanf(format, arg);
    rewind(stdin);
    va_end(arg);
    return done;
}

void clearScreen() {
    const char *CLEAR_SCREEN_ANSI = "\e[1;1H\e[2J";
    write(STDOUT_FILENO, CLEAR_SCREEN_ANSI, 12);
}

void colorGreen() { printfflush("\033[1;92m"); }

void colorCyan() { printfflush("\033[1;36m"); }

void colorReset() { printfflush("\033[0m"); }