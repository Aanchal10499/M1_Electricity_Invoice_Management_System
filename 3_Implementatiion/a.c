#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include"billCal.h"
#include"tarrif.h"
#include"a.h"


struct sinfo {
	char fname[50];
	int roll;
	int rid;
	int cid[10];
	float unit[10];
} st[55];

// Variable to keep track of billings and customer
int i = 0,s=1;
float z;
// Structure to store the customer

void add_custm(char *x,int y, int z){
strcpy(st[i].fname,x);
st[i].roll=y;
st[i].rid=z;
i=i+1;
}

// Function to add the student
void add_cust()
{
    char csname[20];
    int pno, csid;
	printf("Add the Customer Details\n");
	printf("-------------------------\n");
	printf("Enter the Customers Name\n");
	scanf("%s", csname);
	printf("Enter the Number\n");
	scanf("%d", &pno);
	printf("Enter the Id\n");
	scanf("%d", &csid);
	
	add_custm(csname,pno,csid);
}



float cal_bill(int ste, int idj,int idt,int mnt, int unt){
	float bill;
    z=(float)unt;
    st[idj].cid[idt]=mnt;
    bill = calct(ste,z);
    st[idj].unit[idt]=bill;
    return bill;
}

// Function to calculate the electric bill
void find_bill()
{
    int h,ste;
	int x,y,t;
	float s;
	printf("Enter the Id of the Customer\n");
	scanf("%d", &x);
	for (int j = 0; j <= i; j++) {
		if (x == st[j].rid) {
			printf(	"The Customer Details are\n");
			printf("The First name is %s\n",st[j].fname);
			printf("Select\n 1 for maharashtra circle \n 2 for Manipur circle\n");
			scanf("%d",&ste);
			printf("Enter month in Number\n");
			scanf("%d",&y);
			for(int k=0;k<10;k++){
			    if(st[j].cid[k] !=y && st[j].cid[k]==0){
			       
			       t=k;
				   break;

			    }
			}
			printf("Enter units consumed:");
			scanf("%d",&h);
			s = cal_bill(ste,j,t,y,h);
			printf("Your bill is %f rs\n",s);
		}
		break;
	}
}

int find_fin(int id)
{ 
	int t=0;
	for(int v=0;v<=i;v++){
		if(st[i].rid=id){
			t= st[v-1].roll;
		}
	}
	return t;
	
}
// Function to print all the customers
void find_fn()
{
	printf("Customer name                         Number\n");
	for(int w=0;w<=i;w++){
	printf("%s                                       %d\n",st[w].fname,st[w].roll);	

	}
}


// Function to print the monthly bill of specific customer
void tot_s()
{
	int cnid;
	printf("Enter customer Id");
	scanf("%d",&cnid);
	for(int w=0;w<=i;w++){
		if(cnid== st[w].rid){
			printf("Customer name = %s\n",st[w].fname);
			printf("Billing month       Billing Amount\n");
			for(int l=0;l<9 ;l++){
            if(st[w].cid[l]==0){
				break;
			}
			printf("%d         %f rs\n",st[w].cid[l],st[w].unit[l]);
			}
			
		}
	}
}

// Function to delete customer 
void del_s(int m)
{
	int a=m;
	for (int j = 0; j <= i; j++) {
		if (a == st[j].rid) {
			for (int k = j; k < 49; k++)
				st[k] = st[k + 1];
			if(i!=0){
				i--;
			}
		
		}
	}
}

// Function to show tariff slabs 
void up_s()
{
    tariff();
}

// main code
void main()
{
	int choice, count,delId;
	while (s = 1) {
		printf("The Task that you "
			"want to perform\n");
		printf("1. Add new Customer\n");
		printf("2. Calculate electricity bill\n");
		printf("3. List all the customers\n");
		printf("4. Display monthly bills of a specific customer\n");
		printf("5. Delete Customer\n");
		printf("6. To Display tariff slabs and current rates\n");
		printf("7. To Exit\n");
		printf("Enter your choice to find the task\n");
		scanf("%d", &choice);
		switch (choice) {
		case 1:
			add_cust();
			break;
		case 2:
			find_bill();
			break;
		case 3:
			find_fn();
			break;
		case 4:
		     tot_s();
			break;
		case 5:
		 printf("Enter the Customer id to delete");
		 scanf("%d", &delId);
			del_s(delId);
		printf("The Customer is removed Successfully\n");
			break;
		case 6:
			up_s();
			break;
		case 7:
			exit(0);
			break;
		
			
		}
	}
}

