#pragma once
#include <SFML/System/Vector2.hpp>
#include "LinkedList/Node.h"

namespace LinkedList
{
	enum class Operation
	{
		HEAD,
		MID,
		TAIL,
	};

	class SingleLinkedList
	{
	private:
		Node* head_node;

		float node_width;
		float node_height;

		sf::Vector2i default_position;
		Player::Direction default_direction = Player::Direction::RIGHT;

		Node* createNode();

		

	public:
		SingleLinkedList();
		~SingleLinkedList();

		void initialize(float width, float height, sf::Vector2i position, Player::Direction direction);
		void initializeNode(Node* new_node, Node* reference_node, Operation operation);
		void render();

		sf::Vector2i getNewNodePosition(Node* reference_node, Operation operation);
		void insertNodeAtTail();
		void updateNodeDirection(Player::Direction direction_to_set);
		void updateNodePosition();
		bool processNodeCollision();
		void removeNodeAtHead();
		void removeAllNodes();
		Node* getHeadNode();
		std::vector<sf::Vector2i> getNodesPositionList();
	};
}