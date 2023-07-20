// working code but need to add to file



#include "prototype.h"
#include<stdlib.h>
#include<stdio.h>
#include <string.h>

long int getFileSize(const char* fileName) {
    FILE* file = fopen(fileName, "rb"); // Open the file in binary read mode

    if (file == NULL) {
        printf("Error opening the file.\n");
        return -1; // Return -1 to indicate an error
    }

    // Seek to the end of the file
    fseek(file, 0, SEEK_END);

    // Get the current position, which is the file size
    long int fileSize = ftell(file);

    // Close the file
    fclose(file);

    return fileSize;
}

void write_data_to_file(user_data_struct *user)
{
        FILE *file = fopen("person_data.txt", "wb"); // "wb" for binary write mode

    if (file == NULL) {
        printf("Error opening the file.\n");
        
    }

    fwrite(&user, sizeof(user_data_struct), 1, file);
    fclose(file);

    printf("Data saved to file successfully.\n");

}

int main(void)
{
user_data_struct *user;
int mem_incriment_count = 2 , numer_of_users = 0;
static char mode;
user =( user_data_struct *) malloc(mem_incriment_count *sizeof(user_data_struct));

while (1)
{
    scanf("%c",&mode);
    switch (mode)
    {
        case 'a':
                {
                    printf("enter the user name \n");
                    scanf("%s",user[numer_of_users].customer_name);
                    printf("enter the email id \n");
                    scanf("%s",user[numer_of_users].email_id);
                    printf("enter the model number \n");
                    scanf("%s",user[numer_of_users].model_num);
                    printf("enter the device id \n");
                    scanf("%hd",&user[numer_of_users].device_id);
                    numer_of_users++;
                    if (numer_of_users == mem_incriment_count)
                    {
                        mem_incriment_count = mem_incriment_count + 2;
                        user = realloc(user,mem_incriment_count *sizeof(user_data_struct));
                    }
                    break;
                }
        case 's':
                {

                    for (int i = 0; i < numer_of_users; i++)
                    {
                        printf("user name is %s \n",user[i].customer_name);
                    }
                    break;
                }
        case 'l':
                {
                    char name[30];
                    printf("enter the user name \n");
                    scanf("%s",name);
                    for (int i = 0; i < numer_of_users; i++)
                    {
                        if (strcmp(user[i].customer_name,name) == 0)
                        {
                            printf("user name is %s \n",user[i].customer_name);
                            printf("email id is %s \n",user[i].email_id);
                            printf("model number is %s \n",user[i].model_num);
                            printf("device id is %d \n",user[i].device_id);
                        }
                    }
                    break;
                }
        case 'd':
                {
                    int devceid;
                    printf("enter the device id that u need to delete");
                    scanf("%d",&devceid);
                    for (int i = 0; i < numer_of_users; i++)
                    {
                        if(user[i].device_id == devceid)
                        {
                            printf(" Deleting the user %s\n",user[i].customer_name);
                            while(i<numer_of_users)
                            {
                                
                                user[i] = user[i+1];
                                i++;
                                numer_of_users--;
                            }
                        }    

                    }  
                    break;
                }
            case 'h':
                {
                    printf("enter the input modes \n a  -to add new user \n s  -to show all user names \n l  -to list usedetails  \n d  -to delete the user \n");
                    
                }      
            case 'e':
                    {
                        break;                        
                    }
        }
            
            
        
}



}