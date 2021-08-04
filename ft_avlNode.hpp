/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_avlNode.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdupont <gdupont@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 12:49:25 by gdupont           #+#    #+#             */
/*   Updated: 2021/08/04 16:01:30 by gdupont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_AVLNODE_HPP
#define FT_AVLNODE_HPP

#include "ft_pair.hpp"

namespace ft {

	
	template <class T>
	struct	s_node {

		struct s_node				*parent;
		struct s_node				*left;
		struct s_node				*right;
		T							*data;
		int							height;
		int							balanceFactor;

		s_node(void) : parent(NULL), left(NULL), right(NULL), data(NULL), height(0), balanceFactor(0) {} 
	};

	template <class T>
	bool isEndNode(struct s_node<T> *node) {
		return (!node->data);
	}

	template <class T>
	struct s_node<T> *getRightExtremNode(struct s_node<T> *node) {
		if (!node)
			return (NULL);
		while (node->right && !isEndNode(node->right))
			node = node->right;
		return (node);
	}

	template <class T>
	struct s_node<T> *getLeftExtremNode(struct s_node<T> *node) {
		if (!node)
			return (NULL);
		while (node->left)
			node = node->left;
		return (node);
	}

	template <class T, class comp>
	struct s_node<T> *getSmallestHigherParent(struct s_node<T> *node, comp compare) {
		while (node->parent)
		{
			if (compare(node->data->first, node->parent->data->first))
				return (node->parent);
			node = node->parent;
		}
		return (NULL);
	}

	template <class T, class comp>
	struct s_node<T> *getHighestSmallerParent(struct s_node<T> *node, comp compare) {
		while (node->parent)
		{
			if (!compare(node->data->first, node->parent->data->first))
				return (node->parent);
			node = node->parent;
		}
		return (NULL);
	}

	template <class T, class comp>
	struct s_node<T> *getUpperNode(struct s_node<T> *node, comp compare) {
		if (node->right)
			node = getLeftExtremNode(node->right);
		else
			node = getSmallestHigherParent(node, compare);
		return (node);
	}

	template <class T, class comp>
	struct s_node<T> *getLowerNode(struct s_node<T> *node, comp compare) {

		if (node->left)
			node = getRightExtremNode(node->left);
		else
			node = getHighestSmallerParent(node, compare);
		return (node);
	}

	template <class T, class comp>
	struct s_node<T> *getNode(struct s_node<T> *root, T &data, comp compare) {
		struct s_node<T> *current = root;
	
		while (current) {
			if (!compare(data.first, current->data->first) && !compare(current->data->first, data.first))
				break ;
			else if (compare(data.first, current->data->first))
			{
				if (current->left)
					current = current->left;
				else
					break;
			}
			else
			{
				if (current->right)
					current = current->right;
				else
					break;
			}
		}
		return (current);
	}

	template <class T, class comp>
	void		putTargetInLeaf(struct s_node<T> *target, comp compare) {
		
		if (!target->right && !target->left)
			;
		else if (target->right && isEndNode(target->right))       // end_node special case
		{
			std::cout << "je ne dois passer ici\n";
			if (target->parent)
				target->parent->right = target->right;
			target->right->parent = target->parent;
		}
		else if (target->left && !target->right)
			swapWithChild(target, target->left);
		else if (target->right && !target->left)
			swapWithChild(target, target->right);
		else
		{
			std::cout << "je dois passer ici\n";
			swapNodePos(target, getUpperNode(target, compare));
			//putTargetInLeaf(target, compare);
		}
	}

	template <class T>
	void	swapNodePos(struct s_node<T> *node1, struct s_node<T> *node2) {
		struct s_node<T> *parent = node1->parent;
		struct s_node<T> *right = node1->right;
		struct s_node<T> *left = node1->left;
		if (node1->parent)
		{
			if (node1->parent->left == node1)
				node1->parent->left = node2;
			else
				node1->parent->right = node2;			
		}
		if (node1->left)
			node1->left->parent = node2;
		if (node1->right)
			node1->right->parent = node2;
		if (node2->parent)
		{
			if (node2->parent->left == node2)
				node2->parent->left = node1;
			else
				node2->parent->right = node1;			
		}
		if (node2->left)
			node2->left->parent = node1;
		if (node2->right)
			node2->right->parent = node1;
		node1->parent = node2->parent;
		node2->parent = parent;
		node1->right = node2->right;
		node2->right = right;
		node1->left = node2->left;
		node2->left = left;
	}

		template <class T>
	void	swapWithChild(struct s_node<T> *node, struct s_node<T> *child) {
		struct s_node<T> *gparent = node->parent;
		struct s_node<T> *right = node->right;
		struct s_node<T> *left = node->left;
		

		std::cout << "coucoiiiiii'\n";
		child->parent = gparent;
		if (gparent->left == node)
			gparent->left = child;
		else
			gparent->right = child;
		node->left = child->left;
		node->right = child->right;
		node->parent = child;
		if (right == child)
		{
			child->right = node;
			child->left = right;
		}
		else
		{
			child->left = node;
			child->right = left;
		}
		node->left->parent = node;
		node->right->parent = node;
		
	}
	
	template <class T>
	struct s_node<T> *getRootNode(struct s_node<T> *node) {
		for (; node->parent; node = node->parent)
			;
		return (node);
	}
}

# endif