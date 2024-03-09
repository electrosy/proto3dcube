#include <SDL2/SDL.h>


namespace ley {

class Transform
{

private:

public:
    Transform();

    SDL_FPoint rotate(SDL_FPoint r, float a);

};
}