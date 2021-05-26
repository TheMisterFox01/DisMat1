#include <stdio.h>
#include <malloc.h>
#include <string.h>

#pragma warning(disable : 4996)


struct Note {

	struct Note* next;
	char* data;

};


struct List {

	struct Note* First;
	char* name;

};

struct Note* CreateNote(char *data) {

	int i;

	struct Note* note = malloc(sizeof(struct Note*));
	note->data = malloc(sizeof(char) * 10);

	for (i = 0; i < 10; i++) {
		if (data[i] > 0) {
			note->data[i] = data[i];
		}
	}

	note->next = NULL;


	return note;
}

void GetData(char* data) {

	char t;
	int size = 0;

	t = getchar();
	if (t == '\n')
		t = getchar();

	while (t == ' ') {
		t = getchar();
	}

	while (t != ' ' && t != '\n' && (int)t > 0) {
		size++;
		data[size - 1] = t;
		t = getchar();
	}

}

void PrintData(char* data) {

	int i = 0;

	for (i = 0; i < 10; i++) {
		if ((int)data[i] > 0) {
			printf("%c", data[i]);
		}
		else break;
	}

}

int IsEqual(char* data,char* data2) {

	int i;
	int boo = 1;

	for (i = 0; i < 10; i++) {

		if (data[i] == data2[i] || (data[i] <= 0 && data2[i] <= 0)) {

		}
		else {
			return 0;
		}

	}
	return 1;

}



int CommandType(char Command[10]) {

	int CommandType = -1;

	if (Command[0] == 'c' || Command[0] == 'C')
	{
		if (Command[1] == 'r')
		{
			if (Command[2] == 'e')
			{
				if (Command[3] == 'a') {
					if (Command[4] == 't') {
						if (Command[5] == 'e') {
							CommandType = 0;
						}
					}
				}
			}
		}
	}
	if (Command[0] == 'a' || Command[0] == 'A') {
		if (Command[1] == 'd') {
			if (Command[2] == 'd') {
				CommandType = 1;
			}
		}
	}

	if (Command[0] == 'p' || Command[0] == 'P') {
		if (Command[1] == 'r') {
			if (Command[2] == 'i') {
				if (Command[3] == 'n') {
					if (Command[4] == 't') {
						CommandType = 2;
					}

				}
			}
		}
	}

	if (Command[0] == 'h' || Command[0] == 'H') {
		if (Command[1] == 'e') {
			if (Command[2] == 'l') {
				if (Command[3] == 'p') {
					CommandType = 3;
				}
			}
		}
	}

	if (Command[0] == 'd' || Command[0] == 'D') {
		if (Command[1] == 'e') {
			if (Command[2] == 'l') {
				if (Command[3] == 'e') {
					if (Command[4] == 't') {
						if (Command[5] == 'e') {
							CommandType = 4;
						}
					}
				}
			}
		}
	}
	if (Command[0] == 'u' || Command[0] == 'U') {
		if (Command[1] == 'n') {
			if (Command[2] == 'i') {
				if (Command[3] == 'o') {
					if (Command[4] == 'n') {
						CommandType = 5;
					}
				}
			}
		}
	}
	if (Command[0] == 'i' || Command[0] == 'I') {
		if (Command[1] == 'n') {
			if (Command[2] == 't') {
				if (Command[3] == 'e') {
					if (Command[4] == 'r') {
						CommandType = 6;
					}
				}
			}
		}
	}
	if (Command[0] == 'c' || Command[0] == 'C') {
		if (Command[1] == 'o') {
			if (Command[2] == 'm') {
				if (Command[3] == 'p') {
					if (Command[4] == 'l') {
						CommandType = 7;
					}
				}
			}
		}
	}
	if (Command[0] == 's' || Command[0] == 'S') {
		if (Command[1] == 'y') {
			if (Command[2] == 'm') {
				if (Command[3] == 'm') {
					CommandType = 8;
				}
			}
		}
	}
	if (Command[0] == 's' || Command[0] == 'S') {
		if (Command[1] == 'u') {
			if (Command[2] == 'b') {
				CommandType = 9;
			}
		}
	}
	return CommandType;

}

