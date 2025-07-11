  #include <stdio.h>
  #include<stdlib.h>

      typedef struct node { // struct of node
           int dt ;
           struct node *nxt;
      }node ;



        void creationfifo( node **head ,int n ){ // first in first out

            printf("linked list fifo :\n");
            node *p ,*q ;
            p = (node * ) malloc(sizeof(node)) ;// create the first node
            scanf("%d",&(p -> dt) );
            *head = p ;
            p -> nxt = NULL;// its a essential in case of one element or one node

                     for (int i = 1; i < n; i++)
                     {
                         q = (node *)malloc ( sizeof(node ));// create the second node "loop"

                         scanf("%d",&(q -> dt) );

                            q -> nxt = NULL;

                            p -> nxt = q ;// link node to next node

                            p = q ;//update p pointer
                    }

        }



        void creationlifo( node **head ,int n ){// last in first out

            printf("linked list lifo :\n");

            node *p ,*q ;
            p = (node * ) malloc(sizeof(node)) ;// create the last node
            scanf("%d",&(p -> dt) );
            *head = p ;
            p -> nxt = NULL;
                     for (int i = 1; i < n; i++)
                     {
                          q = (node *)malloc ( sizeof(node ));//create the precident node

                          scanf("%d",&(q -> dt) );

                              q -> nxt = p;//link to next node
                              *head = q;// update head
                              p = q;// update p pointer
                     }

        }



      void display (node *head){

            if (head == NULL){
                   printf("linked list an empty !!! 👌🏼");

            }

            else{
               printf("\n display all nodes :\n");

                 while (head != NULL){

                    printf("%d\n",head -> dt);
                    head = head -> nxt ;// we use head as pointer such that pass of value, e. change in fonction without main

                 }
            }

      }


      void addbeing(node **head ){
    //
            printf("list addbeing :\n");
            node *p;
            p = (node *)malloc (sizeof(node ));
            scanf("%d",&(p->dt));

                 if(*head == NULL){
                      *head = p;
                      p -> nxt = NULL;
                 }
                    else {

                          p -> nxt = *head ;// link to The first old node
                          *head = p ;// update head
                    }

      }


  void addend(node *head){
  //

      printf("list addend : \n");
         node *q;
            q =(node *)malloc(sizeof(node));

            scanf("%d",&(q-> dt));
            q -> nxt = NULL;

              while(head ->nxt != NULL){
                   head = head -> nxt ;//catch the last node
              }

                      head -> nxt = q;//lint to new node
  }


  void deletebegin(node **head){
  //
           printf("list deletebegin :\n");

       if (*head == NULL){
      printf("list an empty !");
      }
      else {
           node *p = *head;
           *head = (*head) -> nxt ;//head point  to the next
           free(p);

      }
  }


  deleteend(node **head ){
  //
     printf(" list deleteend :\n");
        if(*head == NULL){
              printf("list an empty !");
        }
     else {
        node *p = *head;
        node *pr;
          while(p -> nxt != NULL){
               pr = p;// pr before p
               p = p -> nxt ;// p after pr
          }

        free(p);

             if(pr == NULL){
                 *head = NULL;//one node
             }
             else {
                 pr -> nxt = NULL;// otherwise
             }
     }
  }




  void link (node *head1,node *head2  ){
  //
      printf("link list1 to list2 :\n");
                while(head1 -> nxt != NULL){

                   head1 = head1 -> nxt ;//catch the last node
                   printf(" ");
                }

                     head1 -> nxt = head2;// link with the first node from the list2

  }



  void addpos(node **head1 ,int n ){
    //
         if ( *head1 == NULL){

             printf("list an empty !"); //hi
         }else{


         int pos ;
         printf("enter a position :\n");
         do{
         scanf("%d",&pos);
         }while(pos<=0);

                if ( pos > n +1  ){// update for n
                printf("\nwe can't add because the number of elements are limite !!!\n");
                }
                else {
                node *p,*prc,*q;

                n--;// for execute the first if() we must Return n to its previous value
                       q =(node *)malloc(sizeof(node));// The node to be added
                             printf("enter a number :\n");
                              scanf("%d",&(q -> dt ));
                                p = *head1 ;// update p
                       for(int i = 0 ; i < pos - 1 ;i++){ // pos -1:In order to add before position to insert correct
                              prc = p;
                              p = p -> nxt ;
                       }
                if (pos == n+1 ){// Possible case I see
                            p -> nxt = q ;
                            q -> nxt = NULL ;
                }
                else {
                         if (p == *head1){ // p & head1 are pointe to same node
                                 q -> nxt = *head1; // insert in first place
                                 *head1 = q ; // update head1
                         }
                         else {//otherwise
                                 q -> nxt = p ; // link to next node
                                 prc -> nxt = q ;// link to new node
                         }
                }
                }
         }

  }

  void deletelist(node **head){//any list


            if(head== NULL){
             printf("the list an empty of first ! ");
            }
                                 else{
                                      node *p;

                                      p = *head;
                                      while (p -> nxt != NULL ){
                                             *head = p -> nxt ;// update head every time even satisfies a condition above
                                             free(p);
                                             p = *head;// update p every time even satisfies a condition above
                                             }
                                      free(p);//Delete the last node
                                      *head = NULL;
                                         printf("\nThe list has been deleted successfully.\n");
                                 }
  }








  void deletepos(node **head2, int n) {

          if (*head2 == NULL) {

             printf("The list is empty !");
          } else {
          printf("deletepos :\n");
          int pos;
          printf("enter a position :\n");
          scanf("%d",&pos);
                  if (pos > n) {
                     printf("\nWe can't delete because there is no position!");
                  } else {
                  node *prc, *p, *q;
                           p = *head2;
                           q = p->nxt;
                                for (int i = 0; i <= pos - 2; i++) {
                                        prc = p; // prc before  p
                                        p = p->nxt; // p after prc
                                        q = p->nxt; // q after p
                                }
                                if ((*head2 == p) && (p->nxt == NULL)) {//"n=1 & pos =1"
                                     free(p);
                                     *head2 = NULL;
                                } else {
                                       if (*head2 == p && p->nxt != NULL) {//"n>1 & pos =1"
                                            *head2 = p->nxt;
                                             free(p);
                                       } else {
                                              if ((*head2 == prc) && (p->nxt == NULL)) {//"n>1 & (pos =2 = end )"
                                                  prc->nxt = NULL;
                                                  free(p);
                                              } else {//otherwise
                                                      prc->nxt = q;
                                                      free(p);
                                              }
                                       }
                                }
                           }


                  }

  }




