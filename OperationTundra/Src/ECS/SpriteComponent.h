#pragma once

#include "Components.h"
#include "SDL.h"

class SpriteComponent : public Component
{
private:
	TransformComponent* transform;
	SDL_Texture *texture;
	SDL_Rect srcRect, destRect;

public:
	SpriteComponent() = default;
	SpriteComponent(const char* path)
	{
		setTex(path);
	}

	void setTex(const char* path)
	{
		texture = TextureManager::LoadTexture(path);
	}

	void init() override
	{
		transform = &entity->getComponent<TransformComponent>();

		srcRect.x = srcRect.y = 0; //initialize
		srcRect.w = srcRect.h = 32;
		destRect.w = destRect.h = 64;
	}

	void update() override
	{
		destRect.x = transform->x();
		destRect.y = transform->y();
		//https://youtu.be/ESNN57ofa3w?list=PLhfAbcv9cehhkG7ZQK0nfIGJC_C-wSLrx&t=184
	}

	void draw() override
	{
		TextureManager::Draw(texture, srcRect, destRect);
	}

};