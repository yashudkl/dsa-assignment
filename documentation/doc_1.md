### Data Structures Defined

Stack has array implementation with the help of structure. Then it is dynamically alloted in the heap using malloc function

Code for reference: 

1) Line no 4 (For defining stack)
struct stack {
    int size;
    int top;
    char *arr;
};

2) Line no 45 (Initializing stack)
 struct stack *sp = (struct stack *)malloc(sizeof(struct stack));

### Function Implementation

Here are list of functions implemented with their purpose

1) isEmpty <br>
This function checks if stack if empty or not if top is equals to -1 stack is empty.

* Purpose: To check if the stack is empty or not

2) isFull <br>
This function checks if stack is full or not which means if top has value is one less than size then means that the stack is full.

* Purose: To check if the stack if full or not

3) push <br>
This function helps adding an element in stack following FILO principle (First In Last Out).It must satisfy condtion where it is not full.

* Purpose: To add an element in stack if it is not full.

4) pop <br>
This function helps removing an element from stack following FILO principle(First In Last Out).It must satsify conditon where it is not empty.


5) isMatching  <br>
This function compares if poped element matches with the element which is being compared 

* Purpose: To compare popped element and element that is to be compared other wise logic won't work since [,} will also be true

6) parenthesisMatch <br>
This function iterates to character array provided and checks if parenthesis matches or not. It pushes in the stack if it finds any opening parenthesis and pops out if it finds any closing parenthesis There are important condition for paranthesis matching and they are :
* while popping if stack is underflow then it returns false
* after checking all characters if stack is not empty it returns false.

* Purpose: To remove an element from the stack if it not empty.

### Orgranization of main function 

In the main function to keep things simple, function parenthesisMatch is called and if it is true then parenthesis matched is printed and if flase then parenthesis does not match is printed.


## Sample Output

1) Input:<br>
<img src="media/{5F943698-234C-494A-9D96-66527F3800D7}.png" width="400"/>
<img src="media/{8C6C2768-1214-4BB8-BF60-306E1A8AF442}.png" width="400"/>


2) Input:<br>
<img src="media/{BFFD2A22-D721-4088-9967-7C62A911D3E3}.png" width="400"/>
<img src="media/{8B3B78AE-1468-41BC-BFEE-7039DCA35B87}.png" width="400"/>


3) Input: <br>
<img src="media/{DAFAD9C2-4948-4AEE-A300-2040DA214502}.png" width="400"/>
<img src="media/{C7C95CAE-C7CC-486D-B0FC-B410AEA23823}.png" width="400"/>


