#include "Headers/InputHandler.h"

bool InputHandler::handleEvents()
{
	while (SDL_PollEvent(&mEventHandler))
	{
		if (mEventHandler.type == SDL_QUIT)
			return true;
		else if (mEventHandler.type == SDL_KEYDOWN)
		{
			if(mEventHandler.key.keysym.sym == SDLK_ESCAPE)
				return true;
			//setColorByKey(e, r, g, b);
		}
	}
	return false;
}