permpos(){

}



crtdouble(){


}

adddouble(){


}
crtcircle(){


}


void tabtotlistposneg6(int tab[],int n) {
      printf("array size 6 to list :\n");

      node *m=NULL,*s=NULL,*h1=NULL;//

          m = (node *)malloc(sizeof(node)); // create the first node
                m->dt = tab[0];// value is: 2
                h1 = m;// update h1 ;
                for (int i = 1; i <= n - 1 ; i++) {
                        s = (node *)malloc(sizeof(node));// create according i
                          s -> dt = tab[i]; //vlaues are : 1 then 0 ,-3,-5,-9
                          m ->nxt = s;// link to next node
                          m = s;// update m

                }
                              m -> nxt = NULL ;// the last node " m == s "
                              s = h1 -> nxt;// update m ,h1 is fixed
                              m = s -> nxt;
                              while(m ->dt != -3){
                                    s = m;
                                    m = m -> nxt ;
                              }

                           s -> nxt = NULL;//m point to the third node & p pointe to the forth node

                          printf("\n list all values array:\n");

                           printf("h2 :\n");
                      while (h1 != NULL){

                         printf("%d\n",h1 -> dt);// Display the values
                            h1= h1 -> nxt ;// move to h1
                      }


                printf("h2 :\n");
                      while (m != NULL){

                         printf("%d\n",m -> dt);// Display the values
                            m = m -> nxt ;// move to m
                      }


  }



   tabtosortlist6(node **head1 ){

   printf("list to  array size 6 :\n");

            int t[] ={0,0,0,0,0,0},i,j,d;
            node *p;
               p = *head1;
               i = 0;
                     while(p != NULL && i<6){
                          t[i] = p -> dt ;//error
                          p = p-> nxt ;
                          i++;
                     }

                       for(i = 0 ;i< 6 ;i++ ){
                           for(j = i + 1; j< 6 ; j++ ){
                               if (t[j] < t[i]){
                                    d = t[i];
                                    t[i] = t[j];
                                    t[j] = d;

                               }
                           }
                       }

               p = *head1;
               i=0 ;
                     while(p != NULL && i<6){
                           p -> dt = t[i];
                           p = p-> nxt ;
                            i++;

                     }


   }





                  tabtolist(node ***htab1){
                      printf("array to list :");
                         int t[6],i;
                            printf(" enter 6 elements of array :\n");
                                  for(i=0;i<6;i++){
                                     printf("\n");
                                     scanf("%d",&t[i]);
                                  }
                            printf(" array contains :\n");
                                 for(i=0;i<6;i++){
                                    printf("\n");
                                    printf("%d",t[i]);
                                 }
                                node *p,*q;
                                       p = (node *)malloc(sizeof(node ));
                                          p -> dt = t[0];
                                         *htab1 = p;
                                       for(i=1;i<6;i++){
                                             q = (node *)malloc(sizeof(node ));
                                               q -> dt = t[i];
                                               p-> nxt = q;
                                               p = q;
                                       }

                                         p -> nxt = NULL;



                  }





  void listtotab(node **htab2){
       printf(" list to array :\n");

            node *p,*q;
            int t[6];
            int i;

               p = (node*)malloc(sizeof(node));
                 scanf("%d",&(p->dt));
                  *htab2 = p;
                     for(i=1;i<6;i++){
                           q = (node*)malloc(sizeof(node));
                             printf("\n");
                             scanf("%d",&(q->dt));
                             p -> nxt = q;
                             p = q ;
                     }


                  p -> nxt = NULL;
                  p = *htab2;
                         for(i=0;i<6;i++){
                            t[i] = p -> dt ;
                              p = p -> nxt ;
                         }

            printf("array contains :");

                 for(i=0;i<6;i++){
                      printf("\n");
                      printf("%d",t[i]);

                 }
  }






  sortasc(node **sort){
     //
     printf("sort Ascending of list :");
        node *p ,*q;
        int t;
          if(*sort == NULL){
            printf("list an empty !");
          }
          else{
          printf("list sort : ");
            p = *sort ;
            q = p -> nxt;
              while ( p != NULL && q != NULL){

                  if((q -> dt) < (p -> dt)   ){
                    t = q -> dt;
                    q -> dt = p -> dt;
                    p -> dt = t ;
                  }

                   q = q -> nxt;

                       if (q == NULL){
                       p = p-> nxt ;
                       q = p-> nxt ;

                  }

              }
        }
     }









