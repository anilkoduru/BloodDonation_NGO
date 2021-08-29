#include<stdio.h>
void donors(){
	int n=4,i;
	char donors1[100][100]={"raj","anil","vikram","viraj"};
	for(i=0;i<n;i++){
		printf("%s ",donors1[i]);
	}
	printf("\n");
}
void requestList(){
	int n=4,i;
	char requests[100][100]={"vijay","arjun","nithiin","mahesh"};
	for(i=0;i<n;i++){
		printf("%s ",requests[i]);
	}
	printf("\n");
}
void registration(){
	char name,blood;
	printf("Enter your Name: ");
	scanf("%s",&name);
	printf("Enter your blood group: ");
	scanf("%s",&blood);
}
int main(){
    int n,entry,choice1,choice2,hospital[100];
    printf("Admin=1, User=2");
    printf("\nEnter the type of your entry: ");
    scanf("%d",&entry);
    while(1)
    {
        switch(entry)
    {
        case 1:
        	printf("\nYou have Entered as Admin ");
        	printf("\nEnter 1- for Adding Hospital Names");
        	printf("\nEnter 2- to View List of Donors");
        	printf("\nEnter 3- to Check the Request List\n");
        	printf("\nEnter the choice you want: ");
        	scanf("%d",&choice1);
            {
                switch(choice1)
        	    {
        	        case 1:
        		    	printf("Enter the name of the hospital: ");
        		    	scanf("%s",&hospital);
        			    break;
        		    case 2:
        			    printf("\nList of Donors: ");
        			    donors();
        			    break;
        		    case 3:
        			    printf("\nRequest list: ");
        			    requestList();
        			    break;
                    default:
                        return 0;
			    }
            }
            break;
		case 2:
			printf("\nYou have Entered as User ");
			printf("\n1- for Registration");
			printf("\n2- Requesting Blood");
			printf("\n3- Donate Blood\n");
			printf("\nEnter the choice you want: ");
			scanf("%d",&choice2);
			switch(choice2)
			{
				case 1:
					printf("Make a Registration:\n");
					registration();
					break;
				case 2:
					printf("\nThe Donors are: ");
					donors();
					break;
				case 3:
					printf("\nDonate Blood: ");
					printf("\nAvailable Hospitals: ");
					printf("\nA");
					printf("\nB");
					printf("\nC");
					printf("\nD\n");
					registration();
                default:
                    return 0;
			}
    }
}

}
