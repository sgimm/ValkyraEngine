#include "TScene.h"


void TScene::Render()
{
}

void TScene::OnMessage(TMessage message)
{
	TComponent::OnMessage(message);
}

TScene::TScene(TComponent * owner, void * parent):TComponent(owner, parent)
{
}


TScene::~TScene()
{
}
