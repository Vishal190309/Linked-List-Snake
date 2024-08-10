#pragma once
#include <SFML/System/Vector2.hpp>
#include "LinkedList/Node.h"
#include "Player/Direction.h"

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
		int linked_list_size;

		sf::Vector2i default_position;
		Player::Direction default_direction = Player::Direction::RIGHT;

		Node* createNode();

		void shiftNodesAfterInsertion(Node* new_node, Node* cur_node, Node* prev_node);
		int findMiddleNode();
		Node* findNodeAtIndex(int index);
		Player::Direction getReverseDirection(Player::Direction reference_direction);
		void reverseNodeDirections();
		
	public:
		SingleLinkedList();
		~SingleLinkedList();

		void initialize(float width, float height, sf::Vector2i position, Player::Direction direction);
		void initializeNode(Node* new_node, Node* reference_node, Operation operation);
		void render();

		sf::Vector2i getNewNodePosition(Node* reference_node, Operation operation);
		void insertNodeAtHead();
		void insertNodeAtTail();
		void insertNodeAtIndex(int index);
		void insertNodeAtMiddle();
		void removeHalfNodes();
		void updateNodeDirection(Player::Direction direction_to_set);
		void updateNodePosition();
		bool processNodeCollision();
		void removeNodeAtHead();
		void shiftNodesAfterRemoval(Node* cur_node);
		void removeNodeAtIndex(int index);
		void removeNodeAtTail();
		void removeNodeAtMiddle();
		void removeAllNodes();
		Player::Direction reverse();
		Node* getHeadNode();
		std::vector<sf::Vector2i> getNodesPositionList();
	};
}