void CopyName(char* name, char* noteName) {

	int i;
	
	for (i = 0; i < 10; i++) {
		noteName[i] = name[i];
	}


}

struct List* AddToList(struct List* Array,int *size,char *name) {
	
	int i;
	int IsEx = 0;
	struct List* Array_t;

	(*size)++;
	Array_t = malloc(sizeof(struct List) * *size);
	if (!Array_t) {
		printf("Realloc ERROR");
	}
	for (i = 0; i < *size - 1; i++) {
		Array_t[i] = Array[i];
	}
	for (i = 0; i < *size - 1; i++) {
		if (IsEqual(Array[i].name, name)) {
			IsEx = 0;
		}
	}
	if (!IsEx) {
		Array = Array_t;
		Array[*size - 1].First = malloc(sizeof(struct Note*));
		Array[*size - 1].name = malloc(sizeof(char) * 10);
		Array[*size - 1].First = NULL;
		CopyName(name, Array[*size - 1].name);
		return Array;
	}
	else {
		printf("ERROR");
		return 0;
	}

}

struct List* Untion(struct List* Array,int* size) {

	int i, j,IsFound,IsEq = 0;

	char name1[10];
	char name2[10];
	char name3[10];

	struct Note* note = NULL;
	struct Note* notetmp = NULL;

	GetData(name1);
	GetData(name2);
	GetData(name3);

	for (i = 0; i < *size; i++) {
		if (IsEqual(Array[i].name, name1)) {
			for (j = 0; j < *size; j++) {
				if (IsEqual(Array[j].name, name2)) {
					Array = AddToList(Array, size, name3);
					notetmp = Array[i].First;
					Array[*size - 1].First = CreateNote(notetmp->data);
					note = Array[*size - 1].First;
					while (notetmp->next != NULL) {
						note->next = CreateNote(notetmp->next->data);
						note = note->next;
						notetmp = notetmp->next;
					}
					notetmp = Array[j].First;
					note = Array[*size - 1].First;
					while (notetmp != NULL) {
						while (note->next != NULL) {
							if (IsEqual(note->data, notetmp->data)) {
								IsEq = 1;
								break;
							}
							note = note->next;
						}
						if (!IsEq) {
							note->next = CreateNote(notetmp->data);
						}
						note = Array[*size - 1].First;
						notetmp = notetmp->next;
					}
				}
			}
		}
	}

	return Array;
}

struct List* Inter(struct List* Array, int* size) {

	int i, j, IsFound, IsFirst =1 ;

	char name1[10];
	char name2[10];
	char name3[10];

	struct Note* note = NULL;
	struct Note* notetmp = NULL;
	struct Note* notetmp2 = NULL;

	GetData(name1);
	GetData(name2);
	GetData(name3);

	for (i = 0; i < *size; i++) {
		if (IsEqual(Array[i].name, name1)) {
			for (j = 0; j < *size; j++) {
				if (IsEqual(Array[j].name, name2)) {
					Array = AddToList(Array, size, name3);
					while (notetmp != NULL) {
						notetmp = Array[i].First;
						notetmp2 = Array[j].First;
						while (notetmp2 != NULL) {
							if (IsEqual(notetmp, notetmp2)) {
								if (IsFirst) {
									Array[*size - 1].First = CreateNote(notetmp->data);
									note = Array[*size - 1].First;
									IsFirst = 0;
								}
								else {
									note->next = CreateNote(notetmp->data);
									note = note->next;
								}
							}
							notetmp2 = notetmp2->next;
						}
						notetmp = notetmp->next;
					}
				}
			}
		}
	}

	return Array;

}


struct List* Compl(struct List* Array, int* size) {

	int i, j, IsFound, IsFirst = 1;

	char name1[10];
	char name2[10];
	char name3[10];

	struct Note* note = NULL;
	struct Note* notetmp = NULL;
	struct Note* notetmp2 = NULL;

	GetData(name1);
	GetData(name2);
	GetData(name3);

