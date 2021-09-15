/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_avlNode.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdupont <gdupont@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 12:49:25 by gdupont           #+#    #+#             */
/*   Updated: 2021/09/14 11:16:06 by gdupont          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_AVLNODE_HPP
#define FT_AVLNODE_HPP

#include "ft_pair.hpp"
#include "iostream"

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
	bool isEndNode(struct s_node<T> *node) {       // see ft::pair<iterator, bool> insert( const value_type& value ) from ft_map.hpp for explanations
		if (!node)
			return (0);
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
		return (node);
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
			if (!(current->data) || (!compare(data.first, current->data->first) && !compare(current->data->first, data.first)))
				break ;
			else if (compare(data.first, current->data->first))
			{
				if (current->left)
					current = current->left;
				else
					return (NULL);
			}
			else
			{
				if (current->right && !isEndNode(current->right))
					current = current->right;
				else
					return (NULL);
			}
		}
		return (current);
	}

	
	template <class T>
	struct s_node<T> *getRootNode(struct s_node<T> *node) {
		for (; node->parent; node = node->parent)
			;
		return (node);
	}

	template <class T, class compare>
	bool compare2NodesNchilds(struct s_node<T> *node1, struct s_node<T> *node2, compare comp) {
		if ((!node1 && !node2))
			return (1);
		if (!nodesAreEqual(node1, node2, comp))
			return (0);
		return (compare2NodesNchilds(node1->left, node2->left, comp) && compare2NodesNchilds(node1->right, node2->right, comp));
	}

	template <class T, class compare>
	bool nodesAreEqual(struct s_node<T> *node1, struct s_node<T> *node2, compare comp) {
		if ((!node1 && !node2) || (isEndNode(node1) && isEndNode(node2)))
			return (1);
		if ((!node1 && node2) || 
			(!node2 && node1) || 
			(!isEndNode(node1) && isEndNode(node2)) || 
			(isEndNode(node1) && !isEndNode(node2)) )
			return (0);
		if ( comp(node1->data->first, node2->data->first) || 
						comp(node2->data->first, node1->data->first) )
			return (0);
		return (1);
	}
}

# endif