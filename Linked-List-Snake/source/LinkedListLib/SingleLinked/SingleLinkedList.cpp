#include "LinkedListLib/SingleLinked/SingleLinkedList.h"
#include "Player/BodyPart.h"
#include "Player/Direction.h"
#include "Level/LevelView.h"
#include "LinkedListLib/SingleLinked/SingleNode.h"

namespace LinkedListLib
{
	namespace SingleLinked {
		using namespace Player;
		SingleLinkedList::SingleLinkedList()
		{
			head_node = nullptr;
		}

		SingleLinkedList::~SingleLinkedList() = default;

		Node* SingleLinkedList::createNode()
		{
			return new SingleNode();
		}

		void SingleLinkedList::insertNodeAtHead() {
			linked_list_size += 1;
			Node* new_node = createNode();

			if (head_node == nullptr) {
				head_node = new_node;
				initializeNode(new_node, nullptr, Operation::HEAD);
				return;
			}
			initializeNode(new_node, head_node, Operation::HEAD);
			new_node->next = head_node;
			head_node = new_node;

		}

		void SingleLinkedList::insertNodeAtTail() {
			linked_list_size++;
			Node* new_node = createNode();
			Node* cur_node = head_node;

			if (cur_node == nullptr) {       // If the list is empty, set the new node as the head
				head_node = new_node;
				initializeNode(new_node, nullptr, Operation::TAIL);
				return;
			}

			// Traverse to the end of the list 
			while (cur_node->next != nullptr) {
				cur_node = cur_node->next;
			}
			// Attach the new node at the end
			cur_node->next = new_node;
			initializeNode(new_node, cur_node, Operation::TAIL);

		}

		void SingleLinkedList::insertNodeAtIndex(int index) {

			if (index < 0 || index >= linked_list_size) return;

			if (index == 0) {
				insertNodeAtHead();
				return;
			}

			Node* new_node = createNode();
			int current_index = 0;
			Node* cur_node = head_node;
			Node* prev_node = nullptr;

			while (cur_node != nullptr && current_index < index)
			{
				prev_node = cur_node;
				cur_node = cur_node->next;
				current_index++;
			}

			prev_node->next = new_node;
			new_node->next = cur_node;
			initializeNode(new_node, prev_node, Operation::TAIL);
			linked_list_size++;
			shiftNodesAfterInsertion(new_node, cur_node, prev_node);
		}

		void SingleLinkedList::shiftNodesAfterInsertion(Node* new_node, Node* cur_node, Node* prev_node)
		{
			Node* next_node = cur_node;
			cur_node = new_node;

			while (cur_node != nullptr && next_node != nullptr)
			{
				cur_node->body_part.setPosition(next_node->body_part.getPosition());
				cur_node->body_part.setDirection(next_node->body_part.getDirection());

				prev_node = cur_node;
				cur_node = next_node;
				next_node = next_node->next;
			}

			initializeNode(cur_node, prev_node, Operation::TAIL);
		}
		void SingleLinkedList::removeHalfNodes()
		{
			if (linked_list_size <= 1) return;
			int half_length = linked_list_size / 2;
			int new_tail_index = half_length - 1;

			Node* prev_node = findNodeAtIndex(new_tail_index);
			Node* cur_node = prev_node->next;

			while (cur_node != nullptr)
			{
				Node* node_to_delete = cur_node;
				cur_node = cur_node->next;

				delete (node_to_delete);
				linked_list_size--;
			}

			prev_node->next = nullptr;
		}

		void SingleLinkedList::insertNodeAtMiddle()
		{
			if (head_node == nullptr) {
				insertNodeAtHead();             // If the list is empty, insert at the head.
				return;
			}

			int midIndex = findMiddleNode();    // Use the existing function to find the middle index
			insertNodeAtIndex(midIndex);             // Use the existing function to insert the node at the found index             
		}

		
		void SingleLinkedList::removeNodeAtHead()
		{
			Node* cur_node = head_node;
			head_node = head_node->next;

			cur_node->next = nullptr;
			delete (cur_node);
			linked_list_size--;
		}


		void SingleLinkedList::shiftNodesAfterRemoval(Node* cur_node)
		{
			sf::Vector2i previous_node_position = cur_node->body_part.getPosition();
			Direction previous_node_direction = cur_node->body_part.getDirection();
			cur_node = cur_node->next;

			while (cur_node != nullptr)
			{
				sf::Vector2i temp_node_position = cur_node->body_part.getPosition();
				Direction temp_node_direction = cur_node->body_part.getDirection();

				cur_node->body_part.setPosition(previous_node_position);
				cur_node->body_part.setDirection(previous_node_direction);

				cur_node = cur_node->next;
				previous_node_position = temp_node_position;
				previous_node_direction = temp_node_direction;
			}
		}

		void SingleLinkedList::removeNodeAt(int index)
		{
			if (index < 0 || index >= linked_list_size) return;

			if (index == 0)
			{
				removeNodeAtHead();
			}
			else
			{
				removeNodeAtIndex(index);
			}
		}

		void SingleLinkedList::removeNodeAtIndex(int index)
		{
			linked_list_size--;
			int current_index = 0;
			Node* cur_node = head_node;
			Node* prev_node = nullptr;

			while (cur_node != nullptr && current_index < index)
			{
				prev_node = cur_node;
				cur_node = cur_node->next;
				current_index++;
			}

			prev_node->next = cur_node->next;

			shiftNodesAfterRemoval(cur_node);
			delete(cur_node);
		}

		void SingleLinkedList::removeNodeAtTail() {
			if (head_node == nullptr) return;

			if (head_node->next == nullptr) {
				removeNodeAtHead();
				return;
			}

			linked_list_size--;
			Node* curr_node = head_node;

			while (curr_node != nullptr && curr_node->next->next != nullptr)
			{
				curr_node = curr_node->next;
			}

			delete(curr_node->next);
			curr_node->next = nullptr;
		}

		void SingleLinkedList::removeNodeAtMiddle()
		{
			if (head_node == nullptr) return;

			int midIndex = findMiddleNode();    // Use the existing function to find the middle index
			removeNodeAtIndex(midIndex);             // Use the existing function to insert the node at the found index             
		}

		void SingleLinkedList::removeAllNodes()
		{
			if (head_node == nullptr) return;

			while (head_node != nullptr)
			{
				removeNodeAtHead();
			}
		}


		void SingleLinkedList::reverseNodeDirections()
		{
			Node* curr_node = head_node;

			while (curr_node != nullptr)
			{
				curr_node->body_part.setDirection(getReverseDirection(curr_node->body_part.getPreviousDirection()));
				curr_node = curr_node->next;
			}
		}

		Direction SingleLinkedList::reverse()
		{
			Node* cur_node = head_node;
			Node* prev_node = nullptr;
			Node* next_node = nullptr;

			while (cur_node != nullptr)
			{
				next_node = cur_node->next;
				cur_node->next = prev_node;

				prev_node = cur_node;
				cur_node = next_node;
			}

			head_node = prev_node;

			reverseNodeDirections();
			return head_node->body_part.getDirection();
		}

	}
}
