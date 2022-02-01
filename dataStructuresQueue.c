#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 10

/* Abdurrahman Derda Karaaslan - 191180048 */


/* 
The program works with the logic of over again queue up the elements.

If the queue is empty the number given from user added to the queue 

Else if the number given from user is biggest element in the queue added the number to the queue 

Else, the number given from user and all element in the queue are compared  
and the smaller number is added to queue 
this proses is repeat for all element in the queue
when the number that given from user is added, other not compared elements are added after it
*/

typedef struct{
	int value;
}element;
element queue[SIZE];
int front = -1;
int rear = -1;
int choice;
int order; 
int number;
int i;


int main() {
	

	while(1){
		
		system("cls");
		printf("---------OPTIONS---------\n");
		printf("0- Pritn all elements of the queue\n");
		printf("1- Add an element into the queue\n");
		printf("2- Remove element from the queue\n");
		printf("3- Exit\n");
		printf("Select (0-3)? :");
		scanf("%d", &choice);
		
		switch (choice){
		
			case 0:
				if(isEmpty()){
					printf("Queue is empty\n");
				}
				else{
				printQueue();
				}
				getch();
				
			break;
		
			case 1:
				
				if(isFull()){// queue is full
					printf("Queue is full\n");
					getch();
				}
				else{

					printf("Please give me a number to add queue\n");
					scanf("%d", &number);
					int sayi = (rear-front+SIZE)%SIZE;// number of elements in queue
					if(isEmpty()){// if queue is empty (for first insert)
							if(enqueue(number)){
								printf("Insert is successful\n");
							}
							else{
								printf("Insert is not successful\n");
							}
							getch();
					}
					else if(queue[rear].value <= number){// if the number given from user is the largest number in the queue
							if(enqueue(number)){// we added number to end of the queue
								printf("Insert is successful\n");
								getch();
							}
					}
					else{// if the queue is not empty and the number is not largest number
						for(i = 0; i <= sayi; i++){/* for, each element in the queue and +1 
							(because we gonna over again queue up the elements and also we have one more elemet to add the queue)*/
							if(queue[front+1].value < number){// if the number is greater than the element that first order in queue
								enqueue(dequeue());
								/*add the first element in the queue to the end of the queue and delete first element
								So actually we threw first element (the smallest element) in the queue to the end of the queue
								*/
							}
							else if(queue[front+1].value >= number){ // if the element is greater than the number
								if(enqueue(number)){// add the number to queue
									for(i =i; i < sayi; i++){// for the remaining elements
									/*
									we added the number to queue so we dont need to comparison any more. 
									Its mean, for the each remaining elements we can add the first element in the queue 
									to the end of the queue and delete first element
									*/
									enqueue(dequeue());//add the first element to end of the queue and delete first element
									}
									printf("Insert is successful\n");
									getch();
								}

								break;// we added all element to queue so get out of loop which at line 80
							}
						}
							
					}	
				}
					
			break;
			
			case 2:
				if(isEmpty()){
					printf("Queue is empty\n");
					getch();
				}
				else{
					dequeue();
					printf("Delete successful\n");
					getch();
				}
			break;
		
			case 3:	
				exit(0);
			break;
		}
		
	}
	
}


int dequeue(){
	front=(front+1)%SIZE;
	return queue[front].value;
}

int enqueue(int number){
	rear = (rear+1)%SIZE;
	queue[rear].value = number;	
	return 1;
}

void printQueue(){
	order= (front+1)%SIZE;
	printf("[First order]");
	while(1){
		printf(" %d ", queue[order]);
		if(order == rear){
		break;
		}
		order=(order+1)%SIZE;
	}
	printf("[Last order]");

}

int isEmpty(){
	if(front == rear){
		return 1;
	}
	else{
		return 0;
	}

}

int isFull(){
	if(front == (rear +1) % SIZE){// queue is full
	return 1;
	}
	else{
		return 0;
	}

}