	for (i = 0; i < *size; i++) {
		if (IsEqual(Array[i].name, name1)) {
			for (j = 0; j < *size; j++) {
				if (IsEqual(Array[j].name, name2)) {
					Array = AddToList(Array, size, name3);
					while (notetmp != NULL) {
						notetmp = Array[i].First;
						notetmp2 = Array[j].First;
						while (notetmp2 != NULL) {
							if (!IsEqual(notetmp, notetmp2)) {
								if (IsFirst) {
									Array[*size - 1].First = CreateNote(notetmp->data);
									note = Array[*size - 1].First;
									IsFirst = 0;
								}
								else {
									note->next = CreateNote(notetmp->data);
									note = note->next;
								}
							}
							notetmp2 = notetmp2->next;
						}
						notetmp = notetmp->next;
					}
				}
			}
		}
	}

	return Array;
}


struct List* Sym(struct List* Array, int* size) {

	int i, j, IsFound, IsFirst = 1;

	char name1[10];
	char name2[10];
	char name3[10];

	struct Note* note = NULL;
	struct Note* notetmp = NULL;
	struct Note* notetmp2 = NULL;

	GetData(name1);
	GetData(name2);
	GetData(name3);

	for (i = 0; i < *size; i++) {
		if (IsEqual(Array[i].name, name1)) {
			for (j = 0; j < *size; j++) {
				if (IsEqual(Array[j].name, name2)) {
					Array = AddToList(Array, size, name3);
					while (notetmp != NULL) {
						notetmp = Array[i].First;
						notetmp2 = Array[j].First;
						while (notetmp2 != NULL) {
							if (!IsEqual(notetmp, notetmp2)) {
								if (IsFirst) {
									Array[*size - 1].First = CreateNote(notetmp->data);
									note = Array[*size - 1].First;
									IsFirst = 0;
								}
								else {
									note->next = CreateNote(notetmp->data);
									note = note->next;
								}
							}
							notetmp2 = notetmp2->next;
						}
						notetmp = notetmp->next;
					}
					while (notetmp2 != NULL) {
						notetmp = Array[i].First;
						notetmp2 = Array[j].First;
						while (notetmp != NULL) {
							if (!IsEqual(notetmp, notetmp2)) {
								if (IsFirst) {
									Array[*size - 1].First = CreateNote(notetmp2->data);
									note = Array[*size - 1].First;
									IsFirst = 0;
								}
								else {
									note->next = CreateNote(notetmp2->data);
									note = note->next;
								}
							}
							notetmp = notetmp->next;
						}
						notetmp2 = notetmp2->next;
					}
				}
			}
		}
	}

	return Array;
}

int Sub(struct List* Array,int size) {


	int i, j, IsEq = 1;

	char name1[10];
	char name2[10];

	struct Note* note = NULL;
	struct Note* notetmp = NULL;

	GetData(name1);
	GetData(name2);

	for (i = 0; i < size; i++) {
		if ((Array[i].name == name1 || Array[i].name == name2)) {
			if (j == 0)
				j = i;
			else break;
		}
	}
	note = Array[j].First;
	notetmp = Array[i].First;

	while (notetmp != NULL) {
		while (note != NULL) {
			if (note != notetmp)
				IsEq = 0;
			else IsEq = 1;
			note = note->next;
		}
		if (!IsEq) {
			return 0;
		}
		notetmp = notetmp->next;
	}

	return 1;
}

