#include<stdio.h>
#include<stdlib.h>//include standard libraries
#define MAX_VERTICES 10000//MAX_VERTICES = 10000
#define MAX_EDGES 3000//MAX_EDGES = 3000
struct P_Queue{
int PersonID;//PersonID corresponds to the unique ID allocated to a single person
int ActionDay;//ActionDay corresponds to the day when action has to be taken on the event
char EventType;//EventType can be either 'T'(Transmit) or 'R'(Recover)
struct P_Queue *next;//link to the next element in the queue
};//priority queue is a queue that holds all the events in order of their priority
struct P_Queue *head = NULL;//head pointer pointing NULL initially
struct I_List{
int PersonID;
struct I_List *next;//link to the next element in the list
};//I_List is a list of IDs of all Infected Persons
struct I_List *I_Head = NULL;//head to the I_List points NULL initially
struct R_List{
int PersonID;
struct R_List *next;//link to the next element in the list
};//R_List is a list of IDs of all Recovered Persons
struct R_List *R_Head = NULL;//head to the R_List points NULL initially
struct node{
int vertex;
struct node* next;
};//node structure
struct Graph {
int NumVertices;//Number of Vertices
struct node **AdjLists;//double pointer to structure 'node'
};
struct node* CreateNode(int v)//function which creates a new node and returns back its pointer
{
struct node* NewNode = malloc(sizeof(struct node));//memory allocation to the node pointed by
NewNode
NewNode->vertex = v;
NewNode->next = NULL;
return NewNode;//returns pointer 'NewNode'
}
struct Graph* CreateGraph(int vertices)//function which creates a graph and returns back its
pointer
{
struct Graph* graph = malloc(sizeof(struct Graph));//memory allocation to the node pointed
by graph
graph->NumVertices = vertices;
graph->AdjLists = malloc(vertices * sizeof(struct node*));
int i;
for(i = 0; i < vertices; i++)
graph->AdjLists[i] = NULL;
return graph;//returns back 'graph'
}
void AddEdge(struct Graph *graph,int s,int d)//function which creates an undirected edge between
given 2 vertices
{
struct node* NewNode = CreateNode(d);//creates a new node with vertex value 'd'
NewNode->next = graph->AdjLists[s];
graph->AdjLists[s] = NewNode;
NewNode = CreateNode(s);//creates a new node with vertex value 's'
NewNode->next = graph->AdjLists[d];
graph->AdjLists[d] = NewNode;
}
void PushToList(int x,int n)//given an ID, this function pushes it to Infected/Recovered List
{
if(n == 0)//pushes it to Infected List
{
struct I_List *temp = (struct I_List*)malloc(sizeof(struct I_List));//memory is

allocated to a node pointed by temp

temp->PersonID = x;//the member of structure is given an ID
temp->next = NULL;//link part points nothing
if(I_Head == NULL)//Infected List is empty
I_Head = temp;//I_Head points the same node as temp does
else//List isn't empty
{
if(x < I_Head->PersonID)
{
temp->next = I_Head;

I_Head = temp;
}

else
{
struct I_List *start = I_Head;
while(start->next != NULL && ((start->next)->PersonID <

x))//traverse until start reaches an appropriate position
start = start->next;
temp->next = start->next;//links being reset so that

start->next = temp;//the temp node is inserted next to node pointed by
start
}

}//here we traverse the list until we find an appropriate position to insert
}
else if(n == 1)//pushes it to Recovered List
{
struct R_List *temp = (struct R_List*)malloc(sizeof(struct R_List));//memory is

allocated to a node pointed by temp

temp->PersonID = x;//the member of structure is given an ID
temp->next = NULL;//link part points nothing
if(R_Head == NULL)//Recovered List is empty
R_Head = temp;//R_Head points the same node as temp does
else//List isn't empty
{
if(x < R_Head->PersonID)
{
temp->next = R_Head;

R_Head = temp;
}

else
{
struct R_List *start = R_Head;
while(start->next != NULL && ((start->next)->PersonID <

x))//traverse until start reaches an appropriate position
start = start->next;
temp->next = start->next;//links being reset so that

start->next = temp;//the temp node is inserted next to node pointed by
start
}

}//here we traverse the list until we find an appropriate position to insert
}
}
void Remove_From_I_List(stored_data)//the function which deletes ID with value 'stored_data' from
the Infected List
{
if(I_Head->PersonID == stored_data)//if the ID which we are looking for,is in head node
I_Head = I_Head->next;//deletes the head node and the next node is made as head node(if
exists)
else
{
struct I_List *temp2 = I_Head,*temp1 = I_Head->next;//temp1 and temp2 are always

made to point 2 immediate nodes
while(1)
{
if(temp1->PersonID == stored_data)//if the ID which we are looking for,is

in node pointed by temp1
{
temp2->next = temp1->next;
break;//exits from while loop
}
temp2 = temp2->next;
temp1 = temp1->next;//shift both pointers by a node
}
}

}
void push(int x,int n,char c)//function which pushes a node with given credentials in the priority
queue
{
struct P_Queue *temp = (struct P_Queue*)malloc(sizeof(struct P_Queue));//memory allocation
to a node pointed by temp
temp->PersonID = x;
temp->ActionDay = n;
temp->EventType = c;
temp->next = NULL;//the details of the node are filled with given credentials
if(head == NULL)//if priority queue is empty
head = temp;//head points the same node as temp does
else//priority queue isn't empty
{
if(n <= head->ActionDay)//the priority is based on 'ActionDay'
{

temp->next = head;
head = temp;//head points the same node as temp does
}

else//the nodes are arranged in ascending order of ActionDay
{
struct P_Queue *start = head;
while(start->next != NULL && ((start->next)->ActionDay < n))//traverse

until start reaches an appropriate position
start = start->next;

temp->next = start->next;//links being reset so that

start->next = temp;//the temp node is inserted next to the node pointed by

start
}//here we traverse the list until we find an appropriate position to insert
}
}
void pop()//the function which removes the element with highest priority in the priority queue
{
if(head==NULL)
return;
head = head->next;
}
int Find_In_P_Queue(int ID)//function which tells whether a node with PersonID as 'ID' exists in
Priority Queue or not
{
struct P_Queue *start = head;//start points the head node
while(start!=NULL)//until end of list
{
if(start->PersonID == ID)
return 1;//exits from while loop and returns back 1 as function value
start = start->next;
}
return 0;//such a node doesn't exist
}
int Find_In_R_List(int ID)//function which tells whether a node with PersonID as 'ID' exists in
Recovered List or not
{
struct R_List *start = R_Head;//start points the head node of Recovered List
while(start!=NULL)//until end of list
{
if(start->PersonID == ID)//such a node already exists
return 1;//exits from while loop and returns back 1 as function value
start = start->next;
}
return 0;//such a node doesn't exist
}
void Infected_List()//prints IDs of all members in Infected List
{
printf("Infected List:\n");
struct I_List *start = I_Head;
while(start!=NULL)//until end of list
{
printf("%d ",start->PersonID);//prints the ID value
start = start->next;//start pointer shifts by a node

}
printf("\n");//cursor moves to the next line
}
void Recovered_List()//prints IDs of all members in Recovered List
{
printf("Recovered List:\n");
struct R_List *start = R_Head;
while(start!=NULL)//until end of list
{
printf("%d ",start->PersonID);//prints the ID value
start = start->next;//start pointer shifts by a node
}
printf("\n");//cursor moves to the next line
}
int main(void)//main function starts here
{
int i,j,k,n,day,EdgeCounter,VertexCounter,LinkedVertex;//necessary variables declaration
srand(time(NULL));
int NumOfVertices = (rand() % MAX_VERTICES) + 1;//Range(NumOfVertices) =
{1,2,.....,MAX_VERTICES}
int MaxNumOfEdges = (rand() % MAX_EDGES) + 1;//Range(MaxNumOfEdges) = {1,2,.....,MAX_EDGES}
printf("Number Of Vertices = %d\n",NumOfVertices);//displays the value of NumOfVertices
printf("Maximum Number Of Edges = %d\n",MaxNumOfEdges);//displays the value of MaxNumOfEdges
struct Graph* graph = CreateGraph(NumOfVertices);//creates a graph with given number of
vertices
for(VertexCounter = 0; VertexCounter < NumOfVertices; VertexCounter++)
{
for(EdgeCounter=0; EdgeCounter < MaxNumOfEdges; EdgeCounter++)//Maximum number of edges for
a vertex = MaxNumOfEdges
{

if(rand()%2==0)
{
LinkedVertex = rand() % NumOfVertices;//Range(LinkedVertex) =

{0,1,....,NumOfVertices-1}
AddEdge(graph, VertexCounter, LinkedVertex);//creates an undirected edge
between IDs (VertexCounter+1) & (LinkedVertex+1)
}
}
}
printf("Enter total number of initially infected persons:");//prompts the user to enter
number of root indices of COVID19
scanf("%d",&n);//scans the value
printf("Enter all those IDs of infected persons:\n");//prompts the user to enter all their
IDs
for(i=1;i<=n;i++)
{
printf("Person %d ID:",i);
scanf("%d",&j);//scans all IDs one by one
push(j,1,'T');//all of them are taken as Day 1 infectants
}//Pushes all of them into the Priority Queue
printf("\n");
for(day=1;day<=300;day++)//this program runs for a maximum of 300 days
{
while(head!=NULL && head->ActionDay == day)
{
if(head->EventType == 'T')//if the event is of type 'T' (Transmit)
{
int stored_data = head->PersonID;//retain the ID of the head node
pop();//pop out the head node
int j = 2,recovery_days = 0;
while(!(j==0 || j==1))
{
j = rand()%10;//recovery happens when a biased coin of

probability 0.2 shows a head

recovery_days++;//the coin is tossed once daily
}//finding number of days to recover
push(stored_data,day + recovery_days,'R');/* The next event for the

node will be a recovery event

and will occur on day(day + recovery_days). So a modifed event is

pushed into priority queue */

PushToList(stored_data,0);//push the ID into Infected List right

now

struct node* temp = graph->AdjLists[stored_data - 1];
while(temp)//until end of list that contains all neighbours

{

i = temp->vertex;

if(Find_In_P_Queue(i+1) == 0 && Find_In_R_List(i+1) ==

0)/*finding whether ID i+1 is in Priority Queue

and Recovery List...it enters in only if it isn't in any of

them */

{
int j = 0,transmission_days = 0;
while(j==0)
{
j = rand()%2;//neighbour gets infected when

an unbiased coin shows a head

transmission_days++;//the coin is tossed

once daily

}
push(i+1,day + transmission_days,'T');/* A transmit

event (that will occur on

day(day + transmission_days) for the person with ID

i+1) is pushed into priority queue */
}
temp = temp->next;//traverse to the next neighbour
}
}
else//if the event is of type 'R' (Recovery)
{
int stored_data = head->PersonID;//retain the ID of the head node
pop();//pop out the head node from the priority queue
Remove_From_I_List(stored_data);//removes the ID from Infected List
PushToList(stored_data,1);//pushes it into the Recovered List
}
}
printf("\nREPORT AT THE END OF DAY %d:\n",day);//daily report is given until end of

pandemic(or for 300 days at max)

Infected_List();//displays all the infected persons(who are not yet recovered) by

the end of that day

Recovered_List();//displays all the recovered persons by the end of that day
if(head == NULL)//when no more infected persons are left
break;//exits from the for loop
}
return 0;//returns 0
}
/* NOTE:
1. INPUT FORMAT: Number of initial infectants and their IDs.
2. OUTPUT FORMAT : Infected List and Recovered List are printed everyday until the end of the
pandemic or for 300 days at
maximum(which ever comes first).*/