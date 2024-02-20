/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenz <kenz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 04:01:02 by kenz              #+#    #+#             */
/*   Updated: 2024/02/20 04:22:43 by kenz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"



int main() {
    // Création de quelques nœuds
    t_node *node1 = (t_node*)malloc(sizeof(t_node));
    t_node *node2 = (t_node*)malloc(sizeof(t_node));
    t_node *node3 = (t_node*)malloc(sizeof(t_node));
    
    // Attribution de valeurs aux champs
    node1->nb = 10;
    node2->nb = 20;
    node3->nb = 30;
    
    // Liaisons entre les nœuds
    node1->next = node2;
    node2->prev = node1;
    node2->next = node3;
    node3->prev = node2;
    node3->next = NULL;
    
    // Affichage des valeurs des champs
    printf("Valeur du premier noeud : %d\n", node1->nb);
    printf("Valeur du deuxième noeud : %d\n", node2->nb);
    printf("Valeur du troisième noeud : %d\n", node3->nb);
    
    // Libération de la mémoire
    free(node1);
    free(node2);
    free(node3);
    
    return 0;
}