
struct userNode{
	
	int id;
	char name[20];
	int age;
	char prog[20];
	int exercise;
	int calorie;	
};

struct userList
{
	struct userNode *data;
	struct userList *link;
};

struct userList *head;
char opt;

