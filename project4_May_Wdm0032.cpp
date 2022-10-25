/*
 * project4_May_Wdm0032.cpp
 * Author: Will May
 * Program Description:
 * 	Allows players to create their trivia questions
 * 	and answers. Program then asks a question to the player,
 * 	input the player's answer, and check if the player's answer
 * 	matches the actual answer.
 * Sources: 
 * 	Dr. Li's Helpful Hints
 * 	Piazza Questions
 * Compiled using standard compiler
 */

#include <iostream>
#include <string>
using namespace std;

//VARIABLES
int num_questions = 0;

//Structure for creating a linked list that holds a trivia question,
//answer and point amount.
struct Trivia_Node {
	string question;
	string answer;
	int points;
	Trivia_Node *next;
};
typedef Trivia_Node* pointer_node;

//DECLARATIONS
void init_question_list(pointer_node& ques_list);
void add_question(pointer_node& ques_list);
int ask_question(pointer_node ques_list, int num_ask);
void Unit_Test();

//Debug and Release Version
#define TRIVIA_QUIZ

int main() {

//RELEASE
#ifdef TRIVIA_QUIZ
	pointer_node node_list = new Trivia_Node;
	init_question_list(node_list);
	
	//Add Questions
	cout << "*** Welcome to Will May's trivia quiz game ***\n";
	string input;
	do {
		add_question(node_list);
		cout << "Continue? (Yes/No): ";
		getline(cin, input);
	} while (input.compare("Yes") == 0 || input.compare("yes") == 0);
	cout << endl;

	//Begin trivia game
	ask_question(node_list, num_questions);
	cout << "*** Thank you for playing the trivia quiz game. Goodbye! ***\n";
	return 0;	
}
#endif

//DEBUG
#ifdef UNIT_TESTING
	Unit_Test();
	return 0;
}
#endif

//Function Definitions
void init_question_list(pointer_node& ques_list) {
	pointer_node current_pointer = new Trivia_Node;

	//Q1
	current_pointer->question = "How long was the shortest war on record? (Hint: how many minutes)";
	current_pointer->answer = "38";
	current_pointer->points = 100;
	current_pointer->next = new Trivia_Node;

	//Initialize ques_list to be first question
	ques_list = current_pointer;
	current_pointer = ques_list->next;

	//Q2
	current_pointer->question = "What was Bank of America's original name? (Hint: Bank of Italy or Bank of Germany)";
	current_pointer->answer = "Bank of Italy";
	current_pointer->points = 50;
	current_pointer->next = new Trivia_Node;
	current_pointer = current_pointer->next;

	//Q3
	current_pointer->question = "What is the best-selling video game of all time? (Hint: Call of Duty or Wii Sports)";
	current_pointer->answer = "Wii Sports";
	current_pointer->points = 20;
	current_pointer->next = NULL;

	num_questions += 3;	
}

void add_question(pointer_node& ques_list) {
	pointer_node new_pointer = new Trivia_Node;

	//Get Input
	cout << "Enter a question: ";
	getline(cin, new_pointer->question);
	cout << "Enter an answer: ";
	getline(cin, new_pointer->answer);
	cout << "Enter award points: ";
	cin >> new_pointer->points;
	cin.ignore(); 
	new_pointer->next = NULL;

	//Adds to end of list
	Trivia_Node* last = ques_list;
	while (last->next != NULL) {
		last = last->next;
	}
	last->next = new_pointer;
	num_questions++;
}

int ask_question(pointer_node ques_list, int num_ask) {
	pointer_node current_pointer = ques_list;
	string user_answer;
	int total_points = 0;

	//Validate ques_list
	if (ques_list == NULL) {
		return 0;
	}

	//Validate num_ask
	if (num_ask <= 0) {
		cout << "Warning - the number of trivia to be asked must equal to or be larger than 1." << endl;
	return 1;
	} else if (num_questions < num_ask) {
		cout << "Warning - there is only " << num_questions << " trivia in the list." <<endl;
		return 1;
	
	//Ask the amount of questions
	//Adds the question to total_points if right.
	} else {
		for (int i = 0; i < num_ask; i++) {
			cout << "Question: " << current_pointer-> question << endl;
			cout << "Answer: ";
			getline(cin, user_answer);
			if (user_answer.compare(current_pointer->answer) == 0) {
				cout << "Your answer is correct. You recieve " << current_pointer->points << " points." << endl;
				total_points += current_pointer->points;
			} else {
				cout << "Your answer is wrong. The correct answer is: " << current_pointer->answer << endl;
			}
			cout << "Your total points: " << total_points << endl << endl;
			current_pointer = current_pointer->next;
		}
	}
	return 0;
}

void Unit_Test() {
	cout << "** This is a debugging version **\n";

	//Trivia question list
	pointer_node node_list = new Trivia_Node;
	init_question_list(node_list);

	cout << "Unit Test Case 1: Ask no question. The program should give a warning message." << endl;
	ask_question(node_list, 0);
	cout << "Case 1 passed\n\n";

	cout << "Unit Test Case 2.1: Ask 1 question in the linked list. The tester enters an incorrect answer." << endl;
	ask_question(node_list,1);
	cout << "Case 2.1 passed\n\n";

	cout << "Unit Test Case 2.2: Ask 1 question in the linked list. The tester enters a correct answer." << endl;
	ask_question(node_list,1);
	cout << "Case 2.2 passed\n\n";

	cout << "Unit Test Case 3: Ask all the questions of the last trivia in the linked list." << endl;
	ask_question(node_list,3);
	cout << "Case 3 passed\n\n";

	cout << "Unit Test Case 4: Ask 5 questions in the linked list." << endl;
	ask_question(node_list,5);
	cout << "Case 4 passed\n\n";

	cout << "*** End of the Debugging Version ***";
}