int main(void) {

	struct List* Array;
	struct List* Array_t;
	struct List* tmp;
	struct Note* note;
	struct Note* notetmp;
	char c;
	char name[10];
	char data[10];
	char Command[10];
	int NumberOfLists = 0;
	int i, j, n;
	int IsFound = 0;
	int IsEx = 0;



	Array = malloc(sizeof(struct List));
	

	c = getchar();
	n = 0;
	while (c != EOF) {


		while (c != EOF && c != ' ' && c != '\n') {
			Command[n] = c;
			c = getchar();
			n++;
		}

		n = 0;

		switch (CommandType(Command))
		{

		case -1: printf("Unknown command\n");
			break;
		case 0://create

			GetData(name);
			Array = AddToList(Array, &NumberOfLists, name);
			break;

		case 1: //add

			GetData(name);
			for (i = 0; i < NumberOfLists; i++) {
				if (IsEqual(Array[i].name, name)) {
					GetData(data);
					IsFound++;
					if (Array[i].First == NULL) {
						Array[i].First = CreateNote(data);
					}
					else {
						note = Array[i].First;
						while (note->next != NULL) {
							note = note->next;
						}
						note->next = CreateNote(data);
					}
				}
			}
			if (!IsFound) {
				printf("Not Found\n");
			}
			else
				printf("Done\n");
			break;

		case 2: //print
			IsFound = 0;
			GetData(name);
			for (i = 0; i < NumberOfLists; i++) {
				if (IsEqual(Array[i].name, name)) {
					IsFound++;	
					PrintData(name);
					printf("= { ");
					if (Array[i].First != NULL) {
						note = Array[i].First;
						PrintData(note->data);
						printf(" ");
						while (note->next != NULL) {
							note = note->next;
							PrintData(note->data);
							printf(" ");
						}
					}
					printf("}\n");
				}

			}
			if (!IsFound) {
				printf("Not Found\n");
			} else 
			printf("Done\n");
			break;

		case 3: //help

			printf("create (Set name) - Creating a new set with name\n");
			printf("add (Set name) (value) - Adds an element to a set\n");
			printf("print (Set name) - Printing set\n");
			printf("delete (Set name) (value, if you want to delete set, do not fill) - Deleting Set/Element\n");
			printf("Union\n");
			printf("Inter\n");
			printf("Compl\n");
			printf("Sym\n");
			printf("Sub\n");

			break;

		case 4: //delete

			if (NumberOfLists > 0) {

				GetData(name);

				c = getchar();
				if(c != '\n'){
					GetData(data);
					for (i = 0; i < NumberOfLists; i++) {
						if (IsEqual(Array[i].name,name)) {
							note = Array[i].First;
							if (IsEqual(data,note->data)) {
								if (note->next != NULL) {
									Array[i].First = note->next;
									//free(note);
									printf("Done\n");
								}
								else {
									Array[i].First = NULL;
									//free(note);
									printf("Done\n");
								}
							}
							else if (note->next != NULL) {
								while (note->next->data != data || note->next->next != NULL) {
									note = note->next;
								}
								if (note->next->data == data) {
									notetmp = note->next;
									note->next = notetmp->next;
									//free(notetmp);
									printf("Done\n");
								}
								else {
									printf("No match\n");
								}
							}
							else {
								printf("No match\n");
							}

						}
					}
				}
				else {
					for (i = 0; i < NumberOfLists; i++) {

						if (IsEqual(Array[i].name, name)) {

							NumberOfLists--;

							if (i == 0) {
								Array_t = Array;
								for (j = 0; j < NumberOfLists; j++) {
									Array_t[j] = Array_t[j + 1];
								}
								Array = Array_t;
							}
							else if (i == NumberOfLists - 1) {

							}
							else {

								Array_t = Array;
								for (j = i - 1; j < NumberOfLists + 1; j++) {
									Array_t[j] = Array_t[j + 1];
								}
								Array = Array_t;
							}

						}

					}
					printf("Done\n");
				}
			}
			else printf("You have no Data\n");
			break;

		case 5:

			Array = Untion(Array, &NumberOfLists);


			break;

		case 6:

			Array = Inter(Array, &NumberOfLists);

			break;

		case 7:


			Array = Compl(Array, &NumberOfLists);

			break;


		case 8:
			Array = Sym(Array, &NumberOfLists);

			break;

		default:

			Sub(Array, NumberOfLists);

			break;
		}

		for (i = 0; i < 10; i++) {
			Command[i] = ' ';
		}

		c = getchar();

		for (i = 0; i < 10; i++) {
			data[i] = NULL;
			name[i] = NULL;
		}

		IsFound = 0;

		while (c == ' ' || c == '\n') {
			c = getchar();
		}


	}




	return 0;

}