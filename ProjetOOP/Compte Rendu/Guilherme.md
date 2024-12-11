# Compte rendu
## ...
- Wrote the basic program, already with the animated road (but in the wrong direction).

## Friday, November 29, 2024
- Wrote the documentation to show the teacher.
- Configured SDL in Xcode.

## Tuesday, December 11, 2024
- Created this document to take notes of progress.
- Rewrote the documentation in MD format to improve readability.
- Decided to use VS Code instead of Xcode because it was not working properly on Jarod's PC.

c++ -o main ProjetOOP/main.cpp -I/usr/local/include -L/usr/local/lib -lSDL2
c++ -std=c++23 c++ -o main ProjetOOP/main.cpp -I/usr/local/include -L/usr/local/lib -lSDL2

/Library/Frameworks/SDL2.framework


g++ main.cpp -o main [--prefix[=DIR]] [--exec-prefix[=DIR]] [--version] [--cflags] [--libs] [--static-libs]

g++ main.cpp -o main -L/opt/homebrew/lib -lSDL2

-I/opt/homebrew/include/SDL2

g++ main.cpp -o main -I/opt/homebrew/include/SDL2/SDL.h -L/opt/homebrew/lib -lSDL2


sdl2-config --cflags
sdl2-config --libs


g++ main.cpp -o main -I/opt/homebrew/include/SDL2/SDL.h -L/opt/homebrew/lib /opt/homebrew/lib/libSDL2.a -lm -Wl,-framework,CoreAudio -Wl,-framework,AudioToolbox -Wl,-weak_framework,CoreHaptics -Wl,-weak_framework,GameController -Wl,-framework,ForceFeedback -lobjc -Wl,-framework,CoreVideo -Wl,-framework,Cocoa -Wl,-framework,Carbon -Wl,-framework,IOKit -Wl,-weak_framework,QuartzCore -Wl,-weak_framework,Metal