#include <stdio.h>

typedef struct Stack{
	int b[7];
	int p;
	int q;
}Stack;

int a[7][7] = {
	0, 1, 1, 1, 1, 1, 0,
	0, 0, 0, 0, 0, 1, 0,
	0, 0, 0, 1, 1, 0, 0,
	0, 0, 0, 0, 1, 1, 0,
	0, 0, 0, 0, 0, 1, 0,
	0, 0, 0, 0, 0, 0, 0,
	0, 0, 0, 0, 0, 0, 0,
};

int Is_Legal(int *a, Stack *map){
	int i = 0, j = 0;
	for (i = 0; i < map->p; i++){
		for (j = i+1; j < map->p; j++){
			if (*(a+7*i+j) == 1 && map->b[j] == map->b[i]) return 0; //Illegal
		}
	}
	return 1; //Legal
}

void Push(Stack *s, int e){
	s->b[s->p] = e;
	s->p++;
}

void Pop(Stack *s){
	s->p--;
}

int Is_Full(Stack *s){
	if (s->p == 7) return 1;
	else return 0;
}

int main(){
	int i;
	Stack map;
	map.p = 0;
	map.q = 0;
	Push(&map, 1);
	while ( !Is_Full(&map) ){
		Push(&map, 1);
		while ( !Is_Legal(&a, &map) && map.b[map.p-1] <= 4){
			Pop(&map);
			Push(&map, map.b[map.p]+1);
		}
		while ( map.b[map.p - 1] == 5){
			Pop(&map);
			map.b[map.p-1]++;
		}
	}

	for (i = 0; i < 7; i++)
		printf("%d ", map.b[i]);

	return 0;
}

