g++ -fdiagnostics-color=always -g -Wall CPPs\\*.cpp -o build/game -Iinclude/SDL2 -Iinclude -Llib -Wl,-subsystem,windows -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer
cd build
game
cd ..