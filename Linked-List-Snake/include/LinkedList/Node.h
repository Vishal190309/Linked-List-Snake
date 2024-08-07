#pragma once
#include "Player/BodyPart.h"

namespace LinkedList {
	struct Node
	{
		Player::BodyPart body_part;
		Node* next = nullptr;
	};
}