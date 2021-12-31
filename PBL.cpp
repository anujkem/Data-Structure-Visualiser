#include<iostream>
#include<stdlib.h>
#include<conio.h>
#include<time.h>
#include<iomanip>

using namespace std;



//-------------------------------------------------------Array Functions-------------------------------------------------------------//


int a[100], arrayPos, elem;
int n = 0;


void arrayCreate();
void arrayDisplay();
void arrayInsert();
void arraydDelete();


void arrayDisplay()
{
    if(!n)
    {
      cout<<"\n Array is Empty....\n\n";
      return;
    }

    clock_t tStart = clock();
    
    cout<<"\n Current Array is : \n";
    cout<<"\n\n\t--------------------------------------------------------------------------------------------------------------------------";
    cout<<"\n\n\t  ";
    
    for(int i = 0 ; i < n - 1 ; i++)
    {
        cout<<"［"<<a[i]<<"］--";
    }
    
    cout<<"［"<<a[n-1]<<"］";
    
    cout<<"\n\n\t--------------------------------------------------------------------------------------------------------------------------";
    cout<<"\n\n\n\n";

    printf(" Time taken for Traversal : %.7fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    
}



void arrayCreate()
{
    
    cout<<"\n Enter the number of elements in array : ";
    cin>>n;
    cout<<"\n Enter the elements : \n\n";
    
    clock_t tStart = clock();
            
    for(int i=0; i<n; i++)
     {
        cout<<"\n Enter element "<< i + 1 <<" : ";
        cin>>a[i];
     }
     
    cout<<"\n\n";
    
    printf(" Time taken in Creation of Array : %.7fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    
    cout<<"\n";
    arrayDisplay();

}



void arrayInsert()
{
    if(n == 100)
    {
        cout<<"\n Size Allocated to array is Array is Full ....\n\n";
        return;
    }

    cout<<"\n Enter position where you want to insert element : ";
    cin>>arrayPos;

    if(arrayPos > n)
    {
        cout<<"In Invalid Position....";
        return;
    }

    cout<<"\n\n Enter the value to be inserted : ";
    cin>>elem;
    
    clock_t tStart = clock();

     for(int i=n-1; i>=arrayPos ; i--)
     {
        a[i+1] = a[i];
     }

    a[arrayPos] = elem;
    n = n+1;
    
    cout<<"\n Element Inserted Successfully !!!";
    cout<<"\n\n";
    printf(" Time taken in Insertion : %.7fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
  
  
    cout<<"\n";
    arrayDisplay();

}



void arrayDelete()
{
   if(n == 0)
   {
       cout<<"\n Array is Empty.... Element can not be Deleted.\n\n";
       return;
   }
  
     cout<<"\n Enter a valid position to delete an Element from Array : ";
     cin>>arrayPos;

     if(arrayPos>n)
     {
         cout<<"\n Given Position is Invalid...Element can not be deleted. ";
         return;
     }
     
     cout<<"\n Element Deleted Successfully !!!";
     cout<<"\n Deleted Element is : "<<a[arrayPos];

     clock_t tStart = clock();

     for( int i = arrayPos; i< n-1; i++)
     {
        a[i] = a[i + 1];
     }

     n = n-1;
     
     cout<<"\n\n";
     printf(" Time taken in Deleting : %.7fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
     cout<<"\n";

     arrayDisplay();
   

} 

//----------------------------------------------------Linked List Functions----------------------------------------------------------//


//Linked List Structure;


struct node
{
  int d;
  node*next;
};

node* head;
node* temp;



//Linked List Traversal/ Display;



void traversal(struct node*ptr)
{   
    bool flag = true;
    
    clock_t tStart = clock();
    
    if(!ptr)
    {
        cout<<"\n Linked list is Empty.....";
    }
    else
    {
    cout<<"\n\n │ Current Linked List │\n\n\n";
    cout<<"\t------------------------------------------------------------------------------------------------------------------------------";
    cout<<"\n\n\n\t";
    
    while(ptr!=NULL)
    {
        if(ptr->next)
        {
            if(flag)
            {
             
              cout<<"Head --->〔 "<<ptr->d<<"|● 〕"<<"--->";
            }
            else
            {
              cout<<"〔 "<<ptr->d<<"|● 〕"<<"--->";
            }
        }
        else
        {
            cout<<"〔 "<<ptr->d<<"|● 〕---> NULL";
        }
        
        flag = false;
        ptr=ptr->next;
    }
    
    cout<<"\n\n\n\n\t------------------------------------------------------------------------------------------------------------------------------";
    cout<<"\n\n";
    
    printf(" Time taken for Traversal : %.7fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    }
}




//Linked List Insertion;


void insertion(int i)
{   
    clock_t tStart = clock();
    
    node* newnode;
    newnode=new node();
    cout<<"\n Enter Node Element "<<i<<" : ";
    cin>>newnode->d;
    newnode->next=NULL;
    if(head==NULL)
    head=temp=newnode;
    else
    {
        temp->next=newnode;
        temp=newnode;
    }
    
    cout<<"\n";
    printf(" Time taken for Insertion : %.7fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
    
    
}


//Delete Element From Linked List;

void deletion()
{
       clock_t tStart = clock();
       
       if(head==NULL)
       {
         cout<<"\n List is empty....";
       }
       else
       {
         temp=head;
         head=head->next;
         cout<<"\n Node "<<temp->d<<" deleted from list...";
         free(temp);
       
       cout<<"\n";
       printf(" Time taken for Deletion : %.7fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
       
       }
       
       cout<<"\n";
       
       traversal(head);
       
}



//Search an Element in Linked list;



int  search()
{       
        clock_t tStart = clock();
        
        int element;
        cout<<"\n Enter Node to be searched in List : ";
        cin>>element;
        temp=head;
        int count=0;
        while(temp!=0)
        {
                count++;
                
                if(temp->d==element)
                {
                   cout<<"\n Entered Node is Found at position | "<<count<<" |";
                   printf(" \n\n Time taken in Seaching: %.7fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
                   return count;
                }
                
                temp=temp->next;
        }
        return -1;
        
        cout<<"\n";

}


//---------------------------------------------------------Stack Functions---------------------------------------------------------//


//Stack Structure ::

struct lobe 
{
   int g;
   lobe *link;
};


lobe* top = NULL;


//Traversal of Stack : Warning : Do not play with this function.......


void display() 
{
   clock_t tStart = clock();  
   
   bool flag = true;
    
   lobe* ptr;
   
   if(top==NULL)
   {
     cout<<"\n Current Stack is empty....";
   }
   else 
   {
      ptr = top;
      cout<<"\n | : Current Stack : |  \n\n\n";
      
      
      while (ptr != NULL) 
      {
         
         if(flag)
         {
            cout<<"\tTop ----> |-----|\n";
            cout<<"\t\t  |  "<< ptr->g <<"  |\n"; 
         }
         else
         {
           cout<<"\t\t  |  "<< ptr->g <<"  |\n";
         }
         
         if(ptr->link)
         {
             cout<<"\t\t  |-----|\n";
         }
         else
         {
             cout<<"\t\t  |-----| ----> Next Null \n";
         }

         ptr = ptr->link;
         flag = false;
      }
      
      
   }
   
   cout<<"\n\n\n";
   printf(" Time Taken in Traversal : %.7fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
   
}



//Push To stack;


void push(int val)
{  
   clock_t tStart = clock();

   lobe* newnode;
   newnode=new lobe();
   newnode->g = val;
   newnode->link = top;
   top = newnode;
   
   cout<<"\n";
   
   printf(" Time taken in Inserting : %.7fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
   
   cout<<"\n\n";
   
   display();
   
}



//Delete Element from Stack;


void pop() 
{
   clock_t tStart = clock();    
    
   if(top==NULL)
   {
      cout<<"\n Stack Underflow : No Element is Present in Stack...."<<endl;
   } 
   else 
   {
      cout<<"\n Popped element is : ";
      cout<<"\t|-----|\n";
      cout<<"\t\t\t|  "<<top->g<<"  |\n";
      cout<<"\t\t\t|-----|";
      cout<<"\n\n";
      top = top->link;
      
      printf("\n Time taken in Deleting : %.7fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
   }
   
  
   cout<<"\n\n";
   
   display();
   
}





//---------------------------------------------------------Main Function--------------------------------------------------------//





int main()
{  
    
    int choice,ch,a,c;
    head = NULL;
    
    
do
{
    cout<<"\n\t\t\t\t\t   ||-----------------------------------------------||";
    cout<<"\n\t\t\t\t\t   ||      Welcome To Data Structure Visualizer     ||";
    cout<<"\n\t\t\t\t\t   ||-----------------------------------------------||";
    
    cout<<"\n\n\n\n Choose a Data Structure To perform Operations :";
    cout<<"\n\n 1. Stack  \n 2. Linked List \n 3. Array \n 4. Queue (X) \n 5. Tree (X) \n";
    cout<<"\n\n Enter your choice : ";
    
    cin>>choice;

 switch(choice)
 {
     //Stack
     
      case 1: cout << "\033[2J\033[1;1H";
          
          do 
           { cout << "\033[2J\033[1;1H";
           
             cout<<"\n\t\t\t\t\t   ||-----------------------------------------------||";
             cout<<"\n\t\t\t\t\t   ||           Stack Data Structure Menu           ||";
             cout<<"\n\t\t\t\t\t   ||-----------------------------------------------||";
             
             cout<<"\n\n\n Operations ::\n";
             cout<<"\n 1 : Push \n 2 : Pop \n 3 : Display \n 4 : Go to Main Menu \n"<<endl;
             cout<<"\n Enter your choice of Operation : ";
             
             cin>>ch;
             
             if(ch == 4)
               break;
             
                 switch(ch) 
                 {
                 case 1:
                        cout << "\033[2J\033[1;1H";
                        int val,m;
                        cout<<"\n Enter no of values to be pushed into Stack : ";
                        cin>>m;
                        for(int i=0;i<m;i++)
                        { 
                          cout<<"\n Enter value "<<i + 1<<" : ";
                          cin>>val;
                          push(val);
                          cout<<"\n";
                        }
                        display();
                        break;
         
                 case 2:
                        cout << "\033[2J\033[1;1H";
                        pop();
                        break;
         
                 case 3: 
                        cout << "\033[2J\033[1;1H";
                        display();
                        break;
         
                 default: cout<<"\nInvalid Choice of Operation.....";
                 }
             
             cout<<"\n\n\n|------------------------------------------------------------------|";
             cout<<"\n\n 1 : To Go To Stack Menu";
             cout<<"\n 2 : Go Back To Main Menu ";
             cout<<"\n\n Enter your Choice : ";
             cin>>c;
        
            }while(c==1);
                 
       cout << "\033[2J\033[1;1H";     
       break;
       
       
       
       //Linked List
       
       case 2: cout << "\033[2J\033[1;1H";
       
             do
            {
              cout << "\033[2J\033[1;1H";
              cout<<"\n\t\t\t\t\t   ||-----------------------------------------------||";
              cout<<"\n\t\t\t\t\t   ||       Linked List Data Structure Menu         ||";
              cout<<"\n\t\t\t\t\t   ||-----------------------------------------------||";
              
              cout<<"\n\n\n Operations ::\n";
              cout<<"\n 1. Display \n 2. Insertion \n 3. Deletion \n 4. Searching \n 5. Go to Main Menu \n";
              cout<<"\n\n Enter your choice of Operation : ";
              cin>>ch;
              
              if(ch == 5)
               break;
               
              switch(ch)
              {
                case 1: 
                        cout << "\033[2J\033[1;1H";
                        traversal(head);
                        break;
                case 2: 
                        cout << "\033[2J\033[1;1H";
                        cout<<"\n Enter no. of elements to be inserted in the list : ";
                        cin>>a;   
                        for(int i = 0; i < a; i++)
                        insertion(i + 1);
                        traversal(head);
                        break;
                case 3: 
                        cout << "\033[2J\033[1;1H";
                        deletion();
                        break;
                case 4: 
                        cout << "\033[2J\033[1;1H";
                        int pos;
                        pos = search();
                        if(pos==-1)
                        cout<<"\n Entered Node not found in Current Linked List...";
                        break;
                default: cout<<" Invalid choice.......";
                }
                
         cout<<"\n\n\n|------------------------------------------------------------------|";
         cout<<"\n\n 1 : To Go To Linked List Menu";
         cout<<"\n 2 : Go Back To Main Menu ";
         cout<<"\n\n Enter your Choice : ";
         cin>>c;
         
         }while(c==1);
         
    cout << "\033[2J\033[1;1H";      
    break;
    
    
    //Array
    
    case 3: cout << "\033[2J\033[1;1H";
           
            do
            {
              cout << "\033[2J\033[1;1H";
              cout<<"\n\t\t\t\t\t   ||-----------------------------------------------||";
              cout<<"\n\t\t\t\t\t   ||            Array Data Structure Menu          ||";
              cout<<"\n\t\t\t\t\t   ||-----------------------------------------------||";
              
              cout<<"\n\n\n Operations ::\n";
              cout<<"\n 1. Create new Array \n 2. Display \n 3. Insert \n 4. Delete \n 5. Go to Main Menu \n";
              cout<<"\n\n Enter your choice of Operation : ";
              cin>>ch;
              
              if(ch == 5)
               break;
              
              switch(ch)
              {
                case 1: 
                        cout << "\033[2J\033[1;1H";
                        arrayCreate();
                        break;
                        
                case 2:
                        cout << "\033[2J\033[1;1H";
                        arrayDisplay();
                        break;
                
                case 3:
                        cout << "\033[2J\033[1;1H";
                        arrayInsert();
                        break;
                
                case 4:
                        cout << "\033[2J\033[1;1H";
                        arrayDelete();
                        break;
                
                default: cout<<"\n Wrong Choice !!!";
                
              }
              
             
            cout<<"\n\n\n|------------------------------------------------------------------|";
            cout<<"\n\n 1 : To Do To Array Menu";
            cout<<"\n 2 : To Go Back To Main Menu ";
            cout<<"\n\n Enter your Choice : ";
            cin>>c;
              
            }while(c==1);
            
        cout << "\033[2J\033[1;1H";      
        break;
        
    case 4: cout << "\033[2J\033[1;1H"; 
            cout<<"\n Ruko Zara Sabar Karo......\n\n Nahin Bana ye function abhi....\n Cross Nai Dikha....\n\n Le Exit Ho tu ab yahan se......";
            exit(1);
            break;
        
    case 5: cout << "\033[2J\033[1;1H"; 
            cout<<"\n Ruko Zara Sabar Karo......\n\n Nahin Bana ye function abhi....\n Cross Nai Dikha....\n\n Le Exit Ho tu ab yahan se......";
            exit(1);
            break;
            
    //Exit
    
    case 6: cout << "\033[2J\033[1;1H";  
            cout<<"\n\t\t\t\t\t   ||-----------------------------------------------||";
            cout<<"\n\t\t\t\t\t   ||    Thanks for Using.......     Bye Bye....    ||";
            cout<<"\n\t\t\t\t\t   ||-----------------------------------------------||";
            exit(0);
              
    default : cout<<"Invalid choice";
              cout << "\033[2J\033[1;1H";  
 }
 
}while(choice!=6);


    return 0;
}





