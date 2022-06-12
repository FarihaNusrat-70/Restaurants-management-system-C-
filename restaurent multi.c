#include<stdio.h>
#include<string.h>
//making struct for food & price...
struct food_price_info{
    char item[20];
    float price;
};
//making struct for order...
struct order_info{
    int order_item;
    int quantity;
    float price_per_item;
};
int main(){
    //declare variables names with array...
    struct food_price_info food_price[10]={"Pasta",240,"Pizza",600,"Chowmein",180,"fried Chicken",300,"Burger",170,"Kacchi Biriyani",210,"Cake",650,"Coca Cola",25,"Ice Cream",140,"Water",20};
    struct order_info order[5];
    float total_price=0;
    float vat;
    int counter,counter1,counter2;
    //item no,item name & it’s prices are shown as menu...
    printf("\n Available Food:\n");
    for(counter=0;counter<10;counter++){
        printf("%d.%s : %.2f/- \n",counter+1,food_price[counter].item,food_price[counter].price);
    }
    //loop will stop when enter 0 & generate cash memo...
    printf("\n Enter 0 to generate cash memo\n");
    printf("Food Serial | Quantity (Use space to separate.)\n");
    for(counter1=0;counter1<5;counter1++){
        printf("\n         ");
        //input order_item ...
        scanf("%d",&order[counter1].order_item);
        if(order[counter1].order_item!=0){
            //input quantity if order_item !=0...
            scanf("%d",&order[counter1].quantity);
            //match order_item with fixed item & calculate price_per_item ...
            for(counter=0;counter<10;counter++){
                if(order[counter1].order_item==counter+1){
                    order[counter1].price_per_item=food_price[counter].price*order[counter1].quantity;
                }
            }
            //total price calculate...
            total_price=total_price+order[counter1].price_per_item;
        }
        //cash memo generate if order_item ==0...
        if(order[counter1].order_item==0){
            printf("                    THE ROCK                     \n");
            printf("      4/2, Sobhanbag, Mirpur Rd, Dhaka 1207.\n");
            printf("      Phone No: 02-9132634; Cell: 01833102806\n");
            printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
            printf("                  CASH MEMO\n");
            printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
            printf("    ITEM NO    | Quantity |    PRICE\n");
            printf("-------------------------------------\n");
            for(counter2=0;counter2<counter1;counter2++){
                //this loop repeat until counter2<counter1...
                printf("       %d       |   x%d    |    %.2f/-\n",order[counter2].order_item,order[counter2].quantity,order[counter2].price_per_item);
            }
            printf("-------------------------------------\n");
            printf("                     TOTAL : %.2f/-\n",total_price);
            vat=total_price*.15;
            printf("                  VAT(15%c) : %.2f/-\n",'%',vat);
            printf("-------------------------------------\n");
            printf("              TOTAL AMOUNT : %.2f/-\n",total_price+vat);
        }
    }
    return 0;
}
