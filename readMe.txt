This C program implements the bucket sorting algorithm on 8 linked lists 
of nodes in order to organize their string contents into alphabetical order.


struct Bucket:  defines the structure for the Bucket structure. Each Bucket structure
		is composed of an (int) minInitial, an (int) maxInitial, an (int) numWords,
		and a struct Node pointer to the particular Bucket's head Node. Each Bucket's
		minInitial/maxInitial are initialized by the following ASCII values which 
		will then be used to allocate words beginning with certain letters into their
		corresponding buckets. The actual ASCII codes used used to initialize the 
		list of buckets are shown here below.


struct Bucket [8] {
	struct Bucket{	(int)97, (int)98, (int)0, (struct Node *)0}, 
	struct Bucket{	(int)99, (int)99, (int)0, (struct Node *)0}, 
	struct Bucket{	(int)100, (int)102, (int)0, (struct Node *)0}, 
	struct Bucket{	(int)103, (int)107, (int)0, (struct Node *)0}, 
	struct Bucket{	(int)108, (int)111, (int)0, (struct Node *)0}, 
	struct Bucket{	(int)112, (int)114, (int)0, (struct Node *)0}, 
	struct Bucket{	(int)115, (int)115, (int)0, (struct Node *)0}, 
	struct Bucket{	(int)116, (int)122, (int)0, (struct Node *)0}
}


main.c -[Algorithm]:	The bucket sort algorithm is implemented in the main method. The 
			inner-workings of the algorithm are as follows: Once the main method
			begins, a counter integer [i] and a char array [word] are declared.
			The program then enters a while loop that the user will loop through 
			for each string input(unless they enter 'stop', which at this point 
			simply terminate the program). For every other string input made by 
			the user, the program will loop through the array list of buckets 
			until the first character of the input string matches a particular 
			bucket's ASCII character range. Once the match is found, a pointer
			to a new Node is declared and memory is allocated for both that new
			Node and the string value the Node will hold. The new Node's string 
			value is then assigned with the value of the current input string 
			using the strcpy() function and the new Node's next-pointer is 
			initialized to NULL. Then begin the if/else statements for proper 
			placement of this newly created Node amongst the alread-existing 
			Nodes(if any). The nodes are placed in position using Insert sort.
			The placement of a particular Node is based on the alphabetical 
			comparison between that Node's string and the strings in the other 
			existing nodes. If a new Node belongs in a particular bucket but 
			the bucket happens to be empty, then that new Node will	become the 
			bucket's head Node. If a bucket already has a head Node, then the 
			algorithm will compare the new Node's strings with that of every 
			Node until it finds where the string fits alphabetially. When
			the algorithm finds the correct place for that new Node, it will 
			readjust the relevant pointers in order to ensure the proper flow 
			from node to node. Once the algorithm finishes placing a Node in 
			a particular bucket's LinkedList, then the program loops back to 
			prompt the user for a new input string. Every time the while-loop 
			executes, a Node with that string input gets stored into one of the 
			8 bucket's linked lists. The only way out of the loop is when the 
			user enters 'stop'. Upon entering 'stop', the program exits that 
			input while loop and subsequently executes the nested for/while 
			loop at the bottom of the main method. Together, these for/while
			loops iterate through the nodes in each bucket, printing out their
			string values in alphabetical order.
 
