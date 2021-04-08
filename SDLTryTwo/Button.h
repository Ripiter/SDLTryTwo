#pragma once
#include "TextImage.h"
#include "RenderEntity.h"
class Button : public RenderEntity
{
public:
	Button(char* _entityName, TextImage* _img, float _x, float _y);
	// Inherited via IPressButton
	void ButtonEvent(int x, int y);

	void OnClick();



	// Inherited via RenderEntity
	virtual void Update() override;

};
class IHover {
	virtual void ButtonHover(int x, int y) = 0;
};