int main (){
    node * head1 = NULL,*head2 = NULL ;
    int tab[]={2,1,0,-3,-5,-9} ;
    int n,ch;


             printf("_________________________________welcome_____________________________________");
             printf("\n\n\n\n\n");

             printf(">>> please enter the number of list elements : ");
                do{
                    scanf("%d",&n);

                }while(n<=0);

                printf("\n");
             printf(">>> menu :\n\n");

             printf("1_.    creationfifo :\n2_.    creationlifo\n3_.    displayfifo\n4_.    displaylifo\n");
             printf("5_.    addbeingfifo\n6_.    addendfifo\n7_.    addposfifo\n8_.    deletebeginfifo\n9_.    deleteend\n10_.   deletepos\n");
             printf("11_.   deletelistfifo\n12_.  deletelistlifo\n13_.    linktwolist\n14_.    tabtosortlist\n15_.   listtosorttab\n");
             printf("16_.   tabtolist\n17_.   listtotab\n18_.   sortascendinglist\n19_.   exist\n");
             printf("\n\n");
          do{
             printf("\n>>> please enter a choise : ");
             scanf("%d",&ch);




             switch(ch){

             case 1 :
                   creationfifo(&head1,n); ///
                   break;
             case 2 :
                   creationlifo(&head2,n); ///
                   break;
             case 3 :
                  display(head1); ///
                  break;
             case 4 :
                  display(head2); ///
                  break;
             case 5 :
                  addbeing(&head1); ///
                  break;
             case 6 :
                   addend(head1); ///
                   break;
             case 7:
                    addpos(&head1,n);///
                    break;
             case 8:
                   deletebegin(&head1);///
                   break;
             case 9:
                   deleteend(&head1);///
                   break;
             case 10:
                    deletepos(&head1,n);///
                    break;
             case 11:
                   deletelist(&head1);///
                   break;
             case 12:
                   deletelist(&head2);///
                   break;
             case 13:
                    link(head1,head2);///
                    break;
             case 14:
                     tabtotlistposneg6(tab,n);///
                     break;
             case 15:
                     tabtosortlist6(&head2);//
                     break;
             case 16:
                    tabtolist(&head1);///
                    break;
             case 17:
                    listtotab(&head1);///
                     break;
             case 18:
                     sortasc(&head1);///
                     break;
             case 19:
               printf("Exiting the program.\n");
             break;

             default :
             printf("Invalid choice ,try again !\n");

       }
       }while(ch != 19);








return 0;

}







