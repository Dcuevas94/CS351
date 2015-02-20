#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "graph.h"

void add_edge (vertex_t **vtxhead, char *v1_name, char *v2_name, int weight) {
	vertex_t *a, *b;
	adj_vertex_t *adj_v;
	b=find_vertex(vtxhead,v2_name);
	a=find_vertex(vtxhead,v1_name);
	int i=1;
	if(b->adj_list==NULL){
		adj_v=b->adj_list=malloc(sizeof(adj_vertex_t));
		adj_v->vertex=a;
		adj_v->edge_weight=weight;
		adj_v->next=NULL;
		i=0;
	}
	adj_v=b->adj_list;
	while(i){
		if(adj_v->next ==NULL){
			adj_v=adj_v->next=malloc(sizeof(adj_vertex_t));
			adj_v->vertex=a;
			adj_v->edge_weight=weight;
			adj_v->next=NULL;
			i=0;
		}
		adj_v=adj_v->next;
	}
	i=1;
	if(a->adj_list==NULL){
		adj_v=a->adj_list=malloc(sizeof(adj_vertex_t));
		adj_v->vertex=b;
		adj_v->edge_weight=weight;
		adj_v->next=NULL;
		i=0;
	}
	adj_v=a->adj_list;
	while(i){
		if(adj_v->next ==NULL){
			adj_v=adj_v->next=malloc(sizeof(adj_vertex_t));
			adj_v->vertex=b;
			adj_v->edge_weight=weight;
			adj_v->next=NULL;
			i=0;
		}
		adj_v=adj_v->next;
	}
}

void printList(vertex_t *head){
	printf("Adjacency list:\n");
	vertex_t *vp;
	adj_vertex_t *adj_v;
	for (vp = head; vp != NULL; vp = vp->next) {
		printf("  %s: ", vp->name);
		for (adj_v = vp->adj_list; adj_v != NULL; adj_v = adj_v->next) {
			printf("%s(%d) ", adj_v->vertex->name, adj_v->edge_weight);
		}
		printf("\n");
	}
}

vertex_t* find_vertex(vertex_t **v, char *name){
	vertex_t *vp;
	for(vp=*v; vp !=NULL; vp=vp->next){
		if(strcmp((vp->name),name)==0)
			return vp;
	}
	vp=malloc(sizeof(vertex_t));
	vp->name=name;
	vp->next=*v;
	*v=vp;
	return vp;
}

vertex_t* make(vertex_t **v, char *name){
	vertex_t *vp=malloc(sizeof(vertex_t));
	vp->name=name;
    vp->next=*v;
    *v=vp;
    return vp;
}

vertex_t* find(vertex_t *v, char *name){
 	vertex_t *vp;
    for(vp=v; vp !=NULL; vp=vp->next){
		if(strcmp((vp->name),name)==0)
			return vp;
	}
	return NULL;
}
int count_v(vertex_t *head){
	int i=0;
	vertex_t *vt;
	for(vt=head; vt!=NULL; vt=vt->next){
		i++;
	}
	return i;
}
int find_tour (vertex_t *vp, int hops, vertex_t **list) {
    char *vtxname;
    vertex_t *tmp;
    adj_vertex_t *adj_v;
    int length;
    if (vp == NULL)
        return 0;
	if(hops==0)
		return 0;
    tmp = make(list, vp->name);
    for (adj_v = vp->adj_list; adj_v; adj_v = adj_v->next) {
        vtxname = adj_v->vertex->name;
        if (find(*list, vtxname) == NULL) {
            if (hops == 1) {
                tmp = make(list, vtxname);
                return (adj_v->edge_weight);
            }
        length = find_tour(adj_v->vertex, hops-1, list);
		return (adj_v->edge_weight) + length;
	    }
    }
	return 0;
}

void free_list(vertex_t *v){
	vertex_t *p;
	adj_vertex_t *adj;
	for(p=v; p!=NULL; p=p->next){
		for(adj=p->adj_list; adj !=NULL; adj=adj->next){
			free(adj);
		}
		free(p);
	}
}
