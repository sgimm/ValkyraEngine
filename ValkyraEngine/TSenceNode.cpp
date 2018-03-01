#include "TSenceNode.h"


TSenceNode::TSenceNode(TComponent* owner, void * parent, TMiracle* mirc):TComponent(owner, parent, mirc)
{
	m_szClassName = "TSenceNode";
}

TSenceNode::~TSenceNode()
{
}
