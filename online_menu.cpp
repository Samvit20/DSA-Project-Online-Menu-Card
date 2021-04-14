#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
struct customer{
    int TableNo;
    int amount;
    int dishId[100];
    int quantity[100];
    int dishPrice[100];
    struct customer *next;
};

typedef struct customer node;
node *frt;
node *head;
node *rear;
node *temp;
int f = -1;
int i;
int r = -1;
int price[] ={100,150,100,100,100,200,200,250,200,250,150,200,150,200,150,250,300,250,300,250,50,75,75,75,50,20,20,25,100,75};
string dishes[] ={"Spring Rolls     ","Paneer Chilli Balls","Paneer Tikka        ","Potato Nuggets","Grilled Mushrooms","Veg Fried Rice","Hyd. Veg Biryani","Paneer Kulchas    ","Butter Naan    ","Chole Bhature","Chicken Majestic","Spicy Salami    ","Fish Sticks    ","Mutton Cheese Balls","Chicken Tikka  ","Chicken Fried Rice","Hyd. Dum Biryani","Chilli Fish Rice","Prawns Fried Rice","Non Veg Thali","Gulab Jamun   ","Spl Rasmalai   ","Mousse Cake    ","Choco Lava Cake","Ice Cream      ","Coffee      ","Tea            ","Green Tea      ","Freakshake      ","Hot Chocolate      "};
void enq(){ 
    i=0;
    
    if(r==-1){
        rear = (node*) (malloc(sizeof(node)));
        frt = rear;
        r++;
        f++;
        rear->next = nullptr;
    }
    else{
        rear->next = (node*) (malloc(sizeof(node)));
        rear = rear->next;
        cout<<"HI!";
        rear->next = nullptr;
        r++;
    }
    printf("\nEnter Your Table Number:\n");
    scanf("%d",&rear->TableNo);
    rear->amount = 0;
    int n;
    cout<<"\n";
    do
    {
        printf("\nWhat do you want to do?\n1. Order Dish.\n2. Delete order.\n3.Exit\n");
        scanf("%d",&n);
        cout<<"\n";
        int temp1=0;
        int temp2=0;
        switch(n)
        {       
                case 1:
                printf("\t\t -M E N U-\n");
                int j;
                printf("Which one do you Want to view?\n");
                printf("1. Veg.\n2. Non-Veg.\n3. Desserts\n4. Beverages.\n5. Exit\n");
                scanf("%d",&j);
                switch(j){
                    case 1:
                    int vc;
                    printf("Select option to Proceed.\n");
                    printf("1. Starters.\n2. Main Course.\n3.Exit\n");
                    scanf("%d",&vc);
                    switch(vc){
                        case 1:
                        printf("Select your dish!\n");
                        for(int z =0;z<5;z++){
                            cout<<(z+1)<<". "<<dishes[z]<<"\t\t"<<price[z]<<endl;
                        }
                        break;
                        case 2:
                        printf("Select your dish!\n");
                        for(int z =5;z<10;z++){
                            cout<<(z+1)<<". "<<dishes[z]<<"\t\t"<<price[z]<<endl;
                        }
                        break;
                        case 3:
                        break;
                        default:printf("Wrong Choice!\n");
                        break;
                    }
                    break;
                    case 2:
                    int nc;
                    printf("Select option to Proceed.\n");
                    printf("1. Starters.\n2. Main Course.\n3.Exit\n");
                    scanf("%d",&nc);
                    switch(nc){
                        case 1:
                        printf("Select your dish!\n");
                        for(int z =10;z<15;z++){
                            cout<<(z+1)<<". "<<dishes[z]<<"\t\t"<<price[z]<<endl;
                        }
                        break;
                        case 2:
                        printf("Select your dish!\n");
                        for(int z =15;z<20;z++){
                            cout<<(z+1)<<". "<<dishes[z]<<"\t\t"<<price[z]<<endl;
                        }
                        break;
                        case 3:
                        break;
                        default:
                        printf("Wrong Choice!\n");
                        break;
                    }
                    break;
                    case 3:
                    printf("Select your dessert!\n");
                    for(int z=20;z<25;z++){
                        cout<<(z+1)<<". "<<dishes[z]<<"\t\t"<<price[z]<<endl;
                    }
                    break;
                    
                    case 4:
                    printf("Select your Beverage!\n");
                    for(int z=25;z<30;z++){
                        cout<<(z+1)<<". "<<dishes[z]<<"\t\t"<<price[z]<<endl;
                    }
                    break;
                    
                    case 5:
                    break;
                    default:printf("Wrong Choice!\n");
                    break;
                }
                cout<<"Enter the Dish number you want to order:\n"<<endl;
                int ch;
                scanf("%d",&ch);
                printf("Enter the quantity you want to order:\n");
                scanf("%d",&rear->quantity[i]);
                ch = ch-1;
                rear->dishId[i]=ch;
                rear->dishPrice[i]=price[ch]*(rear->quantity[i]);
                i++;
                for(int p=0;p<i;p++){
                    temp1=temp1+ rear->dishPrice[p];
                }
                rear->amount=temp1 + temp1*0.05;
                break;
                case 2:
                printf("Which order do you want to delete?\n");
                cout<<"S.No "<<"Dish Name     "<<"\t\t"<<"Dish Price"<<"\t\t"<<"Quantity"<<endl;
                for(int k=0;k<i;k++){
                    printf("%d. ",k+1);
                    cout<<dishes[rear->dishId[k]]<<"\t\t"<<price[rear->dishId[k]]<<"\t\t"<<rear->quantity[k]<<endl;
                }
                int del_ch;
                scanf("%d",&del_ch);
                del_ch=del_ch - 1;
                rear->dishId[del_ch]=NULL;
                rear->dishPrice[del_ch]=0;
                for(int p=0;p<i;p++){
                    temp2=temp2+ rear->dishPrice[p];
                }
                rear->amount=temp2+temp2*0.05;
                printf("Order Deleted!\n");
                break;
                case 3: printf("\nExiting.\n");
                break;
                default: printf("\nWrong choice.\n");
        }
    }while(n!=3);

}
void dequeue(){
    if(f>r || r==-1){
        printf("All set!\nNo orders!");
    }
    else{
        
        printf("Enter Table Number:\n");
        int tn;
        scanf("%d",&tn);
        head=frt;
        for(int x=1;x<tn;x++){
            head=head->next;
        }
        printf("\nWhat do you want to do?\n1. Order Dish.\n2. Delete order.\n3. Get order details.\n4.Exit\n");
        int n;
        scanf("%d",&n);
        cout<<"\n";
        int temp1=0;
        int temp2=0;
        switch(n)
        {       
                case 1:
                int j;
                for(j=0;j<10;j++){
                    cout<<(j+1)<<". "<<dishes[j]<<"\t\t"<<price[j]<<endl;
                }
                cout<<"Enter the Dish number you want to order:\n"<<endl;
                int ch;
                scanf("%d",&ch);
                printf("Enter the quantity you want to order:\n");
                scanf("%d",&rear->quantity[i]);
                ch = ch-1;
                head->dishId[i]=ch;
                head->dishPrice[i]=price[ch]*(rear->quantity[i]);
                i++;
                for(int p=0;p<i;p++){
                    temp1=temp1+ head->dishPrice[p];
                }
                head->amount=temp1 + temp1*0.05;
                break;
                case 2:
                printf("Which order do you want to delete?\n");
                cout<<"S.No "<<"Dish Name   "<<"\t\t"<<"Dish Price     "<<"\t\t"<<"Quantity"<<endl;
                for(int k=0;k<i;k++){
                    printf("%d. ",k+1);
                    cout<<dishes[head->dishId[k]]<<"\t\t"<<price[head->dishId[k]]<<"\t\t"<<rear->quantity[k]<<endl;
                }
                int del_ch;
                scanf("%d",&del_ch);
                del_ch=del_ch - 1;
                head->dishId[del_ch]=NULL;
                head->dishPrice[del_ch]=0;
                for(int p=0;p<i;p++){
                    temp2=temp2+ head->dishPrice[p];
                }
                head->amount=temp2+temp2*0.05;
                printf("Order Deleted!\n");
                break;
                case 3:
                printf("Order for Table Number- %d\n",head->TableNo);
                printf("Total amount including GST- %d\n",head->amount);
                case 4: printf("\nExiting.\n");
                break;
                default: printf("\nWrong choice.\n");
        }
    }
}
int main()
{
    int n;
    do
    {
        printf("Enter choice to proceed :\n1. New customer.\n2. Edit customer's order.\n3.Exit.\n");
        scanf("%d",&n);
        switch(n)
        {
            case 1: enq();
            break;
            case 2: dequeue();
            break;
            case 3: printf("\nTHANK YOU!\nExiting program.");
            break;
            default: printf("\nWrong choice.\n");
        }
    }while(n!=3);
    return 0;
}

