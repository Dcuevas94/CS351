#include <stdlib.h>
#include <stdio.h>
#include "graph.h"

int main (int argc, char *argv[]) {
	vertex_t *vertexList_head=NULL, *visited_list=NULL, *temp;
	//checking if file is empty or invalid
	if(((argc-1) % 3) !=0){
		printf("Invalid Input file\nQuitting the Program\n");
		return 0;
	}
	visited_list=NULL;
	int i,j;
	for(i=1; i<argc; i+=3){
		add_edge(&vertexList_head, argv[i], argv[i+1], atoi(argv[i+2]));
	}

	i=count_v(vertexList_head);
	j=find_tour(vertexList_head, i, &visited_list);

	printList(vertexList_head);
	printf("\nTours: ");
	for(temp=visited_list; temp !=NULL; temp=temp->next){
		printf("%s\n", temp->name );
	}
	printf("\nWeight: %d\n", j);
	//free it all!!
	free_list(vertexList_head);
	free_list(visited_list);
	return 0;
}
